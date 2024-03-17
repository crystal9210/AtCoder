#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 繰り返し二乗法の関数
ll modPow(ll a,ll b,ll mod){
  ll res=1;
  a%=mod;
  while(b>0){
    if(b&1)res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;  // 指数bを1ビット右にシフト
  }
  return res;
}

int main(){
  ll a,b;
  const ll MOD=1000000007;
  cin>>a>>b;
  // 扱う結果がa^bをMODで割った余りなのでそれに応じてmodPowを設計
  cout<<modPow(a,b,MOD)<<endl;

  return 0;
}
