#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc216/tasks/abc216_e
// 方針:二分探索
int main(){
  int n,k,max=0;
  cin>>n>>k;
  vector<int> fun(n+1,0);
  rep(i,0,n)cin>>fun[i];
  // funが保持する要素を降順に並び替え
  sort(fun.begin(),fun.end(),greater<int>());
  fun[n]=0; // これはだいじょうぶか？→下のループ(☆)の処理で下限を作るための補正

  ll res=0;
  rep(i,0,n){ // -☆
    ll t=1LL*(i+1)*(fun[i]-fun[i+1]);
    if(t<=k){
      k-=t;
      // 等差数列の和の公式;和S=n*(a+l)/2 (n:工数,a:初項,l:末項);fun[i+1]からfun[i]を考える
      res+=1LL*(i+1)*(fun[i]-fun[i+1])*(1LL*fun[i]+fun[i+1]+1)/2;
    }else{
      int v=k/(i+1);  //
      res+=1LL*(i+1)*v*(1LL*fun[i]+fun[i]-v+1)/2;
      res+=1LL*(k-v*(i+1))*(fun[i]-v);
      break;
    }
  }

  cout<<res<<endl;

  return 0;

}
