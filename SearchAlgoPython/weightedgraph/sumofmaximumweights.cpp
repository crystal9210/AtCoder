#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc214/tasks/abc214_d
// 方針:uni木の利用。普通に。
// 参照元:https://atcoder.jp/contests/abc214/submissions/25041685

struct UnionFind{
  vector<int> par,rank,size; // par[i]:iの親の番号;par[3]=2⇔3の親が2
  UnionFind(int n):par(n),rank(n,1),size(n,1){
    rep(i,0,n)par[i]=i; // 最初は全てが根であるとして初期化
  }
  // データxが属する木の根を再帰で得る
  int root(int x){
    if(par[x]==x)return x;
    return par[x]=root(par[x]); // 経路圧縮も兼ねている!!
  }

  // xとyの木を併合→これはunionなんちゃらで併合する木のランクを比較してその結果に基づいた併合をするべき
  // UF構造体の実装方針としてparを使って有向的に実装しているので、unite関数内の条件分岐の部分のインデックスをx,yとしてしまうと正常な処理ができない。図を書いて確認するとわかる
  void unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    // 木の均衡性を保つためにrankを利用して条件分岐
    if(rx==ry)return;
    if(rank[rx]<rank[ry]){
      par[rx]=ry;
      size[ry]+=size[rx]; // サイズ更新
    }else{
      par[ry]=rx;
      size[rx]+=size[ry]; // サイズ更新
      if(rank[rx]==rank[ry])rank[rx]++;
    }
  }

  bool same(int x,int y){
    return root(x)==root(y);
  }

  int count(int x){
    return size[root(x)]; // xが属する集合のサイズを返す
  }

};


int main(){
  int n;
  cin>>n;
  ll ans=0;
  vector<tuple<int,int,int>>rel;
  rep(i,0,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    rel.emplace_back(w,u-1,v-1);
  }
  sort(rel.begin(),rel.end());
  UnionFind uf(n);
  // 普通に問題の意図に従った計算結果を求めるように計算
  for(auto [w,u,v]:rel){
    ans+=w*uf.count(u)*uf.count(v);
    uf.unite(u,v);
  }

  cout<<ans<<endl;

  return 0;

}
