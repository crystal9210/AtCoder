#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  ll n,cnt3=0,cnt5=0,cnt15=0;
  cin>>n;
  cnt3=n/3;
  cnt5=n/5;
  cnt15=n/15;
  cout<<(cnt3+cnt5-cnt15)<<endl;
  return 0;
}
