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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int r = 0, current = k;
  rep(i, 0, n)
  {
    if (a[i] > current)
    {
      r++;
      current = k;
    }
    current -= a[i];
    if (i < n - 1 && a[i + 1] > current)
    {
      r++;
      current = k;
    }
  }

  r++;

  cout << r << endl;
  return 0;
}
