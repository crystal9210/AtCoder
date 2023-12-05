#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// this is the code I referred to from kotatsugame for learning purposes.
// https://atcoder.jp/contests/abc189/submissions/19611100
// 方針:確率DP
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> a(k);
  vector<bool> out(n,false);
  vector<double> da(n+m,0),db(n+m,0);
  rep(i,0,k){
    cin>>a[i];
    out[a[i]]=true;
  }
  double sa=0,sb=0;
  // point:逆順に走査する:求める値;スタート地点からゴールまでの試行回数の期待値da[0]を求めるのに利用する累積和を求めるための処理
  for(int i=n;i--;){  // 0になるまでデクリメントを意味
      if(out[i])db[i]=1;
      else{
        da[i]=sa/m+1; // ゴールするまでに必要な試行回数の平均値は、遷移先の期待される試行回数＋1(遷移先に遷移するためには1かいすごろくを振るため)
        db[i]=sb/m;  // i番目のマスからゴールまでで振り出しに戻る確率は次に遷移するであろうマス群の同一の確率の累積和の平均
      }
      // ループ処理をする対象のマスが一つ左に移動するのでm個の遷移先の各数値を保持する累積和sa,sbもその両端を1ずつ左にずらす
      sa+=da[i]-(i+m<n+m ? da[i + m] : 0);
      sb+=db[i]-(i+m<n+m ? db[i + m] : 0);
  }

  double ans;
  if(k==0)ans=da[0];
  else if(db[0]<1-1e-8){
    ans=da[0]/(1-db[0]);
  }else{
    cout<<-1<<endl;
    return 0;
  }

  cout<<fixed<<setprecision(16)<<ans<<endl;

  return 0;

}
