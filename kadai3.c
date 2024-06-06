#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define BUFFER_SIZE 128
#define KEY_SIZE 32
#define IV_SIZE 16

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt_data(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt_data(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    int ret;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    printf("now is decrypting....\n");

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    if(ret > 0) {
        plaintext_len += len;
        plaintext[plaintext_len] = '\0';
    } else {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }

    EVP_CIPHER_CTX_free(ctx);
    return 1;
}

int main() {
    int fd1[2], fd2[2];
    pid_t pid;

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (attacker)
        printf("Attacker process %d started\n", getpid());
        close(fd1[1]);
        close(fd2[0]);

        unsigned char key[KEY_SIZE];
        unsigned char iv[IV_SIZE];
        unsigned char ciphertext[BUFFER_SIZE];
        unsigned char decryptedtext[BUFFER_SIZE];
        int ciphertext_len;

        read(fd1[0], key, KEY_SIZE);
        read(fd1[0], iv, IV_SIZE);
        read(fd1[0], &ciphertext_len, sizeof(int));
        read(fd1[0], ciphertext, ciphertext_len);

        // Use wrong key for decryption
        unsigned char wrong_key[KEY_SIZE];
        if (!RAND_bytes(wrong_key, sizeof(wrong_key))) {
            handleErrors();
        }

        if (decrypt_data(ciphertext, ciphertext_len, wrong_key, iv, decryptedtext)) {
            printf("Attacker process %d successfully decrypted: %s\n", getpid(), decryptedtext);
        } else {
            printf("Attacker process %d failed to decrypt with the wrong key.\n", getpid());
        }

        close(fd1[0]);
        close(fd2[1]);
        printf("Attacker process %d finished\n", getpid());
        exit(0);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (legitimate)
        printf("Legitimate process %d started\n", getpid());
        close(fd1[1]);
        close(fd2[0]);

        unsigned char key[KEY_SIZE];
        unsigned char iv[IV_SIZE];
        unsigned char plaintext[] = "picoCTF{this_is_a_sample_flag}";
        unsigned char ciphertext[BUFFER_SIZE];
        int ciphertext_len;

        read(fd1[0], key, KEY_SIZE);
        read(fd1[0], iv, IV_SIZE);

        ciphertext_len = encrypt_data(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

        write(fd2[1], &ciphertext_len, sizeof(int));
        write(fd2[1], ciphertext, ciphertext_len);

        close(fd1[0]);
        close(fd2[1]);
        printf("Legitimate process %d finished\n", getpid());
        exit(0);
    }

    // Parent process
    printf("Parent process %d started\n", getpid());
    close(fd1[0]);
    close(fd2[1]);

    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];
    int ciphertext_len;

    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        handleErrors();
    }

    write(fd1[1], key, KEY_SIZE);
    write(fd1[1], iv, IV_SIZE);

    close(fd1[1]);  // Ensure EOF is sent to child processes

    read(fd2[0], &ciphertext_len, sizeof(int));
    read(fd2[0], ciphertext, ciphertext_len);

    if (decrypt_data(ciphertext, ciphertext_len, key, iv, decryptedtext)) {
        printf("Parent process %d successfully decrypted: %s\n", getpid(), decryptedtext);
    } else {
        printf("Parent process %d failed to decrypt.\n", getpid());
    }

    close(fd2[0]);
    wait(NULL);
    wait(NULL);
    printf("Parent process %d finished\n", getpid());

    return 0;
}
