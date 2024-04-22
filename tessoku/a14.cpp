#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n), c(n), d(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) cin >> c[i];
  rep(i, 0, n) cin >> d[i];

  // 今回の処理の方針的にいらない
  // sort(a.begin(), a.end());
  // sort(b.begin(), b.end());
  // sort(c.begin(), c.end());
  // sort(d.begin(), d.end());

  // unordered_map<int, int> hash_ab;
  // for (int ax : a)
  //   for (int bx : b)
  //     hash_ab[ax + bx]++;

  //  vector<bool> hash_ab(1e8 + 1);だとエラーになる：vector<bool>のインデックスに使用されるtargetが範囲外になる可能性があるため、targetが非常に大きくなるか、または負の値になることがある；下の処理においてtarget=k-(cx+dx)として扱うため
  unordered_map<int, bool> hash_ab;
  for (int ax : a)
    for (int bx : b)
      hash_ab[ax + bx] = true;

  bool can = false;
  for (int cx : c)
  {
    for (int dx : d)
    {
      int target = k - (cx + dx);
      // findメソッド:指定されたキーに対する要素を検索する。このメソッドは、キーが存在すれば、そのキーに対応する値を持つイテレータを返す。キーが存在しない場合は、unordered_mapのend()イテレータを返す
      if (hash_ab[target])
      {
        can = true;
        break;
      }
    }
    if (can)
      break;
  }

  cout << (can ? "Yes" : "No") << endl;

  return 0;
}
