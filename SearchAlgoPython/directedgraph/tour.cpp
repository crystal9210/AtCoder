#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/ABC204/tasks/abc204_c
// 方針:有向グラフ(directed graph)
int main(){
  int n,m,ans=0;
  cin>>n>>m;
  vector<int> a(m),b(m);
  rep(i,0,m)cin>>a[i]>>b[i];
  // 隣接リストg;g=graph→グラフは隣接リストにより表現される
  vector<vector<int>> g(n);
  // 下のgのインデックスに対応させるため最初に調整する
  rep(i,0,m){
    a[i]--;
    b[i]--;
    g[a[i]].push_back(b[i]);
  }

  // 深さ優先探索関数
  function<int(int)> dfs=[&](int v){
    vector<bool> visited(n,false);
    stack<int> st;
    st.push(v);
    int count=0;

    while(!st.empty()){
      int cur=st.top();
      st.pop();
      if(visited[cur])continue;
      visited[cur]=true;
      count++;
      for(int u:g[cur]){
        if(!visited[u])st.push(u);
      }
    }
    return count;
  };
  rep(i,0,n)ans+=dfs(i);
  cout<<ans<<endl;

  return 0;

}
