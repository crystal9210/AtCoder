#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 文字列sの部分列から辞書順で最小のものを出力
// 部分列：元の文字列から0個以上の文字を取り除いて残りの文字を元順序を保ったまま連結して得られる文字列。「辞書順で小さい」→問題リンク参照
// https://atcoder.jp/contests/typical90/tasks/typical90_f
int main(){
  int n,k;
  cin>>n>>k;
  string s,minsub;
  // cout<<n<<" "<<k<<endl;
  cin>>s;
  // cout<<s<<endl;
  // if(s.length()<k){
  //   cout<<""<<endl;
  //   return 0;  // 長さが k 未満の場合は何も出力しない
  // }
  vector<string> mid;
  minsub="";
  int start=0;  // 文字列の走査を開始する位置を保持
  rep(i,0,k){
    int last=n-(k-i); // 現在の反復で検討することができる最後の文字の位置を計算；残りの部分列の長さが十分であることを保証
    char minc='z'+1;  // 現在の反復で見つかった最小の文字を保持する変数の初期化
    int minpos=-1;  // mincの位置を保持する変数の初期化
    // ☆last 変数:与えられた文字列の中で、辞書順で最小の文字を選択するために走査する範囲を決定するのに使われる。この変数により、残りの部分列が必要な長さを満たすことができる範囲内で最小の文字を見つけることができる。
    rep(j,start,last+1){
      if(s[j]<minc){
        minc=s[j];
        minpos=j;
      }
    }
    minsub+=minc;
    start=minpos+1;
  }
  cout<<minsub<<endl;

  return 0;

}
