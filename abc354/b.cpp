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
  vector<pair<string, int>> users(n);
  rep(i, 0, n) cin >> users[i].first >> users[i].second;
  sort(users.begin(), users.end());
  int sum = 0;
  rep(i, 0, n) sum += users[i].second;
  int winner = sum % n;
  cout << users[winner].first << endl;

  return 0;
}
