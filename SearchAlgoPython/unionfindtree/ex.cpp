#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/arc032/tasks/arc032_2
// 実装方針:uni木

struct UnionFind{
  vector<int> par,rank; // par[i]:iの親の番号;par[3]=2⇔3の親が2
  UnionFind(int n):par(n),rank(n,1){
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
    }else{
      par[ry]=rx;
      if(rank[rx]==rank[ry])rank[rx]++;
    }
  }

  bool same(int x,int y){
    return root(x)==root(y);
  }
};
int main(){
  int n,m;
  cin>>n>>m;

  UnionFind tree(n);

  rep(i,0,m){
    int x,y;
    cin>>x>>y;
    tree.unite(x-1,y-1);  // x,yの木を併合する
  }
  int count=-1; // countで結合する回数を求めたいが、これはグループ数-1であり、グループ数は下のrepループによるcount++の回数と一致。よって最初から-1で初期化しておく
  rep(i,0,n)if(tree.root(i)==i)count++;

  cout<<count<<endl;

  return 0;

}
