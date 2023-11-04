#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 題意:グラフgの2頂点s,t(vの要素)が与えられたとき、sから辺をたどってtに到達できるかどうかを判定;有効グラフにするならl.22を削除(a→bのみgに格納される)、無効グラフなら下のように両方記述する
// 方針:BFS

using graph=vector<vector<int>>;

int main(){
  int n,m,s,t;
  cin>>n>>m>>s>>t;

  graph g(n);
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);  // aと隣接するノードを保持する動的配列にノードbを追加
    g[b].push_back(a);
  }

  // 頂点sをスタートとした探索
  vector<int> dist(n,-1);
  queue<int> que;
  dist[s]=0,que.push(s);
  while(!que.empty()){
    int v=que.front();
    que.pop();
    for(auto nv:g[v]){
      if(dist[nv]==-1){
      dist[nv]=dist[v]+1;
      que.push(nv);
      }
    }
  }

  // tにたどり着けるかどうかの判定
  if(dist[t]!=-1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;

}
