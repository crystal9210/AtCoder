#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  rep(i, 0, n) a[i] = i + 1;

  // 題意の変更・反転・取得操作を実装すればおっけー
  rep(i, 0, q)
  {
    int num;
    cin >> num;
    if (num == 1)
    {
      int s, t;
      cin >> s >> t;
      a[s - 1] = t;
    }
    else if (num == 2)
    {
      // この実装だとTLE
      // rep(i, 0, n) b[n - i - 1] = a[i];
      // rep(i, 0, n) a[i] = b[i];
      reverse(a.begin(), a.end());

      // 注意：今回は、ソートする時点での各配列の並びを逆順にするので、大きさに従ってソートするわけではない
      // sort(a.rbegin(), a.rend());
    }
    else
    {
      int u;
      cin >> u;
      cout << a[u - 1] << endl;
    }
  }

  return 0;
}
