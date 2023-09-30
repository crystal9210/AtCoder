//This program is referenced for learning purposes from one created by tourist. It is submitted here for verification.
#include <bits/stdc++.h>
// 題意：座標平面上に1からNの番号がついた

using namespace std;
 #define rep(i,x) for(int i=0;i<(x);i++)

int main() {
  // 高速化処理
  ios::sync_with_stdio(false);
  cin.tie(0);

  // n:人の数；それぞれ1からnまでの番号を保持　m:任意の2人の相対位置の情報の数、人aから見た人bの相対位置x,yをm個だけ受け取る
  int n, m;
  cin >> n >> m;
  // 隣接リストgの宣言、例えばg[0]は0番目の人が直接何番目の人と相対的位置の情報を入力から受けたか({1,2,3}：最初の1は0-indexの関係でオフセットを-1ずつずらしているので、事実上2番目の人を意味、2、3はそれぞれ1番目の人から2番目の人がx,y軸方向にそれぞれ2,3だけの位置にいることを意味)を要素とするリスト
  vector<vector<array<int, 3>>> g(n);

  // 人aから見た人bの相対位置x,yをm個だけ受け取るための処理
  rep(i,m){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    --a; --b;
    g[a].push_back({b, x, y});
    g[b].push_back({a, -x, -y});
  }
  vector<bool> was(n, false);
  vector<long long> x(n), y(n);
  was[0] = true;
  vector<int> que(1, 0);
  rep(b,(int)que.size()){
    for (auto& p : g[que[b]]) {
      int to = p[0];
      auto nx = x[que[b]] + p[1];
      auto ny = y[que[b]] + p[2];
      if (!was[to]) {
        x[to] = nx;
        y[to] = ny;
        was[to] = true;
        que.push_back(to);
      } else {
        assert(nx == x[to] && ny == y[to]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      cout << x[i] << " " << y[i] << '\n';
    } else {
      cout << "undecidable" << '\n';
    }
  }
  return 0;
}


