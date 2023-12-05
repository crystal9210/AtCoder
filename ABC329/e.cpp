#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,m,max_num_p=200001;
  cin>>n>>m;
  vector<int> p(n,0);
  vector<int> a(m,0);
  rep(i,0,m)cin>>a[i];
  rep(i,0,m)a[i]--;
  int max_num=0;
  rep(i,0,m){
    p[a[i]]+=1;
    // rep(j,0,n)cout<<p[j]<<" ";
    // cout<<endl;
    if(max_num<p[a[i]]){
    max_num=p[a[i]];
    max_num_p=a[i];
    }
    if(p[a[i]]==max_num&&a[i]<max_num_p){
      max_num_p=a[i];
    }
    // cout<<"max_num:"<<max_num<<endl;
    cout<<max_num_p+1<<endl;
  }
  return 0;

}
