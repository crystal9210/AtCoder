#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 実現できない条件を考えたほうがいい
// 条件：列の中で少なくとも1つ、最後に書き換える3つの連続するタイルが同じ色である必要がある
int main()
{
  int n;
  cin >> n;
  vector<char> vch(n);
  rep(i, 0, n) cin >> vch[i];
  rep(i, 0, n - 2)
  {
    if (vch[i] == vch[i + 1] && vch[i + 1] == vch[i + 2])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
