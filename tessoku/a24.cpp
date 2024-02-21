#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

const int INF=1<<30;  // 2^30；初期化、比較の時に「到達不可能」「非常に大きな値」として使う

int main(){
  int n,max=0,cnt=0;
  cin>>n;
  vector<int> a(n),dp(n+1,INF); // dp:LISに用いる動的計画法の配列
  rep(i,0,n)cin>>a[i];
  rep(i,0,n){
    // 注意:dp.begin()はイテレータであり、値ではない!+イテレータ間の差分は、コンテナの要素数に等しい→下記のようにして算出
    auto idx=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();  // lower_bound():イテレータの範囲内から指定した値以上の最小の要素を探し、その要素を指すイテレータを返す
    dp[idx]=a[i];
    for (int i = 0; i < n + 1; ++i) {
      if (dp[i] < INF) {
          cout << dp[i] << " ";
      } else {
          break; // INFに到達したら、それ以上の要素はLISに関連しないため、ループを抜ける
      }
      }
    cout << endl;
  }



  auto ans=lower_bound(dp.begin(),dp.end(),INF) - dp.begin();
  cout<<ans<<endl;



  return 0;

}
