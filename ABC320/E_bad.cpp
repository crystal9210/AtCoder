// 問題文：N人の人が一列に並んでいて先頭から順に1からNまでの番号が割り振られている。ここでM回、時刻Tiに量Wiのそうめんを流す。先頭の人がそのそうめんをゲットし、時刻Ti+Siに列の元の位置に戻る。ただし、誰も列に並んでいない場合、誰もそうめんをGETしない。
// 題意：M解の出来事がすべて行われたあと、それぞれの人が合計でどれだえそうめんをGETしたかを求める。
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int n,m;
  cin>>n>>m;
  // N人の人がそうめんをGETできる状態かどうかを保持する配列→並ぶまでの時間で判定すればいい
  // vector<bool> able(n,true);
  // N番目の人が列に戻るまでの時間を保持する配列、インデックス番号が列の先頭からの順番を意味、その順番の人の列に戻るまでの時間を保持
  vector<int> re_time(n,0);

  vector<int> somen_sum(n,0);

  //各試行iに対するパラメータを保持する動的ベクトルの宣言
  vector<int> W(m),S(m),T(m),padding_time(m);

  //入力
  rep(i,m){
    cin>>T[i]>>W[i]>>S[i];
  }
  rep(i,m-1){
    padding_time[i+1]=T[i+1]-T[i];
  }
  // rep(i,m)cout<<T[i]<<' '<<W[i]<<' '<<S[i]<<endl;


  // そうめんを流した時、そうめんをGETするときの処理

  //列の一番前の人の前からの順番の位置を保持
  int first=-1;
  // 前回のイベントの時刻を保持
  int pre_time=0;
  rep(i,m){ // whileループで操作を繰り返す

    //列に人がいるかどうかを判定
    rep(j, n) {
      if (re_time[j] <= padding_time[i]) {
        first=j;
        break;  //判定のループを抜ける
      }
    }

    //列の一番前の人のデータの更新と他の人のデータの更新
    rep(j,n){
      if(j!=first && re_time[j]>0){
        re_time[j] -= padding_time[i];
        if(re_time[j] < 0) re_time[j] = 0;
      }
    }
    if(first!=-1){
      somen_sum[first]+=W[i];
      re_time[first]=S[i];
    }

    // i回目の処理の最後に次のループのために必要な媒介変数の更新
    pre_time=T[i];
    first=-1;
  }

  //結果の出力
  rep(i,n) cout << somen_sum[i] << endl;


  return 0;

}




//以下デッドコード


      // j番目以外の人のデータを更新
    //   rep(l, n) {
    //     if (re_time[l] > 0 && l != j && i >= 1) {
    //       re_time[l] -= (T[i] - T[i - 1]);
    //     }
    //     if (re_time[l] < 0) {
    //       re_time[l] = 0;
    //     }
    //   }
    //   i++; // iをインクリメント
      
    // }

    // if (!operation_done) {
//     // もし操作が一度も行われなかった場合、iをインクリメントして次の操作に進む
//     // j番目以外の人のデータを更新
//       rep(l, n) {
//         if (re_time[l] > 0 && i >= 1) {
//           re_time[l] -= (T[i] - T[i - 1]);
//         }
//         if (re_time[l] < 0) {
//           re_time[l] = 0;
//         }
//       }
//     i++;
//     operation_done=false;
//   }

//   }
// }

  //出力
//   rep(i,n)cout<<somen_sum[i]<<endl;

//   return 0;

// }