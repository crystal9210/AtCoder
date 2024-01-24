#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,sumt=0,suma=0;
  cin>>n;
  vector<int> t(n),a(n);
  rep(i,0,n)cin>>t[i]>>a[i];
  rep(i,0,n){
    sumt+=t[i];
    suma+=a[i];
  }
  if(sumt>suma){
    cout<<"Takahashi"<<endl;
  }else if(suma>sumt){
    cout<<"Aoki"<<endl;
  }else{
    cout<<"Draw"<<endl;
  }

  return 0;

}
