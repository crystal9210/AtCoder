#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
typedef long long ll;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, 0, n) a[i] = i + 1;
  // 下の処理において配列を逐一反転させるとTLEとなるので配列が反転しているかどうかのフラグを利用、計算時間の短縮
  bool reversed = false;

  rep(i, 0, q)
  {
    int num;
    cin >> num;
    if (num == 1)
    {
      int s, t;
      cin >> s >> t;
      // 反転状態の反映
      if (reversed)
        s = n - s + 1;
      a[s - 1] = t;
    }
    else if (num == 2)
    {
      // 反転フラグを反転させて交換することなく処理を実現
      reversed = !reversed;
    }
    else
    {
      int u;
      cin >> u;
      // 反転してるときの状態をインデックスに反映
      if (reversed)
        u = n - u + 1;
      cout << a[u - 1] << endl;
    }
  }

  return 0;
}
