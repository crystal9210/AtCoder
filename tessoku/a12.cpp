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
    // 今回はmid=(l+r)/2としても無限ループにはならないが、-1したほうがmain関数より下のコメント部分の通りになるのでよき
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

// mid = (l + r - 1) / 2 の意味と効果
// この式を使用する主な目的は、二分探索の更新中に l と r の間に一貫性を保ちつつ、より均等に探索範囲を分割することです。無限ループを防ぐために -1 を加える理由は、特に l と r が1つの要素だけで隔てられている場合（r = l + 1）に重要です。

// 無限ループの防止
// ケース : l = 4, r = 5 通常の計算 : mid = (4 + 5) / 2 = 4.5 → 4 更新後（条件が満たされない場合） : l = mid + 1 = 5 次のループ : mid = (5 + 5) / 2 = 5 ここでまた l を 5 に設定し、終了するかどうかが鍵ですが、条件が満たされた場合は r = mid で r を 4 に設定し、l < r の条件が偽となりループ終了。満たされない場合は l = 6 となりループ終了。 - 1 を加えた場合
// ケース : l = 2, r = 3 計算 : mid = (2 + 3 - 1) / 2 = 4 / 2 = 2 更新後の動作 : 条件が満たされた場合 : r = mid = 2 条件が満たされない場合 : l = mid + 1 = 3 なぜ - 1 が効果的か 均等分割 : mid の計算に - 1 を加えることで、mid が l と r の間の下側にずれることを意図しています。これにより、探索範囲をより均等に分割する効果があります。 適切な更新 : 特に l と r が非常に近い場合、 - 1 がないと mid が常に l に偏ることになり、l = mid + 1 の更新が十分に効果的でない場合があります。 - 1 を加えることで、mid がもう少し小さくなり、r = mid の更新がより積極的に働きます。
