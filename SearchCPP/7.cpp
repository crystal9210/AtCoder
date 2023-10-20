// 問:N日間の気温のデータがあり、i日目の気温はAi度だった。AiがP日連続である一定の「適温」を越えるi.e.「暑い」場合、熱中症になってしまう。この時、適温としてありえる値のうち最小のものtを求めよ
// 制約:1<=P<=N<=1000,0<=Ai<=10^9,Aiは整数
// 方針:適温の最小値はAi(i=0,1,2...,n)のうち、最大となるものと最小となるものの間に存在する→Aiから適温となる温度を考える
#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;

// 「適温」をAiの中から選んで設定した変数borderを引数に渡し、
bool solve(int border,int p,int n,vector<ll>& a){
  int current_len=0;  //len=length
  rep(i,1,n){
    if(a[i]>border)current_len+=1;
    else current_len=0;
    if(current_len>=p) return false;
  }
  return true;
}

int main(){
  int n,p;
  ll ans=1000000001;  //10^9より大きければAiのうちから適温の判定ができるのでなんでもおっけー
  cin>>n>>p;
  vector<long long> a(n);
  rep(i,0,n)cin>>a[i];
  rep(i,0,n){
    if(solve(a[i],p,n,a)){
      ans=min(ans,a[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
// 参照元:https://qiita.com/e869120/items/25cb52ba47be0fd418d6#:~:text=%E6%A7%8B%E3%81%84%E3%81%BE%E3%81%9B%E3%82%93%E3%80%82-,2%2D1.%20%E5%85%A8%E6%8E%A2%E7%B4%A2%E3%81%A8%E3%81%AF,%E6%8E%A2%E7%B4%A2%E3%81%99%E3%82%8B%E3%80%8D%E3%81%A8%E3%81%84%E3%81%86%E3%81%93%E3%81%A8%E3%81%A7%E3%81%99%E3%80%82
