#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

string s[300005];
int n, ans;

int main()
{
  cin >> n;
  rep(i, 1, n + 1) cin >> s[i];

  rep(i, 1, n)
  {
    rep(j, i + 1, n + 1)
    {
      int len = 0;
      while (len < min(s[i].size(), s[j].size()) && s[i][len] == s[j][len])
        len++;
      ans += len;
    }
  }

  cout << ans << endl;
  return 0;
}
