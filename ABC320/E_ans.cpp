/**
this is the code refered to original one of uesr 'tourist'.  And the submission of this code is for the confirmation of functioning.
**/
#include <bits/stdc++.h>

using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  // 人が列に戻る予定の時間とその人のIDをペアとして格納
  set<pair<int, int>> ret;
  set<int> alive; //列に並んでいる人のIDが昇順に格納されるコンテナのインスタンス→人が列から外れる、すなはちその人のIDがaliveからretに移され、格納されるときは、そのIDはretの第二引数。
  rep(i,n){
    alive.insert(i);
  }

  //res：列のIDが一致する人がgetしたソーメンの量をその人のIDと一致するインデックスに格納する
  vector<long long> res(n); 
  while (m--) {
    int t, w, s;
    cin >> t >> w >> s;

    //ソーメンを受け取った人たちの列に戻る時間it->firstを経過時間tと比較して前者が後者より小さければ、すでに列に戻っているのでretから削除して、aliveに戻す処理。
    //☆add:retはsetであり、先頭の引数を基準にして昇順にソートしていく
    while (!ret.empty()) {
      auto it = ret.begin();  //itはイテレータ、セットの特定の要素を指すポインタのようなもの→直接要素の値にアクセスするには*を使ってデリファレンス(参照先の値を取得)する必要がある
      if (it->first > t) {
        break;
      }
      alive.insert(it->second);
      ret.erase(it);
    }
    if (!alive.empty()) {
      auto it = alive.begin();
      res[*it] += w;
      ret.emplace(t + s, *it);
      alive.erase(it);
    }
  }
  rep(i,n){
    cout << res[i] << '\n';
  }
  return 0;
}
