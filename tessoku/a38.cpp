#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// いもす法

int main()
{
  int d, n;
  cin >> d >> n;
  vector<int> wtime(d, 24);
  // 範囲ごとにループを回して最大値を求めて反映していく
  rep(i, 0, n)
  {
    int l, r, h;
    cin >> l >> r >> h;
    l--;
    rep(j, l, r) if (wtime[j] > h) wtime[j] = h;
  }

  int sum = 0;
  rep(i, 0, d) sum += wtime[i];

  cout << sum << endl;

  return 0;
}
