#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  string s;
  cin>>s;
  if(s.empty()){
    cout<<"No"<<endl;
    return 0;
  }else if(!isupper(s[0])){
    cout<<"No"<<endl;
    return 0;
  }else{
    rep(i,1,s.length()){
      if(!islower(s[i])){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;

}
