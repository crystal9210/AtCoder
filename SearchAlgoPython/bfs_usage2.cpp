#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

using graph=vector<vector<int>>;

// 題意:連結成分の個数
// 常に連結とは限らない無効グラフが与えられたとき、それが何個の連結成分からなるかを数える問題。BFSもDFSも同様

int main(){
  // 頂点数n,辺数m
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

  // 頂点sをスタートとした探索
  vector<int> dist(n,-1);
  queue<int> que;
  int count=0;
  // 外側のループ
  rep(v,0,n){
    if(dist[v]!=-1)continue;  // vが探索済みならばスルー
    // dist:distance;各連結成分ごとにその始点を0として、まだ探索されていないかつ、そのvを含む連結成分群を全て走査、各成分のdistにvからの最短距離を格納→これを外側ループrep(v,0,n)においてvをカウンタ変数として回すことで処理を実現する
    dist[v]=0;
    que.push(v);
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
    count++;
  }

  cout<<count<<endl;

  return 0;

}
