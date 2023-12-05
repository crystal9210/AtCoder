#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 問:n個のアトラクション、i個目のアトラクションの楽しさの初期値ai、高橋のアトラクションに乗れる回数k回、満足度にアトラクションiの現在の楽しさが加算される、iコメのアトラクションの楽しさが1減少
// 求:高橋の満足度の最大値max

// メイン処理をするための再帰関数
void maxSatisfying(int n,int k,int* max,vector<int>* fun){
  // k回目までのアトラクションに乗った満足度を計算し保持するための配列
  vector<vector<int>> dp(k,vector<int>(n,0));


};
int main(){
  int n,k,max=0;
  cin>>n>>k;
  vector<int> fun(n,0);
  rep(i,0,n)cin>>fun[i];
  // funが保持する要素を昇順に並び替え
  sort(fun.begin(),fun.end());
  // 下の実装方針だと、uti--;が2以上、3以上と大きくなっていったときに一気にutiを飛ばす先として選択肢が線形に増えていき、結果としてループごとの比較回数が指数関数的に増加するので×。
  // int uti=n-1;
  // while(k>0){
  //   k--;
  //   max+=fun[uti];
  //   fun[uti]--;
  //   if(fun[uti]<fun[uti+1] && uti+1<n){
  //     uti++;
  //   }else if(uti-1>=0 && fun[uti]<fun[uti-1] && fun[uti-1]>fun[uti+1]){
  //     uti--;
  //   }else if(){

  //   }
  // }
  cout<<max<<endl;

  return 0;

}
