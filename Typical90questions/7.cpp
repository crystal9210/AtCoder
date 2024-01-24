#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin>>n;
  vector<ll> a(n);
  rep(i,0,n)cin>>a[i];
  cin>>q;
  sort(a.begin(),a.end());
  while(q--){
    ll b;
    cin>>b;
    auto it=lower_bound(a.begin(),a.end(),b);
    ll dis=1000000000000;
    if(it!=a.end()){
      dis=min(dis,llabs(*it-b));
    }
    if(it!=a.begin()){
      it--;
      dis=min(dis,llabs(*it-b));
    }
    cout<<dis<<endl;
  }

  return 0;

}
