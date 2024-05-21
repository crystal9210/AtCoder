#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// ペアでいけないかと思ったけど、ソート時にインデックスが不整合を起こすのでstructにする
struct Card
{
  int index;
  int strength;
  int cost;
};

bool compare(const Card &a, const Card &b)
{
  return a.strength < b.strength;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Card> cards(n);
  // first:強さ、second:コスト
  rep(i, 0, n)
  {
    cin >> cards[i].strength >> cards[i].cost;
    cards[i].index = i + 1;
  }
  sort(cards.begin(), cards.end(), compare);
  // デバッグ
  // rep(i, 0, n)
  // {
  //   cout << cards[i].first << " " << cards[i].second;
  //   cout << endl;
  // }
  set<int> remain;
  int minCost = INT_MAX;
  // strengthは降順でループを回しているので考慮するのはcostのみでいい
  for (int i = n - 1; i >= 0; --i)
  {
    if (cards[i].cost <= minCost)
    {
      minCost = cards[i].cost;
      remain.insert(cards[i].index);
    }
  }

  cout << remain.size() << endl;
  for (int index : remain)
    cout << index << " ";
  cout << endl;

  return 0;
}
