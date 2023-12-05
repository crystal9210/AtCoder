#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 方針:二分探索
// https://atcoder.jp/contests/abc206/tasks/abc206_b
int main(){
  int n,count=1;
  cin>>n;
  while(count*(count+1)/2<n){
    count++;
  }
  cout<<count<<endl;

  return 0;

}
