// this is the code I reffered to from SSRS for learning purposes.
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;  // これ素数らしい
int main(){
  int N, X;
  cin >> N >> X;
  vector<int> T(N);
  for (int i = 0; i < N; i++){
    cin >> T[i];
  }
  vector<long long> inv(N + 1); // 逆元を格納するためのベクター
  inv[1] = 1;
  for (int i = 2; i <= N; i++){
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<long long> dp(X + 1, 0); // dp：動的計画法のための配列
  dp[0] = 1;
  long long ans = 0;
  for (int i = 0; i <= X; i++){
    for (int j = 0; j < N; j++){
      if (i + T[j] <= X){
        dp[i + T[j]] += dp[i] * inv[N];
        dp[i + T[j]] %= MOD;
      } else if (j == 0){
        ans += dp[i] * inv[N];
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}
