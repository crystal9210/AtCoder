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
  ll sum = 0;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int j = 0;
  rep(i, 0, n)
  {
    int st = k + a[i]; // st:standard;基準、便宜上この単語を使う
    while (j < n && a[j] - a[i] <= k)
      j++;
    sum += j - i - 1; // 数えるのはペア数なので-1する、そして、jが1つ無駄に加算されるのでその部分の調整
  }

  cout << sum << endl;

  return 0;
}
