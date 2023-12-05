#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:2分探索
// https://atcoder.jp/contests/zone2021/tasks/zone2021_c
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll n;
  cin>>n;
  vector<int> as(n),bs(n),cs(n),ds(n),es(n);
  rep(i,0,n)cin>>as[i]>>bs[i]>>cs[i]>>ds[i]>>es[i];

  // 与えられた閾値が求めたい値以下かどうかを判定 i.e. 結果として返り値がtrueの場合、lにmを代入、そうでない場合rにmを代入し、l<=m<rより、繰り返すことで最終的にl=mとなり、出力した値が求めたい値に一致する
  auto check=[&](ll x){
    vector<vector<ll>> dp(4,vector<ll>(32,0));
    dp[0][0]=1;
    rep_ll(i,0,n)for(ll j=2;j>=0;j--)rep(bit,0,32){
      if(!dp[j][bit])continue;
      ll nbit=bit;
      nbit|=(as[i]>=x)<<0;
      nbit|=(bs[i]>=x)<<1;
      nbit|=(cs[i]>=x)<<2;
      nbit|=(ds[i]>=x)<<3;
      nbit|=(es[i]>=x)<<4;
      dp[j+1][nbit]=1;
    }
    return dp[3][31];
  };

  // 2分探索
  ll l=0,r=1e9+1;
  while(l+1<r){
    ll m=(l+r)>>1;
    if(check(m))l=m;
    else r=m;
  }
  cout<<l<<endl;

  return 0;

}
