#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 与えられた時間tにおいてすべてのプリンターが合計何枚のチラシを印刷できるかを計算する関数をここに書く
ll cntPrint(ll t, const vector<int> &a)
{
  ll tot = 0; // tot:total
  for (int ptime : a)
  {
    tot += t / ptime;
  }
  return tot;
}

// メインロジック実装、時間の計算自体は2分探索を使用
ll findTimeToPrintKNum(const vector<int> &a, int k)
{
  ll l = 0, r = 1e9;
  // 事前にここでrを各aの要素のなんかで処理しておくことで探索範囲を狭めて効率化する
  for (int ptime : a)
  {
    ll possible_max_t = (ll)ptime * k;
    if (possible_max_t < r && possible_max_t <= 1e9)
    {
      r = possible_max_t;
    }
  }
  while (l < r)
  {
    // ここの-1大事
    // 簡単なケースl=2,r=3を考えてみるといい
    ll mid = (l + r - 1) / 2;
    // 探索処理の抽象化→上部の関数に委任
    if (cntPrint(mid, a) >= k)
    {
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;
}

// ドライバ
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  cout << findTimeToPrintKNum(a, k) << endl;

  return 0;
}
