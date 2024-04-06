#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 3つのことなる入力値をvector aから選んで正三角形が作れるかどうかを判定
int main()
{
  int n;
  ll cnt = 0;
  cin >> n;
  vector<int> a(101);
  rep(i, 0, n)
  {
    int length = 0;
    cin >> length;
    a[length]++;
  }

  // スタックオーバーフローが内部で発生するため、cntおよび右辺の計算式の先頭に型キャストのllを入れる
  rep(i, 0, 101) if (a[i] >= 3) cnt += (ll)(a[i]) * (a[i] - 1) * (a[i] - 2) / 6;
  // 下は方針が間違っている
  // sort(a.begin(), a.end());
  // rep(i, 0, n - 2) if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) cnt++;

  cout << cnt << endl;

  return 0;
}
