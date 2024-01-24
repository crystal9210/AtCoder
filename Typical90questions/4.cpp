#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
//  https://atcoder.jp/contests/typical90/tasks/typical90_d

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> a(h+1,vector<int>(w+1)), b(h+1,vector<int>(w+1));
  rep(i,0,h)rep(j,0,w)cin>>a[i][j];
  // rep(i,0,h){
  //   rep(j,0,w){
  //     cout<<a[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  rep(i,0,h){
    int t=0;
    rep(k,0,w)t+=a[i][k];
    rep(k,0,w)b[i][k]+=t;
  }
  rep(j,0,w){
    int t=0;
    rep(l,0,h)t+=a[l][j];
    rep(l,0,h)b[l][j]+=t;
  }
  rep(i,0,h)rep(j,0,w)b[i][j]-=a[i][j];

  rep(i,0,h){
    rep(j,0,w){
      cout<<b[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;

}
