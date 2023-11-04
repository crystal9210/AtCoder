#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

using graph=vector<vector<int>>;

// BFSの簡易的な例コード
// BFS:探索の始点となる頂点から各頂点への最短距離を求めることのできるアルゴリズム

int main(){
  // 頂点の数と辺数
  int n,m;
  cin>>n>>m;

  // グラフ入力受け取り(ここどぇは無効グラフを想定)
  graph g(n);
  rep(i,1,m+1){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // bfsのためのデータ構造;dist:各頂点から頂点0までの最短距離を格納する
  vector<int> dist(n,-1); // 全頂点の状態を未訪問として初期化
  queue<int> que;

  // 初期条件(頂点0を初期ノードとする)
  dist[0]=0;
  que.push(0);  // 0を橙色頂点にする

  // bfs開始(キューが空になるまで探索を行う)
  while(!que.empty()){
    int v=que.front();  // キューから先頭頂点を取りだす
    que.pop();  // キューの先頭を削除

    // vからたどれる頂点を全て調べる→☆g[v]:頂点vと直接的に隣接しているノードの集合(l.20-l.25の実装)
    for(int nv:g[v]){
      if(dist[nv]!=-1)continue; // 既に発見済みの頂点は探索しない

      // 新たな白色頂点nvについて距離情報を更新してキューに追加する→☆vは
      dist[nv]=dist[v]+1;
      que.push(nv); // 探索したノードを次の探索元のノードとしてqueに追加
    }
  }

  // 結果出力(各頂点の頂点0空の距離を見る)
  rep(v,0,n)cout<<v<<": "<<dist[v]<<endl;

  return 0;

}

// 追記:
// つまりa=aなる辺も存在しうるということ。しかし、この場合、1回の辺の追加に2個の辺が追加されてしまう。処理の性質上このような辺の存在の有無が結果に影響することはないが、できたら避けたい

