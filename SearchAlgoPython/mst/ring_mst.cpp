#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:最小全域木、クラスカル法
// https://atcoder.jp/contests/abc210/tasks/abc210_e
// I reffered to the code by SSRS which can be read on the page;https://atcoder.jp/contests/abc210/submissions/24296556 .
int gcd(int a, int b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),c(m);
  rep(i,0,m)cin>>a[i]>>c[i];
  vector<pair<int, int>> p(m);
  rep(i,0,m)p[i]=make_pair(c[i],a[i]);
  sort(p.begin(),p.end());
  rep(i,0,m){
    a[i]=p[i].second;
    c[i]=p[i].first;
  }
  int g=n;
  ll ans=0,g2;  // g2は下のループで使用する。言語別の仕様により、ループ内で定義することによる予期しない挙動の発生を避けるため、外部スコープで宣言
  rep(i,0,m){
    if(g>1){
      // gとa[i]の最大公約数：全ノードのうち、それぞれ割り振った番号をa[i]で割った値が同じもの同士をグルーピングする。しかし、それは全体が綺麗にa[i]で割り切れた場合であり、gcd(g,a[i])=1の場合は、modの式からインデックスに関してループが綺麗に作れないため、すべての番号のノードが連結される
      g2=gcd(g,a[i]); // gcdはc++17から標準搭載されるので警告は無視。
      ans+=(ll)c[i]*(g-g2);
      g=g2;
    }
  }
  if(g>1){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }

  return 0;

}
