#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  int a, b;
  cin >> a >> b;

  if (a == b)
  {
    cout << -1 << endl;
  }
  else
  {
    rep(i, 1, 4)
    {
      if (i == a || i == b)
      {
        continue;
      }
      else
      {
        cout << i << endl;
      }
    }
  }

  return 0;
}
