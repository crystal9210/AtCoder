#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
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

const int MOD = 998244353;

ll numlen(ll x)
{
  if (x == 0)
    return 1;
  ll base = 10;
  while (x >= 10)
  {
    x /= 10;
    base *= 10;
  }
  return base;
}

void solve()
{

  int n;
  cin >> n;

  vector<ll> a(n);               // l:36のところでllにキャストしなくて済む
  ll pile = 0, sum = 0, ans = 0; // pile:pile up:逆順に走査することで次の要素への桁数の和による調整を効率的に計算, sum:これまでの累積和を計算
  rep(i, 0, n) cin >> a[i];
  // 前他の人のコードを参考にした時のエイリアスなので引数注意、第一引数は要素数でおっけー(定義部分で調整してくれてる)
  rfor(i, n, 0)
  {
    ans += ((pile * a[i] % MOD) + sum % MOD) % MOD;
    ans %= MOD; // 忘れないこと
    pile += numlen(a[i]);
    pile %= MOD; // 必要だった→けっきょくMODで割るから途中のオーバーフローだけ防ぐようにしておけばいい
    // cout << pile << endl;
    sum += a[i];
    sum %= MOD;
  }

  cout << ans % MOD << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  while (t)
  {
    solve();
    t--;
  }

  return 0;
}
