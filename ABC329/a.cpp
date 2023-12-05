#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  string s;
  cin>>s;
  vector<char> chars;
  for(char c:s){
      chars.push_back(c);
    }
    for(char c:chars){
      cout<<c<<" ";
    }
    cout<<endl;
  return 0;

}
