#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double lb;

// 正整数x,yに対して(x+y)を10^8で割った余りの和を求める
// なんとか法

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m = 1e8; // ここで1e8を整数リテラルに変換しておかずにそのまま使用すると、浮動小数点リテラルとなり、大きな数値計算に誤差が出る
  ll sum = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  // まず全ての和を求める
  rep(i, 0, n) sum += a[i] * (n - 1);
  rep(i, 0, n)
  {
    ll subtract_iterator = a.end() - lower_bound(a.begin() + i + 1, a.end(), m - a[i]);
    sum -= m * subtract_iterator;
  }
  cout << sum << endl;

  // 次に(x+y)が10^8より大きくなる場合、その数だけ引く

  return 0;
}
