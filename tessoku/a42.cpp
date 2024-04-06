#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  int n, k;
  cin >> n >> k;
  // str:strength,spi:spirit
  vector<int> str(n + 1), spi(n + 1);
  rep(i, 1, n + 1)
  {
    cin >> str[i] >> spi[i];
  }

  int ans = 0;

  // 体力と気力を固定したとき、二つの基準を元に全ての生徒を一人一人条件を満たすかループを回す
  rep(i, 1, 101)
  {
    rep(j, 1, 101)
    {
      // 条件を満たす生徒数
      int cnt = 0;

      // すべての生徒を調査
      rep(l, 1, n + 1)
      {
        // 生徒kが条件を満たすかどうか
        if (str[l] >= i && str[l] <= i + k && spi[l] >= j && spi[l] <= j + k)
        {
          cnt++;
        }
      }

      // 最大グループサイズを更新
      ans = max(ans, cnt);
    }
  }

  // 最大グループサイズを出力
  cout << ans << endl;

  return 0;
}
