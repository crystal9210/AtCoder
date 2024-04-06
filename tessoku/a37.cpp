#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,m,b;
  cin>>n>>m>>b;
  vector<int> a(n),c(m);
  rep(i,0,n)cin>>a[i];
  rep(i,0,m)cin>>c[i];
  ll sum=0,a_sum=0,c_sum=0;
  rep(i,0,n)a_sum+=a[i];
  rep(i,0,m)c_sum+=c[i];
  sum+=a_sum*m;
  sum+=c_sum*n;
  sum+=(ll)b*n*m; // 右辺のすべての変数がintなので明示的に何か一つ以上をllに変換する必要がある、C++は異なる型の変数を含む算術演算を行う際、通常はより大きな型に自動的にアップキャストされる

  cout<<sum<<endl;
  return 0;

}
