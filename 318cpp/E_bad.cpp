#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int k = N - 1; k > i; k--) {
            if (A[i] == A[k]) {
                for(int j=i+1;j<k;j++){
                  if(A[j]!=A[i]){
                    sum++;
                  }
                }
                break;  // A[i]に対応するA[k]を1つ見つけたらループを抜ける
            }
        }
    }

    cout << sum << endl;
    return 0;
}
