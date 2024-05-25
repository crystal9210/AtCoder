#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

struct st
{
  char ch;
  int v;
};

bool compare(const st &a, const st &b)
{
  return a.v < b.v;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<st> c(n + m);
  rep(i, 0, n)
  {
    c[i].ch = 'a';
    c[i].v = a[i];
  }
  rep(i, n, n + m)
  {
    c[i].ch = 'b';
    c[i].v = b[i - n];
  }
  // 配列a,bを連結したcに対してどう処理するか
  // 処理とは→cの要素にaの配列の要素が連続で現れることがあるかどうかを判定→cと他のフラグ使って連続数やaとの比較の処理にしようとすると実装がむずかしくなるので、setかpairを用いて実装したほうがよさそう
  sort(c.begin(), c.end(), compare);

  rep(i, 0, n + m - 1)
  {
    if (c[i].ch == 'a' && c[i + 1].ch == 'a')
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
