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
  vector<pair<int, int>> arr(n);
  rep(i, 0, n)
  {
    int l, r;
    cin >> l >> r;
    arr[i] = {l, r};
  }

  vector<pair<int, int>> e;
  rep(i, 0, n)
  {
    e.push_back({arr[i].first, 1});
    e.push_back({arr[i].second, -1});
  }

  sort(e.begin(), e.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first; });

  ll cnt = 0, active = 0;
  for (auto &t : e)
  {
    if (t.second == 1)
    {
      cnt += active;
      active++;
    }
    else
    {
      active--;
    }
  }

  cout << cnt << endl;
  return 0;
}
