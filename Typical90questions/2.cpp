#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/typical90/submissions/49009976

int main(){
  int n;
  cin>>n;
  vector<string> ans;

  auto dfs=[&](auto dfs, int k, int l, string s) -> void {
    if(s.size()==n){
      ans.push_back(s);
      return;
    }
    // l:現在生成している(の個数を保持→直下行の判定文をl<=n/2とするとこのときn%2==0に注意して2種類の括弧の個数が合わなくなり×
    if(l<n/2){
      dfs(dfs,k+1,l+1,s+'(');
    }
    if(k>0){
      dfs(dfs,k-1,l,s+')');
    }
    return; // 処理が終了すると呼び出し元に戻るようになっているのでいらない
  };

  string s={};
  if(n%2==0){
    dfs(dfs,0,0,s);
  }
  for(auto st:ans){
    cout<<st<<endl;
  }

  return 0;

}
