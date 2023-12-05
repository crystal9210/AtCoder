#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:2分探索
// https://atcoder.jp/contests/zone2021/tasks/zone2021_c
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll n;
  cin>>n;
  vector<int> as(n),bs(n),cs(n),ds(n),es(n);
  rep(i,0,n)cin>>as[i]>>bs[i]>>cs[i]>>ds[i]>>es[i];
  // 5つの能力値をそれぞれ格納するベクトルを初期化、入力の読み込み
  // auto [as, bs, cs, ds, es] = read_tuple<ll, ll, ll, ll, ll>(n);
  // 生成されるタプルの例:tuple<vector<int>({1, 2, 3}), vector<string>({"one", "two", "three"})>

  // check func;与えられた閾値xがチームの総合力として実現可能かどうかを判定、閾値xを引数で渡す
  auto check=[&](ll x){
    // 最大3人のチームメンバーの組み合わせと5つの能力値についてその組み合わせでxを越えることができるかどうかを記録
    vector<vector<bool>> dp(4,vector<bool>(32,0));
    dp[0][0]=1; // 0人のメンバー；誰も選ばれていない状態ではdp[a][b]のbの値が0-31のいずれでも常に実現可能
    // 【ループの各カウンタ変数】
    // n:メンバー全体数、j:チームの人数、bit:現在のビットマスク状態
    rep_ll(i,0,n)for(ll j=2;j>=0;j--)rep_ll(bit,0,32){
      // dp[j][bit]:これまでに選んだメンバーの数がjであり、各能力値が閾値を越えているかどうかをビットマスクbitで表現した状態
      if(!dp[j][bit])continue;  // 現在のビットマスク状態が実現できない場合、処理をスキップ
      ll nbit=bit;  // 新しいビットマスク状態を保持
      cout<<nbit<<endl;
      nbit|=(as[i]>=x)<<0;
      nbit|=(bs[i]>=x)<<1;
      nbit|=(cs[i]>=x)<<2;
      nbit|=(ds[i]>=x)<<3;
      nbit|=(es[i]>=x)<<4;
      dp[j+1][nbit]=1;
    }

    // dp[3][31] の値が 1 である場合、これは3人のメンバーからなるチームが全ての能力値で閾値を超えることが可能であることを意味
    return dp[3][31];
  };
  // 各メンバーの能力値は最大で10e9まで→チームの総合力も同じ最大値を持つ→論理的に合理的な最大値をrの初期値として保持(lも同様)；探索プロセス中に実際の最大値・最小値が探索範囲から除外されるリスクを回避するため(詳細な理由については下の【参考】を参照)
  ll l=0,r=1e9+1;
  while(l+1<r){
    ll m=(l+r)>>1;  // ☆mを求める値を判別するための基準としてcheck関数内で比較する
    if(check(m))l=m;  // 最終的に出力したいlがmになるはず。なぜなら求めたい値がm以上かどうかをcheck関数内で判別しているため。そして、それが成り立つとき、lにmを代入するから。→ok!
    else r=m;
  }
  cout<<l<<endl;

  return 0;

}

// 【参照】
// ☆二分探索の範囲に最小値-1,最大値+1を用いる理由
// ①二分探索では内部的な処理において、しばしば半開区間を使用する
// ②丸め誤差の回避:浮動小数点数や整数演算において、丸め誤差やオーバーフローを避けるために、範囲の上限をわずかに大きく設定することがある、1e9+1 は、このような誤差を回避するための余裕を提供する
// ③明示的な範囲の確保: r = 1e9+1 とすることで、最大値 1e9 を含む範囲が確実に探索されることを保証
