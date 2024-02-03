#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

const int INF=1<<30;  // 2^30

int main(){
  int n,max=0,cnt=0;
  cin>>n;
  vector<int> a(n),dp(n+1,INF); // dp:LISに用いる動的計画法の配列
  rep(i,0,n)cin>>a[i];
  rep(i,0,n){
    // 注意:dp.begin()はイテレータであり、値ではない!+イテレータ間の差分は、コンテナの要素数に等しい→下記のようにして算出
    auto idx=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
    dp[idx]=a[i];
  }

  auto ans=lower_bound(dp.begin(),dp.end(),INF) - dp.begin();
  cout<<ans<<endl;

  return 0;

}
