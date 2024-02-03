#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

char findChar(const string &s){
  vector<int> freq(26,0);
  for(char c:s){
    freq[c-'a']++;
  }
  int max=0;
  char res='a';
  for(int i=0;i<26;++i){
    if(freq[i]>max){
      max=freq[i];
      res='a'+i;
    }
  }
  return res;
}

int main(){
  string s;
  cin>>s;
  char ans=findChar(s);
  cout<<ans<<endl;

  return 0;

}
