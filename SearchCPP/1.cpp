#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=1;i<(x);i++)
//問題文：N*Nの碁盤目状道路に対し、左上座標を(0,0)、右下座標(N,N)とするとき、左上から右下まで同じ交差点を通らずに行くような方法は何通りあるか
// 方針：碁盤目状道路の進み方として垂直方向にN、水平方向にNだけ進むからその組み合わせとして2NCN通り。
// 計算量はO(N)のはず

int combi(int n){
  int ans=1;
  rep(i,n+1){
    ans*=i;
  }
  cout<<ans<<endl;
  return ans;
}

int main(){
  int n,out;
  cin>>n;
  out=combi(2*n)/combi(n);
  cout<<out<<endl;
  return 0;
}
