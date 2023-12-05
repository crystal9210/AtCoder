#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc218/tasks/abc218_e
// 解法:mst
// 方針:n頂点m辺の連結無向グラフに対し、辺を削除することにより、連結は保ちつつ、かつ
// Union-findアルゴリズムを実装しなきゃいけないらしく、テストケースを通らない
struct st{
  int first,second,third;
};
bool compareStDescending(const st& a, const st& b) {
    return a.first > b.first; // 'first' が大きい順
};
bool compareStUpscending(const st& a, const st& b) {
    return a.first < b.first; // 'first' が小さい順
};
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
  int unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    // 木の均衡性を保つためにrankを利用して条件分岐
    if(rx==ry)return -1;
    if(rank[rx]<rank[ry]){
      par[rx]=ry;
    }else{
      par[ry]=rx;
      if(rank[rx]==rank[ry])rank[rx]++;
    }
    return 0;
  }

  bool same(int x,int y){
    return root(x)==root(y);
  }
};

// 方針:①最小全域木を求める②求めた最小全域木に含まれない辺のうち、その重さが正のものをansに加算して出力する
int main(){
  int n,m,ans=0;
  cin>>n>>m;
  vector<int> a(m),b(m),c(m),cnt_node(n,0);
  rep(i,0,m)cin>>a[i]>>b[i]>>c[i];
  rep(i,0,m){
    a[i]--;
    b[i]--;
  }
  vector<st> arr(m);
  rep(i,0,m){
    arr[i].first=c[i];
    arr[i].second=a[i];
    arr[i].third=b[i];
  }
  UnionFind tree(n);
  sort(arr.begin(),arr.end(),compareStUpscending);  // c[i]の値に従い、まずは昇順にソート
  // ソートしたarrの要素を前のインデックスから順に出力
  // rep(i,0,m)cout<<arr[i].first<<' ';
  // cout<<endl;
  // rep(i,0,m)cout<<arr[i].second<<' ';
  // cout<<endl;
  // rep(i,0,m)cout<<arr[i].third<<' ';
  // cout<<endl;
  vector<bool> toRemove(m,false);
  rep(i,0,m){
    if(tree.unite(arr[i].second,arr[i].third)==-1){ // 自己ループと閉路を作る辺の削除＋それらの重みをansに加算
      toRemove[i]=true;
      // cout<<"c[i]:"<<c[i]<<endl;
      ans+=arr[i].first;
    }
  }
  vector<st> newArr;
  rep(i,0,m){
    if(toRemove[i]==false){
      newArr.push_back(arr[i]);
    }
  }
  int size_newArr=newArr.size();

  sort(newArr.begin(),newArr.end(),compareStDescending);  // c[i]の値に従い、昇順にソート
  // rep(i,0,size_newArr)cout<<newArr[i].first<<' ';
  // cout<<endl;
  rep(i,0,size_newArr){
    c[i]=newArr[i].first;
    a[i]=newArr[i].second;
    b[i]=newArr[i].third;
  }
  rep(i,0,size_newArr){
    cnt_node[a[i]]++;
    cnt_node[b[i]]++;
  }
  rep(i,0,size_newArr){
    if(c[i]>0 && cnt_node[a[i]]>1 && cnt_node[b[i]]>1){
      cnt_node[a[i]]--;
      cnt_node[b[i]]--;
      ans+=c[i];
      // cout<<ans<<" ";
    }
  }
  // cout<<endl;

  cout<<ans<<endl;

  return 0;

}
