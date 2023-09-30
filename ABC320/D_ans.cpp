/**
 *    author:  tourist
 *    created: 16.09.2023 08:08:38       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 3>>> g(n);
  for (int i = 0; i < m; i++) {
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
  for (int b = 0; b < (int) que.size(); b++) {
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
