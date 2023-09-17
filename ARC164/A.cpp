#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int T;
  cin>>T;

  vector<int> N(T,0),K(T,0),z(T,0),rest(T,0),mid_N(T,0),mid_K(T,0);
  vector<bool> ans(T,false);
  rep(i,T)cin>>N[i]>>K[i];
  rep(i,T)z[i]=N[i]/3; //N[i]-rest[i]=3*z[i]
  rep(i,T)rest[i]=N[i]%3;
  rep(i,T)mid_K[i]=K[i]-rest[i];

  rep(i,T){
    if(N[i]>=3*(K[i]-rest[i])+rest[i] && z[i]>=(K[i]-rest[i])){
      ans[i]=true;
    }else{
      ans[i]=false;
    }
  }

  rep(i,T){
    if(ans[i]){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;  
    }
  }

  return 0;

}