#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// ゲーム理論の"Nim"ゲームの一種らしい

int main(){
  int n,a,b;
  cin>>n>>a>>b;

  // 逆算的に考える
  vector<bool> dp(n+1,false);
  rep(i,1,n+1){
    if(i-a>=0 && !dp[i-a])dp[i]=true;
    if(i-b>=0 && !dp[i-b])dp[i]=true;
  }

  // dpは先手の勝ち負けの判定結果を保持する→逆算的にdpを用いて上のループで導出しているため
  if(dp[n])cout<<"First"<<endl;
  else cout<<"Second"<<endl;

  return 0;
}
