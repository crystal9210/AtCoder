#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc218/tasks/abc218_e
// 解法:mst
// 方針:n頂点m辺の連結無向グラフに対し、辺を削除することにより、連結は保ちつつ、かつ

struct st{
  int first,second,third;
};

int main(){
  int n,m;
  vector<int> a(m),b(m),c(m);
  vector<bool> judge(m,false);
  vector<st> arr(m);
  rep(i,0,m){
    arr[i].first=c[i];
    arr[i].second=a[i];
    arr[i].third=b[i];
  }
  sort(arr.begin(),arr.end());
  rep(i,0,m){
    c[i]=arr[i].first;
    a[i]=arr[i].second;
    b[i]=arr[i].third;
  }


  return 0;

}
