#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)
#define rep1(i,m,x) for(int i=m;i<(x);i++)
// 問：N個のカードが一列に並んでおり、左からi番目のカードに書かれた数はAi。N枚から3枚カードを選びそれらの和がKになるような場合は何通りあるか。
// 制約:1<=N<=50,1<=Ai,K<=10^8
// 方針:全探索→下の処理において、三つの要素の和がkに一致するような場合を全てのインデックスの組に対して調べている(全探索的)

int main(){
  int n,k,count=0;
  cin>>n>>k;
  vector<long long> a(n);
  rep(i,n)cin>>a[i];
  rep1(i,0,n)rep1(j,i+1,n)rep1(l,j+1,n){
    if(a[i]+a[j]+a[l]==k)count++;
  }
  cout<<count<<endl;

  return 0;

}
