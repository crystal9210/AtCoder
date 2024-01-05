#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/typical90/submissions/48996572

// 方針:たぶん①道の重複は許容しない　②道路自体は双方向
// bfsな気がする
// ふつうにノードごとに他の各ノードへの行き方()

using graph=vector<vector<int>>;

int main(){
  int n;
  cin>>n;
  vector<vector<int>> g(n);
  // どこかでインデックスと入力数とですり合わせをしなきゃいけない
  // 連結リストの生成
  rep(i,0,n-1){
    int a,b;
    cin>>a>>b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> d1(n,-1),d2(n,-1);
  d1[0]=0;
  queue<int> que;
  que.push(0);
  while(!que.empty()){
    int cr=que.front(); // キューの先頭から都市crを取り出す
    que.pop();
    // crに隣接する都市nxについてループ
    for(int nx:g[cr]){
      if(d1[nx]==-1){
        que.push(nx);
        d1[nx]=d1[cr]+1;
      }
    }
  }
  // d1を計算した後、0番目の都市から最も距離が遠い都市の番地(mv)およびその都市までの距離(ma)を保持
  int ma=-1,mv=-1;
  rep(i,0,n){
    if(d1[i]>ma){
      ma=d1[i];
      mv=i;
    }
  }
  // 問題文の要件(ポイント)：都市がn個、元々の都市を結ぶ道路がn-1個、そしてすべての都市は道路により連結されていることから都市を結んだ道路は木構造を形成!→mvから最も距離が遠い都市との距離を出した後、しかし、どのようにしてもそのままだと都市間を言って帰ってくることはできない(同じ道を通ってはいけないため)が、問題文中の指示；さて、あなたは整数 u,v(1≤u<v≤N) を自由に選び、都市uと都市vを双方向に結ぶ道路を1本だけ新設することができます。から、最後最長の道で移動し、そのあと直接的な道路を作って帰ればおっけー！ということになり出力がma+1となる。
  d2[mv]=0;
  que.push(mv);
  while(!que.empty()){
    int cr=que.front();
    que.pop();
    for(int nx:g[cr]){
      if(d2[nx]==-1){
        que.push(nx);
        d2[nx]=d2[cr]+1;
      }
    }
  }

  ma=-1;
  for(int x:d2){
    if(x>ma){
      ma=x;
    }
  }

  cout<<ma+1<<endl;

  return 0;

}
