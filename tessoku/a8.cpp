#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, q, a, b, c, d;
  cin >> h >> w;
  // あとでインデックスを調整すると色々ややこしくなるのでここで最初に調整
  vector<vector<int>> grid(h + 1, vector<int>(w + 1)), dp(h + 1, vector<int>(w + 1));
  rep(i, 1, h + 1) rep(j, 1, w + 1) cin >> grid[i][j];
  // dpの初期化処理
  dp[1][1] = grid[1][1];
  for (int i = 2; i < h + 1; ++i)
    dp[i][1] = dp[i - 1][1] + grid[i][1];
  for (int j = 2; j < w + 1; ++j)
    dp[1][j] = dp[1][j - 1] + grid[1][j];

  // dpの各要素を計算する
  rep(i, 2, h + 1) rep(j, 2, w + 1) dp[i][j] = grid[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
  cin >> q;

  rep(i, 0, q)
  {
    cin >> a >> b >> c >> d;
    cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << endl;
  }

  return 0;
}
