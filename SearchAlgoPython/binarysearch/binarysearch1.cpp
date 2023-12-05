#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 問:n人の生徒が背の順に整列している。前からi番目の生徒はaiセンチ。身長がvセンチより低い人は何人か。(できるだけ短い時間で答えること)
int main(){
  int n,
  cin>>n;
  int ng=0,ok=n+1;
  while(ok-ng>1){
    int m=(ng+ok)/2;
    if(a[m]>=v)ok=m;
    else ng=m;
  }
  return 0;

}
