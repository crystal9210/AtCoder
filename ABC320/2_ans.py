s = input()
length = 1
for i in range(len(s)):
    for j in range(i+1,len(s)+1):
        if s[i:j] == s[i:j][::-1]:
            length = max(length,len(s[i:j]))
print(length)