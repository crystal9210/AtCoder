#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 問:初期値1を持つ変数xがあり、操作A:xの値を2倍にする、操作B:xにkを加える、の2つの操作がある。ここでxに対しA,Bを合計でN解行った時のxが最小となる値を求めよ。
// 方針:操作Aが2という定数を利用することに着目し、2^n-2^(n-1)>KとなるまでAを行い、残りはBを行うようにする。1を2倍するのと1より大きい数zを2倍するのは前者の方が小さい

int main(){
  int n,k,b,output,a_count=0;
  cin>>n>>k;
  // a_countはn-1以下でループを回す
  // 指数を計算する際は、pow関数を使うか、ただし返り値がfloatなため誤値が生じる可能性があり、なるべく使わないほうがいい。よって、2の累乗を考える時は純粋にビット変換を利用したほうがベター
  while((1<<a_count)<=k && a_count<=n-1){
    a_count+=1;
  }
  b=n-a_count;
  output=pow(2,a_count)+b*k;
  cout<<output<<endl;

  return 0;
}
