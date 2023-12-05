#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:bit全探索
// 問:N個の硬貨がある。番号iの硬貨はAi円。硬貨の選び方は2^N通りあるがその中で合計価格がちょうどX円になる選び方はあるか。
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  rep(i,0,n)cin>>a[i];
  bool flag=false;

  rep(i,0,(1<<n)){
    int bit[n],sum=0;
    rep(j,0,n){
      int div=(1<<j);
      bit[j]=(i/div)%2; // iをバイナリ列変換した系列が各番号の硬貨が選択されているかどうかを判定しているので、i/divはj番目の硬貨が選択されているかどうかを情報として保持する。%2するのはi/divの一番下の桁の0か1がj番目の硬貨の選択状態を指していてその部分だけを取り出すため。
    }
    rep(j,0,n)sum+=a[j]*bit[j];
    if(sum==x)flag=true;
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;

}
