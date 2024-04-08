#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 必要とされる処理的に機械学習的に目標に応じて適切な処理分岐が必要層だけどどうやって選択するのか
// 方針：色の遷移からそれらを3の余りで分類
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; // 1<=n<=200000→複雑なループ×
  char c;
  string a;
  cin >> n >> c >> a;
  int total = 0;
  rep(i, 0, n)
  {
    if (a[i] == 'B')
      ++total;
    if (a[i] == 'R')
      total += 2;
  }
  if ((total % 3 == 0 && c == 'W') || (total % 3 == 1 && c == 'B') || (total % 3 == 2 && c == 'R'))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
