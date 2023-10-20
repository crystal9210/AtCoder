#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)
#define rep1(i,m,x) for(int i=m;i<(x);i++)
// 問:105は奇数で正の約数を8個持つ。さて、1以上N以下の奇数のうち、正の約数をちょうど8個持つ個数はいくつか？
bool solve(int n){
  int cnt=0;
  rep1(j,1,n+1){
    if(n%j==0)cnt+=1;
    if(cnt==8 && n%2==1)return true;
  }
  return false;
}

int main(){
  int n,ans=0;
  cin>>n;
  rep1(i,1,n+1){  // n以下なので、n+1まででループを指定することに注意
    if(solve(i))ans+=1;
  }
  cout<<ans<<endl;
  return 0;
}
