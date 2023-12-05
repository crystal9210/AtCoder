#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/ABC204/tasks/abc204_c
// 方針:有向グラフ
int main(){
  int n,m,ans=0;
  cin>>n>>m;
  vector<int> a(m),b(m);
  rep(i,0,m)cin>>a[i]>>b[i];
  // 下のlistのインデックスに対応させるため調整
  rep(i,0,m){
    a[i]--;
    b[i]--;
  }
  // 方針:始点と終点
  vector<vector<int>> list(n);
  rep(i,0,m){
    // 自己ループ対策
    if(a[i]==b[i]){
      list[a[i]].push_back(a[i]);
      list[a[i]].erase(unique(list[a[i]].begin(), list[a[i]].end()), list[a[i]].end());
      continue;
    }

    list[a[i]].push_back(b[i]);
    list[a[i]].insert(list[a[i]].end(), list[b[i]].begin(), list[b[i]].end());
    list[a[i]].erase(unique(list[a[i]].begin(), list[a[i]].end()), list[a[i]].end());
  }
  rep(i,0,m){
    // 自己ループ対策
    if(a[i]==b[i]){
      list[a[i]].push_back(a[i]);
      list[a[i]].erase(unique(list[a[i]].begin(), list[a[i]].end()), list[a[i]].end());
      continue;
    }

    list[a[i]].push_back(b[i]);
    list[a[i]].insert(list[a[i]].end(), list[b[i]].begin(), list[b[i]].end());
    list[a[i]].erase(unique(list[a[i]].begin(), list[a[i]].end()), list[a[i]].end());
  }
  rep(i,0,m)ans+=list[i].size();
  cout<<ans<<endl;

  return 0;

}
