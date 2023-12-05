#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,0,n)cin>>a[i];
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  cout<<a[a.size()-2]<<endl;

  return 0;

}
