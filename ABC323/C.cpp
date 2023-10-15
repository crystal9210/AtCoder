#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int n,m,top=0;
  cin>>n>>m;
  // a(i)はi問目の得点を保持する動的配列,b(i)は半分の時間が過ぎた時点でのプレイヤーiの得点,restはプレイヤーが全プレイヤーの得点の最大値topを上回るために解く最低の問題数
  vector<int>a(n),b(n),rest(n);
  rep(i,n)b[i]+=i;
  vector<vector<bool>> is_resolved(n,vector<bool>(m,false));
  vector<vector<char>> s(n,vector<char>(m));
  rep(i,m)cin>>a[i];
  rep(i,n)rep(j,m)cin>>s[i][j];
  rep(i,n)rep(j,m){
    if(s[i][j]=='o'){
      is_resolved[i][j]=true;
    }
  }
  rep(i,n)rep(j,m){
    if(s[i][j]=='o'){
      b[i]+=a[j];
    }
  }
  // 半分の時間が過ぎた時点で最も得点が高いプレイヤーの得点をtopに格納
  rep(i,n){
    if(top<b[i]){
      top=b[i];
    }
  }

  //各プレイヤーに対し処理
  rep(i, n) {
    //まず、プレイヤーiの初期得点を取得
    int current_score = b[i];
    //解いていない問題を点数の高い順にソートするための配列の生成
    vector<int> unresolved_problems;
    rep(j, m) {
      if (!is_resolved[i][j]) {
        unresolved_problems.push_back(a[j]);
      }
    }
    //高い点数の問題から順にソート
    sort(unresolved_problems.rbegin(), unresolved_problems.rend());

    //必要な問題数を計算
    int needed = 0;
    while(current_score < top && !unresolved_problems.empty()) {
      current_score += unresolved_problems[0]; //最も高い得点の問題を追加
      unresolved_problems.erase(unresolved_problems.begin());
      needed++;
    }

    //必要な問題数をrest配列に格納
    rest[i] = needed;
  }

  //結果の出力
  rep(i, n) {
    cout << rest[i] << endl;
  }

  return 0;

}
