#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
//  https://atcoder.jp/contests/typical90/submissions/48674120

int main(){
  int n,l,k;
  cin>>n>>l>>k;
  vector<int> a(n+1);
  rep(i,0,n)cin>>a[i];
  a[n]=l;
  for(int i=n;i>0;i--){
    a[i]=a[i]-a[i-1];
  }

  int left=-1;
  int right=l+1;
  int mid,count;
  long int temp;

  while(right-left>1){
    mid=(left+right)/2;
    count=0;
    temp=0;
    for(int i:a){
      temp+=i;
      if(temp>=mid){
        count++;
        temp=0;
      }
    }
    if(count>=k+1)left=mid;
    else right=mid;
  }
  cout<<left<<endl;

  return 0;

}
