#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  bool check=true;
  string s;
  cin>>s;
  char lc='A'-1;  // lc:last char
  for(char ch: s){
    if(ch<lc || ch >'C'){
      check=false;
      break;
    }
    lc=ch;
  }
  cout<<(check?"Yes":"No")<<endl;
  return 0;

}
