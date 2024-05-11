#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  if (n == 1)
  {
    cout << -1 << endl;
    return 0;
  }

  rep(i, 1, n)
  {
    if (h[0] < h[i])
    {
      cout << i + 1 << endl;
      return 0;
    }
    else if (i == n - 1)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  return 0;
}
