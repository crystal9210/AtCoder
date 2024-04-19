#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 二分探索　bsearch:binary search
int bsearch(const vector<int> &a, int x)
{
  int l = 0;
  int r = a.size() - 1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (a[mid] == x)
    {
      return mid + 1;
    }
    else if (a[mid] > x)
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return -1; // 今回はほんとはいらないけど、一般的な二分探索では必要
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int position = bsearch(a, x);
  cout << position << endl;

  return 0;
}
