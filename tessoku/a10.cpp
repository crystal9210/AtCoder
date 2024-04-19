#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

class segtree
{
private:
  int n;
  vector<int> tree;

  void build(const vector<int> &data, int node, int start, int end)
  {
    if (start == end)
    {
      tree[node] = data[start];
    }
    else
    {
      int mid = (start + end) / 2;
      build(data, 2 * node + 1, start, mid);
      build(data, 2 * node + 2, mid + 1, end);
      tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
  }

  int query(int node, int start, int end, int l, int r)
  {
    if (r < start || end < l)
      return INT_MIN;
    if (l <= start && end <= r)
      return tree[node];
    int mid = (start + end) / 2;
    int left_query = query(2 * node + 1, start, mid, l, r);
    int right_query = query(2 * node + 2, mid + 1, end, l, r);
    return max(left_query, right_query);
  }

public:
  segtree(const vector<int> &data)
  {
    n = data.size();
    tree.resize(4 * n);
    build(data, 0, 0, n - 1);
  }

  int query(int l, int r)
  {
    return query(0, 0, n - 1, l, r);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  segtree st(a);
  cin >> d;

  rep(t, 0, d)
  {
    int ld, rd;
    cin >> ld >> rd;
    int max_left = ld > 1 ? st.query(0, ld - 2) : INT_MIN;
    int max_right = rd < n ? st.query(rd, n - 1) : INT_MIN;
    cout << max(max_left, max_right) << endl;
  }

  return 0;
}
