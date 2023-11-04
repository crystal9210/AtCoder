#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// BFS;breadth first search型探索問題
//　https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
// 問:ねずみが東西南北に区切られた区画により分割される町を移動する。各区画には巣、チーズ工場、障害物、空地のどれかがある。全区画のうちn個はチーズ工場となっており、各工場には硬さが1からnまでのチーズがある。それぞれの硬さを生産する工場が1つずつ、計n個町の中にある。ねずみは最初の強さ1として自分の強さ以下の硬さのチーズを食べることができる。また、隣の区画間を1分で移動でき、移動先の区画のチーズ工場のチーズは食べなくてもよく、障害物の区画には移動できない。ねずみが全てのチーズを食べ終えるまでにかかる最短時間を求めるプログラムを書け。ねずみの食事の時間は考慮しない。
// 下のプログラムにおいて、h:南北方向の区画数、w:東西方向の区画数、n:工場数、それらにより入力から受け取れ、表示できる区画のうち、S:巣、x:障害物、数字i(1からn):そこにあるチーズの硬さ、.:空地

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<vector<char>> sec(h,vector<char>(w));
  rep(i,0,h)rep(j,0,w)cin>>sec[i][j];
  // l.17の確認→ok.
  // rep(i,0,h){
  //   rep(j,0,w)cout<<sec[i][j];
  //   cout<<endl;
  // }



  return 0;

}
