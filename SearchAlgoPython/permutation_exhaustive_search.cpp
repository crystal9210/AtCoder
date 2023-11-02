#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 順列全探索:permutation brute force;permutation exhaustive search
// 問.n個の年があり、都市iからjへ移動するのにAij円かかる。任意の年から出発し、全ての年を飛行機で一度ずつめぐるとき、最小で何円必要か。

int main(){
  int n,ans=10000000000;
  cin>>n;
  vector<int> p(n,0);
  rep(i,0,n)p[i]=i;
  vector<vector<int>> a(n,vector<int>(n,0));
  rep(i,0,n)rep(j,0,n)cin>>a[i][j];
  do{
    int ret=0;  // ループされるたびにretの値は0にリセットされる
    rep(i,0,n-1)ret+=a[p[i]][p[i+1]];
    ans=min(ans,ret);
  }while(next_permutation(p.begin(),p.end()));

  cout<<ans<<endl;

  return 0;

}
