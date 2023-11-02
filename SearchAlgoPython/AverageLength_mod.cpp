#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 参照:https://atcoder.jp/contests/abc145/tasks/abc145_c
// 問:座標平面上にn個の町がある。町iは座標(xi,yi)に位置している。町iとjの距離は直線的に考え、√((xi-xj)^2+(yi-yj)^2)。全ての町を任意の順番で訪れる時、その経路はn!通りある。全ての街を訪れる時の移動距離の総和の平均値を計算せよ。

int main(){
  int n,count=0;
  long double sum_sum=0.0;
  cin>>n;
  vector<long long> x(n),y(n);
  rep(i,0,n)cin>>x[i]>>y[i];
  vector<int> p(n);
  rep(i,0,n){
    p[i] = i;  // インデックスの初期化
  }

  do{
    long double sum=0.0;  // ループされるたびにsumは0にリセットされる
    rep(i,0,n-1){
      double x_diff = x[p[i]]-x[p[i+1]];
      double y_diff = y[p[i]]-y[p[i+1]];
      sum += sqrt(x_diff * x_diff + y_diff * y_diff);  // 平方根を取る
    }
    sum_sum+=sum;
    count++;
  }while(next_permutation(p.begin(),p.end()));

  double ans=sum_sum/count;

  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;

  return 0;
}
