#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 最大何人でサッカーできるか

// st:student
struct st
{
  int strength;
  int spirit;
};

int main()
{
  int n, k;
  cin >> n >> k;
  vector<st> sts(n); // sts:students
  rep(i, 0, n) cin >> sts[i].strength >> sts[i].spirit;

  sort(sts.begin(), sts.end(), [](const st &a, const st &b)
       { return a.strength < b.strength; });

  int maxgr = 0; // 作れるグループの最大人数
  rep(i, 0, n)
  {
    int j = i;
    while (j < n && sts[j].strength - sts[i].strength <= k)
    {
      // 内側のループでは気力の差も考慮する
      int minsp = sts[i].spirit, maxsp = sts[i].spirit;
      rep(k, i, j)
      {
        minsp = min(minsp, sts[k].spirit);
        maxsp = max(maxsp, sts[k].spirit);
      }
      if (maxsp - minsp <= k)
      {
        maxgr = max(maxgr, j - i + 1);
      }
      j++;
    }
  }

  cout << maxgr << endl;

  return 0;
}
