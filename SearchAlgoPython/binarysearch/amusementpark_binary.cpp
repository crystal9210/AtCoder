#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc216/tasks/abc216_e
// 解法:二分探索
// メイン処理をまとめたユーザ定義関数
void solve(){
  int n,k;  // nの制約:<=10e5
  cin>>n>>k;
  vector<int> fun(n,0);
  rep(i,0,n)cin>>fun[i];
  // funが保持する要素を昇順に並び替え
  sort(fun.begin(),fun.end());
  ll min=0,max=2e9+1;
  while(max>min+1){
    ll mid=(max+min)/2;
    ll sum=0;
    rep(i,0,n){
      if(fun[i]>mid)sum+=fun[i]-mid;
    }
    if(sum>k)min=mid;
    else max=mid;
  }
  ll ans=0;
  // n個のアトラクションの楽しさのうち、maxより大きいものの分をansに追加
  rep(i,0,n){
    if(fun[i]>max){
      ans+=(fun[i]+max+1)*1LL*(fun[i]-max)/2;
      k-=fun[i]-max;
    }
  }
  // 上のループでansに追加していないmaxの値に相当する楽しみをkの残りの回数ですることで最大値を求める
  ans+=k*max;
  cout<<ans<<endl;
}

int main(){

  solve();

  return 0;

}
