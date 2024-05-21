#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 解として出力する変数を用意する、入力変数を用意する、計算に必要な各種変数を用意する

int main()
{
  int h, s = 1, day = 0, sum = 0;
  cin >> h;
  while (sum <= h)
  {
    sum += s;
    day++;
    s *= 2;
  }
  cout << day << endl;

  return 0;
}
