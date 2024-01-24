#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,k=0,ans;
  cin>>n;
  vector<int> a(n);
  rep(i,0,n)cin>>a[i];

  while(2*k-1<=n)k++;
  k--;

  int minl=1e9+7,minr=1e9+7,max=0;
  int l=0,r=n-1;
  rep(i,0,k){
    if(minl>=a[i]){
      minl=a[i];
      l=i;
    }
    if(minr>=a[n-i]){
      minr=a[n-i];
      r=n-i;
    }
  }
  if((r-l+1)%2==0){
    ans=(r-l)/2;
  }else{
    ans=(r-l+1)/2;
  }
  cout<<ans<<endl;

  return 0;

}
