// this is the code I referred to from ksun48's one for learning purposes.
// R:グー、P:パー、S:チョキ
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  //winnerは関数オブジェクトの型→ラムダ式にすることで、[&]が外部スコープの変数全ての参照を関数内部で利用可能(直接キャプチャ可能)にすることを意味する;[外部参照変数の指定](関数に直接渡す引数)->関数の戻り値 {関数の処理}
  auto winner=[&](char a, char b)->char {
    if(a == 'R' && b == 'S') return a;
		if(a == 'P' && b == 'R') return a;
		if(a == 'S' && b == 'P') return a;
		return b;
  };
  rep(i,k){
    s+=s; //最初の s が "RPSR" だった場合、s += s; の後、s は "RPSRRPSR"
    cout<<s<<endl;
    string v;
    rep(j,n){
      v+=winner(s[2*j], s[2*j+1]);
    }
    s=v;
    cout<<s<<endl;
  }
  cout<<s.front()<<endl;

  return 0;
}
