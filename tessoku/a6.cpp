#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ai

// 調整後
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);    // インデックス1から開始、入力時にループ内で宣言せず動的配列として外部で宣言して扱ったほうが処理速度が100msほど早い
  vector<ll> dp(n + 1, 0); // 累積和の配列、先頭に0を持つ

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    dp[i] = dp[i - 1] + a[i]; // 累積和の計算
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << '\n'; // 常に同じ計算方法
  }

  return 0;
}
// 元のコード
// int main()
// {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int n, q;
//   cin >> n >> q;
//   vector<int> l(q), r(q), a(n);
//   vector<ll> dp(n);
//   rep(i, 0, n) cin >> a[i];
//   rep(i, 0, q) cin >>
//       l[i] >> r[i];
//   dp[0] = a[0];
//   rep(i, 0, n - 1) dp[i + 1] = dp[i] + a[i + 1];
//   rep(i, 0, q)
//   {
//     if (l[i] == 1)
//       cout << dp[r[i] - 1] << endl;
//     else
//       cout << dp[r[i] - 1] - dp[l[i] - 2] << endl;
//   }

//   // この処理だと論理的に不備があるっぽい
//   // rep(i, 0, q) cout << dp[r[i] - 1] - dp[l[i] - 1] << endl;

//   return 0;
// }
