#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc216/tasks/abc216_d
// 参照元:https://atcoder.jp/contests/abc216/submissions/25413352
// 方針:dagかトポロジカルソート
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m,cnt=0;
  cin>>n>>m;
  vector<vector<int>> tubes(m),colors(n+1);

  // 下のループ内の処理の関数化
  function<void(int)> removeballs=[&](int i){
    int color=tubes[i].back();
    colors[color].push_back(i); // colorsはボールの番号をインデックスとして、各番号のボールがどの筒に入っているのか、その値をそれぞれインデックスごとに格納
    // ☆colors[color]に保持される要素数は各筒の最上位にあるボールが入っている筒の番号、そして、colorsのcolorはそのボール自身の番号を指示
    if(colors[color].size()==2){
      cnt++;
      for(auto j:colors[color]){
        tubes[j].pop_back();
        if(!tubes[j].empty()){
          removeballs(j);
        }
      }
    }
  };
  rep(i,0,m){
    int k;
    cin>>k;
    tubes[i].resize(k);
    rep(j,0,k){
      cin>>tubes[i][j];
      tubes[i][j]--;  // インデックスの調整の反映
    }
    reverse(tubes[i].begin(),tubes[i].end()); // 問題文の指示が、tubes[i]に格納されるボールの色(番号)を逆順するようになっているので調整
    removeballs(i); // i:筒の番号
  }

  cout<<(cnt==n?"Yes":"No")<<endl;

  return 0;

}
