// 勝ち負け判定；トーナメント
// 問題：じゃんけん大会。R:グー、P:パー、S：チョキとし、大会参加者は2^k人、それぞれ0から2^k -1までの整数が振られている。
// 参加者の得意な手はn文字のR,P,Sからなる文字列sによって表現される。番号iの参加者の得意な手はsの(i mod n)+1文字目の文字で表現される。
// r-lが2のべき乗であるようなl,rに対し、番号がl以上、r未満ン参加者による大会を開き、r以上m未満の勝者a、m以上l未満の参加者の勝者bとすると、あいこの場合aを勝者とする。
// 方針：じゃんけんの勝敗を決めた後、勝者同士の対戦をどのようなインデックスまたはコンテナでアクセスするように制御し、
// 必要な処理：①じゃんけんの勝敗を決める→対戦番号を振ってそのインデックスを引数に渡し、そのインデックスからオフセットを考えて対戦者のインデックスを計算、勝敗を決定し、勝者のインデックスをどこかに格納
// ②対戦番号を振る処理。コンテナの利用をすると思う→方針として、対戦結果をどのように反映させるかが問題なんだけど、
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// int

int main(){
  int n,k;
  cin>>n>>k;
  string str;
  cin>>str;
  vector<char> vec(str.begin(), str.end());

  // じゃんけんの勝敗を決める処理


}