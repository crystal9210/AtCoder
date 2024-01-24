#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n;
  cin>>n;
  vector<int> a(n),pos(n,-1);
  int head=-1;
  rep(i,0,n){
    cin>>a[i];
    if(a[i]==-1){
      head=i;
    }else{
      pos[a[i]-1]=i;
    }
  }
  for(int i=head;i!=-1;i=pos[i]){
    cout<<(i+1)<<" ";
  }
  cout<<endl;

  return 0;

}
