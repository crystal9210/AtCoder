#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll tile_distance(ll K, ll Sx, ll Sy, ll Tx, ll Ty)
{
  auto is_small_tile = [K](ll x, ll y)
  {
    return (x / K + y / K) % 2 == 0;
  };

  ll dx = abs(Sx - Tx);
  ll dy = abs(Sy - Ty);
  ll upper_bound = dx + dy;

  if (K == 1)
    return upper_bound;

  vector<pair<ll, ll>> start_candidates, end_candidates;

  auto add_candidates = [&](ll x, ll y, vector<pair<ll, ll>> &candidates)
  {
    if (!is_small_tile(x, y))
      candidates.push_back({x, y});
    for (ll d = 1; d < K; ++d)
    {
      if (is_small_tile(x + d, y))
        candidates.push_back({x + d, y});
      if (is_small_tile(x - d, y))
        candidates.push_back({x - d, y});
      if (is_small_tile(x, y + d))
        candidates.push_back({x, y + d});
      if (is_small_tile(x, y - d))
        candidates.push_back({x, y - d});
    }
  };

  add_candidates(Sx, Sy, start_candidates);
  add_candidates(Tx, Ty, end_candidates);

  ll min_cost = upper_bound;
  for (const auto &start : start_candidates)
  {
    for (const auto &end : end_candidates)
    {
      ll cost = abs(start.first - end.first) + abs(start.second - end.second);
      cost += abs(abs(start.first - end.first) - abs(start.second - end.second));
      min_cost = min(min_cost, cost);
    }
  }

  return min_cost;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll K, Sx, Sy, Tx, Ty;
  cin >> K >> Sx >> Sy >> Tx >> Ty;

  cout << tile_distance(K, Sx, Sy, Tx, Ty) << endl;

  return 0;
}
