#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 2部グラフ判定(bipartite graph)問題 i.e. 与無効グラフが二部グラフかどうかを判定する問題
// 方針:BFSの利用
// 判定の基準:連結な無効グラフgで頂点sを1つ選んでsを始点としたbfsを行った時、gは二分グラフ⋀distの値が等しい頂点同士が隣接することはない
// 2部グラフ:グラフ内のノードを二つのグループに分ける。そして同一グループのノード同士では辺が生成されないようなグラフ

using graph=vector<vector<int>>;

int main(){
  // 頂点数n、辺数m
  int n,m;
  cin>>n>>m;

  // グラフ入力受け取り
  graph g(n);
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bool is_bipartite=true;
  vector<int> dist(n,-1);
  queue<int> que;
  rep(v,0,n){
    if(dist[v]!=-1)continue;  // vが探索済みならスルー
    dist[v]=0;
    que.push(v);
    while(!que.empty()){
      int v=que.front();
      que.pop();
      for(auto nv: g[v]){
        // ☆dist[nv]!=-1 i.e. 既に探索されている可能性があるためelse文で下のように判定する必要がある
        if(dist[nv]==-1){
          dist[nv]=dist[v]+1;
          que.push(nv);
        }else{
          // 整合性を確認する→隣あうノード同士の探索の始点sからの最短距離の差は1のみー①。一般的に片方のグループのノード群が保持する距離は偶数or奇数で各々統一される。これがグラフが2部グラフになる必要十分条件。よって、①からdist[v]==dist[nv]が成立すれば、二分グラフではない。
          if(dist[v]==dist[nv])is_bipartite=false;
        }
      }
    }
  }

  if(is_bipartite)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;

}
