#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// サンプルケース1がどうしても通らないが、テストケースはすべて通り、内部ロジック的にもあっているはず、ACしてる

// 最近傍法；ある点から出発して、まだ訪れていない点の中で最も近い点を次に訪れる点として選び、すべての点を訪れるまでこのプロセスを繰り返す、問題の規模が大きくなると、最適解を見つけることが現実的でなくなるため、近似解を効率的に求める方法として有用

// 貪欲法；Greedy Algorithm
// 貪欲法は、問題を解くためのアルゴリズムの一つ、各ステップで最も良いと思われる選択をしていく方法、この「最も良い」とは、その時点で最も利益をもたらす、またはコストを最小限に抑えるなどの基準に基づく。一度行った選択を後で変更しない、つまり、局所的に最適な選択を積み重ねることで、全体としての最適解を目指す

struct city
{
  int x, y;
  bool is_visited;
};
int main()
{
  int n;
  cin >> n;
  vector<city> c(n); // c:cities
  rep(i, 0, n)
  {
    cin >> c[i].x >> c[i].y;
    c[i].is_visited = false;
  }

  // 都市は１から順に巡る
  cout << 1 << endl;
  c[0].is_visited = true;
  int cur = 0; // cur:current city number
  rep(i, 1, n)
  {
    // 後の処理の比較ために今いる都市の各データを変数に保持、ループごとにその時の値が反映されるようになっている(再代入される)→処理の性質上必要
    int curx = c[cur].x;
    int cury = c[cur].y;
    double min_dist = numeric_limits<double>::max(); // C++のdouble型の変数が格納できる最大値で初期化(ライブラリの提供機能)
    int next = -1;                                   // next:next city numbser

    // 未訪問の都市で現在の都市からもっとも距離が近いものを選択し、変数に格納→後続の処理に反映することでロジックを実現
    rep(j, 0, n)
    {
      if (!c[j].is_visited)
      {
        double dist = (c[j].x - curx) * (c[j].x - curx) + (c[j].y - cury) * (c[j].y - cury); // 平方根を取る必要はない
        if (dist < min_dist)
        {
          min_dist = dist;
          next = j;
        }
      }
    }
    cout << (next + 1) << endl;
    c[next].is_visited = true;
    cur = next;
  }
  cout << 1 << endl;

  return 0;
}
