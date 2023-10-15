#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// 問題：N曲から成るプレイリストについて、曲iの長さはTi秒。プレイリストをランダム再生する。同じ曲が連続して選ばれることもある。
// 題意：時刻0から(X+0.5)秒語に曲1が再生されている確率をmod998244353で求めよ。
// →方針：
// ①A=998244353とすると、この時、問題の制約から、確率は(double)z/(double)Aとして表現される
// ②確率を求める。

int main(){
  int n,x;
  cin>>n>>x;
  x+=0.5;
  vector<int> t(n,0);
  rep(i,n)cin>>t[i];




}
