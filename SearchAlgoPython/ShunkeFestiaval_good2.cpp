#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 補足:
// lower_bound 関数の返り値はインデックスではなく、イテレータです。イテレータは、配列やコンテナの特定の位置を指し示すオブジェクトで、C++ の標準テンプレートライブラリ (STL) において広く使用されています。
// a.begin() は、配列 a の最初の要素を指すイテレータを返します。このイテレータが指すのは、最初の要素の実際の値ではなく、その位置（アドレス）です。したがって、a.begin() が返すのは 0 ではなく、最初の要素の位置を示すイテレータです。
// イテレータを用いた算術操作では、イテレータ同士の引き算によって、2つのイテレータ間の距離（要素数）が計算されます。この場合、lower_bound(a.begin(), a.end(), i) - a.begin() という式は、lower_bound によって返されたイテレータと a.begin()a.begin() との間の距離を計算し、それを整数値として返します。この「距離」は、検索された要素のインデックスに相当します。

int main(){
  int n;
	ll ans = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  for (int &x : c) cin >> x;
  sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i: b) {
		int x = lower_bound(a.begin(), a.end(), i) - a.begin();
		int y = upper_bound(c.begin(), c.end(), i) - c.begin(); // upper_bound()はiより小さいcの要素までイテレータを移動する
		y = c.size() - y;
		ans += ll(x) * y;
	}
  cout<<ans<<endl;

  return 0;

}
