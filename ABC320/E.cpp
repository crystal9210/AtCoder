// 問題文：N人の人が一列に並んでいて先頭から順に1からNまでの番号が割り振られている。ここでM回、時刻Tiに量Wiのそうめんを流す。先頭の人がそのそうめんをゲットし、時刻Ti+Siに列の元の位置に戻る。ただし、誰も列に並んでいない場合、誰もそうめんをGETしない。
// 題意：M解の出来事がすべて行われたあと、それぞれの人が合計でどれだえそうめんをGET下かを求める。
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int n,m;
  cin>>n>>m;
  // N人の人がそうめんをGETできる状態かどうかを保持する配列→並ぶまでの時間で判定すればいい
  // vector<bool> able(n,true);
  // N番目の人が列に戻るまでの時間を保持する配列、インデックス番号が列の先頭からの順番を意味、その順番の人の列に戻るまでの時間を保持
  vector<long long> re_time(n,0);

  vector<long long> somen_sum(n,0);

  vector<long long> passed_time(n,0);

  //各試行iに対するパラメータを保持する動的ベクトルの宣言
  vector<long long> W(n),S(n),T(n);

  //入力
  rep(i,m){
    cin>>T[i]>>W[i]>>S[i];
  }


  // そうめんを流した時、そうめんをGETするときの処理
  rep(i,n){
    rep(j,n){
      if(re_time[j]==0){
        //j番目の人のデータを更新
        re_time[j]+=S[i];
        somen_sum[j]+=W[i];
        
        //j番目以外の人のデータを更新
        rep(l,n){
          if(re_time[l]>0 && j!=i && i>=1){
            re_time[l]-=(T[i]-T[i-1]);
          }
          if(re_time[l]<0){
            re_time[l]=0;
          }
        }
      }
    }
  }

  //出力
  rep(i,n)cout<<somen_sum[i];

  return 0;

}