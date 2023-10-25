#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 部分和問題
// 問:n個の整数と正の整数aがある。これらの整数から何個かの整数を選んで総和がaになるようにすることが可能か判定せよ。可能ならば'YES'、不可能なら'NO'と出力せよ。

int main(){
  int n,a;
  cin>>n>>a;
  vector<int> num(n,0);
  rep(i,0,n)cin>>num[i];
  vector<vector<bool>> dp(n,vector<bool>(a+1,false));
  dp[0][0]=true;

  // メインの実装部分;前述のdp[0][0]=trueから、i番目の数字が
  rep(i,0,n)rep(j,0,a+1){
    // i番目まででそれらの合計がjとなるならi+1番目の数字を加えないことでi+1番目の数字の走査においてもその数字が実現可能(true)
    dp[i+1][j]= dp[i+1][j] || dp[i][j];
    // j>=num[i] i.e. i回目の走査において、合計jがnum[i]より大きい場合、i+1回目が、①i回目のdp[i][j](i回目の走査時の合計jが実現可能かどうかのbool値)または②i回目の合計がj-num[i]の場合が実現可能かどうか、の2つのbool値のいずれかがtrueならtrueとなる
    if(j>=num[i])dp[i+1][j]= dp[i+1][j] || dp[i][j-num[i]];
  }
  if (dp[n][a]) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;

}
