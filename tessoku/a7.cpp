#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_g

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int d, n, number = 0, l, r;
  cin >> d >> n;
  vector<int> l_cnt(d), r_cnt(d);
  rep(i, 0, n)
  {
    cin >> l >> r;
    l_cnt[l - 1]++;
    r_cnt[r]++;
  }
  rep(i, 0, d)
  {
    number += l_cnt[i];
    number -= r_cnt[i];
    cout << number << endl;
  }
  return 0;
}
