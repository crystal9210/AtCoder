#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// すべての映画の開始時刻、終了時刻を読み込み、終了時刻が早い順に映画をソートしていく

struct movie
{
  int start, end;
};

int main()
{
  int n;
  cin >> n;
  vector<movie> m(n); // m:movies
  rep(i, 0, n) cin >> m[i].start >> m[i].end;
  // 第一引数、第二引数はイテレータを返していることに注意(復習)、第三引数：ラムダ式、const:関数内で引数が変更されないことを保証、内部のロジックは隠蔽されるようになっているので配列 or vector内の任意の要素a,bに対して特定の処理を指定するだけでおっけー
  sort(m.begin(), m.end(), [](const movie &a, const movie &b)
       { return a.end < b.end; });

  int cnt = 0;
  int last_end = 0;

  for (const auto &movie : m)
  {
    if (movie.start >= last_end)
    {
      cnt++;
      last_end = movie.end;
    }
  }

  cout << cnt << endl;

  return 0;
}
