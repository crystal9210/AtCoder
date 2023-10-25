#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 問:n個の品物があり、i番目の品物の重さと価値をそれぞれw[i],v[i]とする。このとき、これらの品物の重さの総和がmaxを越えないように選んだ時の価値の総和の最大値を求めよ
// 方針:DP(動的計画法);

int main(){
  int n,max_w;
  cin>>n>>max_w;
  vector<int> w(n,0),v(n,0);
  vector<vector<ll>> dp(n,vector<ll>(max_w+1,0));
  rep(i,0,n)cin>>v[i]>>w[i];  // 多くの場合、ここの入力順は問題文で指定される

  // dpループ;外側は各品物ごとに走査し、それら走査したまでの品物群に対しそれらのうち選んだ組み合わせに対する総和に相当する重さに対する価値の最大値を内側のループで保持するために実装している
  rep(i,0,n){
    rep(j,0,max_w+1){
      if(j>=w[i])dp[i+1][j]=max(dp[i][j-w[i]]+v[i],dp[i][j]);
      else dp[i+1][j]=dp[i][j];
    }
  }
  cout<<dp[n][max_w]<<endl;

  return 0;
}
