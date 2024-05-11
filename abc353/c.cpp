#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define fi first
#define se second
#define pii pair<, >
#define show(a)       \
  for (auto e : a)    \
  {                   \
    cout << e << " "; \
  }                   \
  cout << "\n";

int M = 1e8;

void solve()
{

  int n;
  cin >> n;

  vector<ll> a(n); // l:36のところでllにキャストしなくて済む
  ffor(i, 0, n) cin >> a[i];

  sort(all(a));

  ll ans = 0;

  ffor(i, 0, n) ans += a[i] * (n - 1);

  ffor(i, 0, n)
  {
    ll val = a.end() - lower_bound(a.begin() + i + 1, a.end(), M - a[i]);

    ans -= val * M;
  }
  cout << ans << "\n";
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  // 引数があるとき用に複数のテストスイートを試せるように構築
  while (t--)
    solve();

  return 0;
}
