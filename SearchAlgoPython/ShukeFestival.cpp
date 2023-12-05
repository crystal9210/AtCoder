#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:2分探索
// 普通にループ回してO(N^3)でしてしまい、TLE
// https://atcoder.jp/contests/arc084/tasks/arc084_a

int main(){
  int n,count=0;
   cin>>n;
   vector<int> a(n),b(n),c(n);
   rep(i,0,n)cin>>a[i];
   rep(i,0,n)cin>>b[i];
   rep(i,0,n)cin>>c[i];
   rep(i,0,n)rep(j,0,n)rep(l,0,n){
    if(a[i]<b[j] && b[j]<c[l]){
      count++;
    }
   }
   cout<<count<<endl;

  return 0;

}
