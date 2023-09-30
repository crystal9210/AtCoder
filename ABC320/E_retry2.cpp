#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)
//this code is TLE*4 AC*37 result:TLE.

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  // N番目の人が列に戻るまでの時間を保持する配列、インデックス番号が列の先頭からの順番を意味、その順番の人の列に戻るまでの時間を保持
  set<pair<int,int>> re_time;  //第一引数には戻るまでの時間、第二引数にはID

  vector<long long> somen_sum(n,0);
  vector<bool> is_in_line(n,true);

  // そうめんを流した時、そうめんをGETするときの処理
  while(m--){ // whileループで操作を繰り返す
    int t, w, s;
    cin >> t >> w >> s;

    //列に人がいるかどうかを判定/ab_indi=absent individual
    while(!re_time.empty()){
      auto ab_indi=re_time.begin();
      if(ab_indi->first>t){
        break;  //re_timeに登録されている個人は第一引数の、列に戻る時間が昇順になっているので、順にみていってある個人でT[i]より戻る時間が後だと、それ以降の全員はT[i]で列に戻ってない
      }
      is_in_line[ab_indi->second]=true;
      re_time.erase(ab_indi);
    }

    //ここでループ処理使うとTLEになる
    rep(i,n){
      if (is_in_line[i]) { 
        somen_sum[i]+=w;
        re_time.emplace(s+t,i);
        is_in_line[i]=false;
        break;
      }
    }
    
  }

  //結果の出力
  rep(i,n) cout << somen_sum[i] << endl;


  return 0;

}