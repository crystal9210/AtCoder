#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> a(t), row_cnt(n), col_cnt(n);
  int cross1 = 0, cross2 = 0;
  rep(i, 0, t) cin >> a[i];
  vector<vector<bool>> arr(n, vector<bool>(n, false));
  // 今回の問題はビンゴなのでa[i]をarrに反映するごとに縦・横・斜めを効率的にチェックを入れるー＞ちぇっくするにしてもループが多いとTLEするはずなのでどうするか
  rep(i, 0, t)
  {
    int t = a[i];
    int h = (t - 1) / n;
    int w = (t - 1) % n;
    arr[h][w] = true;
    row_cnt[h]++;
    col_cnt[w]++;
    if (h == w)
    {
      cross1++;
    }
    if (h + w == n - 1)
    {
      cross2++;
    }
    if (row_cnt[h] == n || col_cnt[w] == n || cross1 == n || cross2 == n)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
