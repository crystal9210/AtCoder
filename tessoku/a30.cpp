#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 繰り返し二乗法によるa^b mod MODを計算する関数
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

// aのモジュラー逆元を計算
ll modInv(ll a, int mod){
  return modPow(a,mod-2,mod); // フェルマーの小定理を利用;フェルマーの小定理とは、modが素数で、aがmodで割り切れない時、a^(mod-1)はmodを法として1に等しい、という定理です。この定理から、a^(mod-2)がaのモジュラー逆元となる
}

// nCr mod MODを計算
ll nCr(int n,int r,int mod){
    ll fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    ll res=fact[n]; // n!
    res=(res*modInv(fact[r],mod))%mod; // r! の逆元をかける、かけあわせた後にmodで割ることで事実上nCrを求めている
    res=(res*modInv(fact[n-r],mod))%mod; // (n-r)! の逆元をかける
    return res;
}
// 【nCr関数の計算原理】
// 二項係数nCrの計算式はn! / (r! * (n-r)!)ですが、モジュラー算術（割り算の余りを扱う数学）においては、通常の割り算が直接使えません。そのため、「割る」という操作をモジュラー算術において行うためには、「モジュラー逆元」という概念を利用します。

// モジュラー逆元とは、ある数aに対して、その数と掛け合わせることで1になる数（モジュラーmodの下で）のことを指します。つまり、aをbで「割る」ことは、aにbのモジュラー逆元を掛けることに相当します。


int main(){
  int n,r;
  cin>>n>>r;
  const ll MOD=1000000007;
  cout<<nCr(n,r,MOD)<<endl;

  return 0;

}
