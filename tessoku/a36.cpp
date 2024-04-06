#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  ll n,k;
  bool ans=false;
  cin>>n>>k;
  // k%2==0を(k-n+1)%2==0としていてテスト通らなかった、-n+1でkの偶奇が変わってしまう可能性があったので
  if(2*(n-1)<=k && k%2==0)ans=true;
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;

}
