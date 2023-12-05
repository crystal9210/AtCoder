#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,sum=0,count=1;
  cin>>n;
  while(sum<n){
    sum+=count;
    // cout<<sum<<endl;
    count++;
  }
  cout<<count-1<<endl;
  return 0;

}
