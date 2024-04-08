#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// トンネルの幅が狭いから2人が同じ位置に来たら移動方向を変える
// 追跡する必要があるのか？また、その場合どう追跡するのか？
// ポイント：問題文では「逆方向を進む二人が同じ位置に到達したら方向を変える」とあるが、実際には「すれ違う；次に進む位置を交換する」のと一緒なので、結局進行方向に対して出口まで最も遠い人と出口との距離を求めればおっけー
int main()
{
  int n;
  ll l, ans = 0;
  cin >> n >> l;
  vector<ll> a(n);
  vector<char> b(n);
  rep(i, 0, n)
  {
    ll c;
    char b;
    cin >> c >> b;
    if (b == 'E')
    {
      ans = max(ans, l - c);
    }
    else
    {
      ans = max(ans, c);
    }
  }

  cout << ans << endl;

  return 0;
}
