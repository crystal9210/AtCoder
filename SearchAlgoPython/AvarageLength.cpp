#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// これはダメなコード→修正後コード:AverageLength_mod.cpp；ダメな理由→26行目参照
// 参照:https://atcoder.jp/contests/abc145/tasks/abc145_c
// 問:座標平面上にn個の町がある。町iは座標(xi,yi)に位置している。町iとjの距離は直線的に考え、√((xi-xj)^2+(yi-yj)^2)。全ての町を任意の順番で訪れる時、その経路はn!通りある。全ての街を訪れる時の移動距離の総和の平均値を計算せよ。

int main(){
  int n;
  long double sum_sum=0;
  ll count=0;
  cin>>n;
  vector<pair<int, int>> loc(n,{0,0});  // 分割した配列で保持するべき→アクセスの短縮
  rep(i,0,n)cin>>loc[i].first>>loc[i].second;
   vector<int> p(n);
  rep(i,0,n){
    p[i] = i;  // インデックスの初期化
  }

  do{
    ll sum=0;  // ループされるたびにsumは0にリセットされる
    rep(i,0,n-1){
      ll x_diff=loc[p[i]].first - loc[p[i+1]].first;
      ll y_diff = loc[p[i]].second - loc[p[i+1]].second;
      sum+=(x_diff * x_diff + y_diff * y_diff); // これだと、√(∑xi^2+∑yi^2)ー①となり、求めたいのは、∑(√(xi^2+yi^2))ー②なので、①≠②より不適
    }
    sum_sum+=sum;
    count++;
  }while(next_permutation(p.begin(),p.end()));

  double ans=sqrt((double)sum_sum/count);
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;

  return 0;
}
