// 問題：喫茶店を訪問した客i(合計c人)について入店時刻siと出店時刻eiを考える。同時刻に店にいた客の数の最大値Mを考える。tは店内の合計人数を数える最大時間
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// 記録にはO(c)、シミュレートにO(t)かかり、全体の計算量はO(c+t)

int main(){
  int c,t;
  cin>>c>>t;
  vector<int> s(c),e(c),table(t);
  rep(i,c)cin>>s[i]>>e[i];


  rep(i,t)table[i]=0;
  rep(i,c){
    table[s[i]]++;
    table[e[i]]--;
  } //table[i]は時刻iに店内にいる客の数

  // シミュレート
  rep(i,t)if(0<i)table[i]+=table[i-1];

  // 最大値を調べる
  int m=0;
  rep(i,t)if(m<table[i])m=table[i];

  cout<<m<<endl;

  return 0;
}
