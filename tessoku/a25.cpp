#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 時間計算量：O(HW)

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> loc(h,vector<char>(w));
  rep(i,0,h)rep(j,0,w)cin>>loc[i][j];
  // rep(i,0,h){
  //   rep(j,0,w){
  //     cout<<loc[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  vector<vector<ll>> dp(h,vector<ll>(w,0));
  dp[0][0]=1; // スタート地点
  rep(i,0,h)rep(j,0,w){
    if(loc[i][j]=='#')continue; // 黒いますはスキップ
    if(i>0)dp[i][j]+=dp[i-1][j];  // 上からくる場合
    if(j>0)dp[i][j]+=dp[i][j-1];  // 左からくる場合
  }

  cout<<dp[h-1][w-1]<<endl;

  return 0;

}
