#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;

template <typename F>
using fn = function<F>;

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()

template <class A>
int len(const A &a) {
  return a.size();
}

#define eb emplace_back
#define pb push_back
#define elif else if

template <typename T>
using vec = vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;
template <typename T>
using vec4 = vec<vec3<T>>;
template <typename T>
using vec5 = vec<vec4<T>>;

#define VEC(T, a, ...) \
  vec<T> a(__VA_ARGS__)

#define VEC2(T, a, n, ...) \
  vector a(n, vec<T>(__VA_ARGS__));

#define VEC3(T, a, n, m, ...) \
  vector a( \
    n, \
    vector(m, vec<T>(__VA_ARGS__)) \
  );

#define VEC4(T, a, n, m, l, ...) \
  vector a( \
    n, \
    vector( \
      m, \
      vector(l, vec<T>(__VA_ARGS__)) \
    ) \
  );

#define eval_4(a, b, c, d, e, ...) e

#define loop while (1)

#define rep(n) \
  for (int __ = 0; __ < n; __++)

#define range_1(i, n) \
  for (int i = 0; i < n; i++)
#define range_2(i, a, b) \
  for (ll i = a; i < b; i++)
#define range_3(i, a, b, c) \
  for (ll i = a; i < b; i += c)

#define range(...) \
  eval_4(__VA_ARGS__, range_3, range_2, range_1, rep)( \
    __VA_ARGS__ \
  )

#define ranger_1(i, n) \
  for (int i = n; i-- > 0;)
#define ranger_2(i, a, b) \
  for (ll i = b; i-- > a;)
#define ranger_3(i, a, b, c) \
  for (ll i = b - 1; i >= a; i -= c)

#define range_rev(...) \
  eval_4(__VA_ARGS__, ranger_3, ranger_2, ranger_1)( \
    __VA_ARGS__ \
  )

#define iter(x, a) \
  for (const auto &x : a)
#define iter_mut(x, a) \
  for (auto &&x : a)

template <typename T, typename U>
istream &
operator>>(istream &in, pair<T, U> &p) {
  return in >> p.first >> p.second;
}

template <typename T, typename U>
ostream &operator<<(
  ostream &out,
  pair<T, U> &p
) {
  out << p.first << ' ' << p.second;
  return out;
}

template <int k = 0, class T>
void read_tup(istream &in, T &x) {
  if constexpr (tuple_size<T>::value > k) {
    in >> get<k>(x);
    read_tup<k + 1>(in, x);
  }
}

template <class... T>
istream &operator>>(
  istream &in,
  tuple<T...> &x
) {
  read_tup(in, x);
  return in;
}

template <int k = 0, class T>
void out_tup(ostream &out, T &x) {
  if constexpr (tuple_size<T>::value > k) {
    if constexpr (k > 0) {
      out << ' ';
    }
    out << get<k>(x);
    out_tup<k + 1>(out, x);
  }
}

template <class... T>
ostream &operator<<(
  ostream &out,
  tuple<T...> &x
) {
  out_tup(out, x);
  return out;
}

template <typename T>
auto operator<<(ostream &out, vec<T> a)
  -> ostream & {
  range(i, len(a)) {
    if (i) {
      out << ' ';
    }
    out << a[i];
  }
  return out;
}

template <typename T>
auto operator<<(ostream &out, vec2<T> a)
  -> ostream & {
  iter_mut(x, a) out << x << '\n';
  return out;
}

template <typename T>
auto operator>>(istream &in, vec<T> &a)
  -> istream & {
  iter_mut(x, a) in >> x;
  return in;
}

template <typename... T>
void in(T &...a) {
  (cin >> ... >> a);
}

template <class T, class... U>
void out(T a, const U... b) {
  cout << a;
  ((cout << ' ' << b), ...);
  cout << '\n';
}

template <typename T = int>
vec<T> iota(int n, T v = 0) {
  vec<T> a(n);
  std::iota(all(a), v);
  return a;
}

template <class T>
using max_queue = priority_queue<T>;

template <class T>
using min_queue =
  priority_queue<T, vec<T>, greater<T>>;

