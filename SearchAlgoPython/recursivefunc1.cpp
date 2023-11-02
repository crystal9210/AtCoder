#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 再帰関数を用いた全探索
// https://atcoder.jp/contests/abc165/tasks/abc165_c
// 問:正整数n,m,qおよび4つの整数の組(ia,bi,ci,di)がq個与えられる。以下の条件を満たす数列aを考える。

// 特定の長さnに対し、各桁1以上m以下の範囲の数値を含む増加するシーケンス(数列)を生成するための再帰関数
void generateIncreasingSequences(int n, int m, int last,int &max_points,
                                 vector<int> &sequence,vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
  if (sequence.size() == n) {
    // ここでsequenceにはn桁の増加的な整数が格納されている、出力や他の用途のために利用できる
    int each_points=0;
    rep(i,0,a.size()){
      if(sequence[b[i]-1]-sequence[a[i]-1]==c[i]){
        each_points+=d[i];
      }
    }
    max_points=max(max_points,each_points);
    return;  // ここできちんとreturnしないと値の更新と、
  }

  rep(i, last, m + 1) {
    sequence.push_back(i); // 現在の文字をシーケンスに追加
    generateIncreasingSequences(n, m, i, max_points, sequence,a,b,c,d);
    sequence.pop_back();
  }

}

int main(){
  int n,m,q;
  cin>>n>>m>>q;
  // 生成した条件を満たすような数列を保持する配列;数列の各桁ごとの制約1<=ai<=mをどのようにして実現するか
  vector<int> A;  // 数列を動的に保持するための配列
  vector<int> a(q),b(q),c(q),d(q);
  rep(i,0,q)cin>>a[i]>>b[i]>>c[i]>>d[i];

  // 下のループ処理で走査する整数群の上限となる整数の生成とループを走査するために利用するカウンタ変数
  int max_points=0;
  generateIncreasingSequences(n,m,1,max_points,A,a,b,c,d);

  cout<<max_points<<endl;

  return 0;
}
