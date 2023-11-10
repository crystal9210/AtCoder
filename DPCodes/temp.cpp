// すごろく系典型問題
// https://atcoder.jp/contests/abc189/tasks/abc189_f
#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> a(k); //各a[i]には振り出しに戻るマス目のインデックス番号を保持
  rep(i,0,k)cin>>a[i];
  vector<vector<double>> p_dp(n+1,vector<double>(n+1+m,0));
  p_dp[0][0]=1;
  rep(i,1,n+1)p_dp[0][i]=0;
  rep(j,1,m)p_dp[1][j]=1/(double)m;
  rep(i,1,n+1)rep(j,m,n+1+m)rep(l,j-m,j){
      p_dp[i][j]+=p_dp[i-1][l]/(double)m;
    }
  // rep(i,0,n+1){
  //   rep(j,0,n+1)cout<<p_dp[i][j]<<" ";
  //   cout<<endl;
  // }
  double ans_p=0;
  rep(j,n,n+m+1)ans_p+=p_dp[n][j];

  cout<<ans_p<<endl;

  return 0;

}