template <typename T>
T pop(queue<T> &q) {
  T v = q.front();
  q.pop();
  return v;
}

template <typename T>
T pop(deque<T> &q) {
  T v = q.front();
  q.pop_front();
  return v;
}

template <typename T>
T pop(vec<T> &q) {
  T v = q.back();
  q.pop_back();
  return v;
}

template <typename T>
T pop(max_queue<T> &q) {
  T v = q.top();
  q.pop();
  return v;
}

template <typename T>
T pop(min_queue<T> &q) {
  T v = q.top();
  q.pop();
  return v;
}

template <typename T>
T max(const vec<T> &a) {
  return *max_element(all(a));
}

template <typename T>
T min(const vec<T> &a) {
  return *min_element(all(a));
}

int topbit(int x) {
  return 31 - __builtin_clz(x);
}

template <class T>
bool operator==(
  const vec<T> &a,
  const vec<T> &b
) {
  int n = len(a);
  if (len(b) != n) {
    return false;
  }
  range(i, n) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

template <class T, class U>
bool chmin(T &a, const U &b) {
  return b < a ? a = b, 1 : 0;
}

template <class T, class U>
bool chmax(T &a, const U &b) {
  return b > a ? a = b, 1 : 0;
}

int popcnt(int x) {
  return __builtin_popcount(x);
}

template <class T, class U>
T sum(const vec<U> &a) {
  return accumulate(all(a), 0ll);
}

template <class T>
void unique(vec<T> &a) {
  sort(all(a));
  a.erase(std::unique(all(a)), a.end());
}

template <class T, class A>
int lb(const A &a, const T &x) {
  auto p = lower_bound(all(a), x);
  return distance(a.begin(), p);
}

template <class T, class A>
int ub(const A &a, const T &x) {
  auto p = upper_bound(all(a), x);
  return distance(a.begin(), p);
}

template <class A>
vec<int> argsort(const A &a) {
  int n = len(a);
  auto b = iota(n);
  sort(all(b), [&](int i, int j) {
    return a[i] < a[j];
  });
  return b;
}

template <class T>
int ctz(T n) {
  return __builtin_ctzll(n);
}

template <class T>
int bitlen(T n) {
  return 64 - __builtin_clzll(n);
}

template <typename T>
auto divmod(T a, T b) -> pair<T, T> {
  T q = a / b;
  return {q, a - q * b};
}

template <typename T>
int argmax(const vec<T> &a) {
  int n = len(a);
  assert(n);
  int j = 0;
  range(i, 1, n) {
    if (a[i] > a[j]) {
      j = i;
    }
  }
  return j;
}

#ifdef DEBUG
#define dbg(...) out(__VA_ARGS__);
#else
#define dbg(...) ;
#endif

#ifdef DEBUG
#define dbg_assert(...) \
  assert(__VA_ARGS__);
#else
#define dbg_assert(...) ;
#endif

// define yes/no
#define yesno(y, n) \
  void yes(bool f = 1) { \
    out(f ? #y : #n); \
  } \
  void no() { \
    out(#n); \
  }

yesno(yes, no);

// yesno(Yes, No);
// yesno(YES, NO);

// with msb (l = msb + 1), l bit
uint bit_reverse(int l, uint n) {
  constexpr uint masks[5] = {
    0xaaaaaaaaU,
    0xccccccccU,
    0xf0f0f0f0U,
    0xff00ff00U,
    0xffff0000U,
  };
  for (int i = 0; i < 5; i++) {
    int d = 1 << i;
    uint m = masks[i];
    n =
      ((n & m) >> d) | ((n & ~m) << d);
  }
  return n >> (32 - l);
}

template <class T>
void arg_bit_reverse(vec<T> &a) {
  // butterfly
  int n = len(a);
  int h = ctz(n);
  dbg_assert(1 << h == n);
  range(i, n) {
    int j = bit_reverse(h, i);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
}

// iterative
// inplace
template <class R>
void fft(
  vec<complex<R>> &a,
  bool inv = 0
) {
  int s = inv ? -1 : 1;
  int n = len(a);
  arg_bit_reverse(a);
  for (int d = 1; d < n; d <<= 1) {
    auto g = polar<R>(1, s * M_PI / d);
    complex<R> w = 1;
    range(j, d) {
      range(i, j, n, d << 1) {
        auto x = a[i + d] * w;
        a[i + d] = a[i] - x;
        a[i] += x;
      }
      w *= g;
    }
  }
  if (inv) {
    iter_mut(x, a) x /= n;
  }
}

template <class R>
vec<complex<R>> conv(
  vec<complex<R>> a,
  vec<complex<R>> b
) {
  int n = len(a), m = len(b);
  int k = n + m - 1;
  dbg_assert(k);
  int k2 = 1 << bitlen(k - 1);
  a.resize(k2);
  b.resize(k2);
  fft(a);
  fft(b);
  range(i, k2) a[i] *= b[i];
  fft(a, 1);
  a.resize(k);
  return a;
}

template <class R, class Z>
vec<complex<R>>
to_complex(const vec<Z> &a) {
  int n = len(a);
  vec<complex<R>> b(n);
  range(i, n) b[i].real(a[i]);
  return b;
}

template <class Z, class R>
vec<Z> to_rint(const vec<complex<R>> &a
) {
  int n = len(a);
  vec<Z> b(n);
  range(i, n) b[i] = round(a[i].real());
  return b;
}

template <class Z>
vec<Z>
conv(const vec<Z> &a, const vec<Z> &b) {
  using R = double;
  return to_rint<Z>(conv(
    to_complex<R>(a),
    to_complex<R>(b)
  ));
}

template <class T>
T norm(T m, T x) {
  assert(m > 0);
  if (x < -m || x >= m) {
    x %= m;
  }
  if (x < 0) {
    x += m;
  }
  return x;
}

// karatsuba
vec<ll> conv(
  int m,
  const vec<ll> &a,
  const vec<ll> &b
) {
  static constexpr int K = 15;
  static constexpr int M = (1 << K) - 1;
  int n = len(a), k = len(b);
  vec<ll> a1(n), a0(n), a10(n);
  vec<ll> b1(k), b0(k), b10(k);
  range(i, n) {
    a1[i] = a[i] >> K;
    a0[i] = a[i] & M;
    a10[i] = a1[i] + a0[i];
  }
  range(i, k) {
    b1[i] = b[i] >> K;
    b0[i] = b[i] & M;
    b10[i] = b1[i] + b0[i];
  }

  auto c0 = conv(a0, b0);
  iter_mut(x, c0) x %= m;
  auto c = conv(a1, b1);
  iter_mut(x, c) x %= m;
  auto c1 = conv(a10, b10);
  int l = len(c);
  range(i, l) {
    c1[i] -= c0[i] + c[i];
    c1[i] = norm<ll>(m, c1[i]);
    c[i] <<= K << 1;
    c[i] += c1[i] << K;
    c[i] += c0[i];
    c[i] %= m;
  }
  return c;
}

void solve() {
  ll n;
  int b, k;
  in(n, b, k);
  vec<int> c(k);
  in(c);
  vec<ll> y(b), x(b);
  y[0] = 1;
  iter(v, c) x[v % b]++;
  const int mod = 1'000'000'007;
  auto mul = [&](
               int ten,
               const vec<ll> &f,
               const vec<ll> &g
             ) -> vec<ll> {
    vec<ll> h(b);
    range(i, b) {
      h[ten * i % b] += f[i];
    }
    iter_mut(x, h) x %= mod;
    h = conv(mod, h, g);
    range(i, b, 2 * b - 1) {
      h[i - b] += h[i];
    }
    h.resize(b);
    iter_mut(x, h) x %= mod;
    return h;
  };
  int t = 10 % b;
  while (n) {
    if (n & 1) {
      y = mul(t, y, x);
    }
    x = mul(t, x, x);
    n >>= 1;
    t = t * t % b;
  }
  out(y[0]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // cout << setprecision(16);
  int t = 1;
  // in(t);
  while (t--) {
    solve();
  }
}
