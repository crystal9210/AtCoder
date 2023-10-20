// this is the code I referred to from tourist's one for learning purposes.
// R:グー、P:パー、S:チョキ
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// じゃんけんの勝敗を決める関数
char Win(char a,char b){
  if(a==b) return a;
  if(a=='R' && b=='S') return a;
  if(a=='P' && b=='R') return a;
  if(a=='S' && b=='P') return a;
  return b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  string s; // 参加者の得意な手を表現する文字列
  cin>>s;
  string win=s;
  int shift=1;  //これは何のフラグ？→じゃんけんで対戦する参加者のインデックスの距離
  // l回各対戦を行うことにより対戦していない残りの組はk-l組になる！
  // n<2^kであることに注意
  // 外側のループは第i回ラウンドを意味。ラウンドが1増えるごとに対戦ペアの組数は1/2となる
  rep(i,k){
    string new_s; // 各大会の勝者の手を保存するために利用
    // 最初のループでは選手は番号0から2^k-1まで
    rep(j,n){
      char x=s[j%n];
      char y=s[(j+shift)%n];
      new_s+=Win(x,y);  // C++のstring型にはchar型の要素を追加することができる
    }
    s=new_s;
    cout<<s<<endl;
    shift=(shift*2)%n;
  }
  cout<<s[0]<<endl;

  return 0;

}
// 〇メモ
// 2^3人の参加者の得意な手が長さ3で与えられる場合について、実際に紙に書いて考えたところ、
// RPSRPSRPとなり、これらからまず抽出される文字列は
// PSRであり、また、それを8個の文字列に当てはめると
// PSRPSRPSとなり、同様にここから抽出される文字列は
// shiftが2となることに注意して、
// PSRであり、それを8個の文字列に当てはめると
// PSRPSRPSとなり、同様にここから抽出される文字列はshiftが4となることに注意して、
// そのインデックス0と4との比較結果が知りたいので、
// PとSを比較して、最後の答えとしてSが得られる。ということですね。実際に比較する表を書き出してみたら、各ラウンドごとに、rep(j,n){
//       char x=s[j%n];
//       char y=s[(j+shift)%n];
//       new_s+=Win(x,y);  // C++のstring型にはchar型の要素を追加することができる
//     }の処理の記述上、
// 結果として得られる文字列のインデックス番号1,3,5,....の奇数番号に余分な結果が表れ、また、元の各i番目の選手得意な手がsの文字列からmodnのインデックスから決定する、という性質上、新しく得られるnew_sについても最初のsと同じ数だけの文字数保持すればよく、各jのループにより得られる結果が循環するため、以上のようにして結果が得られる
