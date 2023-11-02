#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
// 問:N桁のラッキーナンバーSがある。SからN-3桁を消して残りの3桁を左から順に読んだものを暗証番号とする。暗証番号のパターン数を求めよ。
// cntが元ソースだと初期化されておらず、初期化後、ACとなった。

int main(){
  ll n,cnt=0;
  string s;
  cin>>n>>s;
  // 考えうる暗証番号について全探索
  rep(i,0,1000){
    // process:現在の暗証番号の桁数をカウントする変数、a[3]は各桁が暗証番号の候補となるiの各桁を格納ｓ
    int a[3]={(int)i/100, ((int)i/10)%10, (int)i%10},digit_count=0;
    // nはラッキーナンバーの桁数、全ての桁について走査
    rep(j,0,n){
      if(digit_count<=2 && a[digit_count]==(int)(s[j]-'0'))digit_count++;
      if(digit_count==3){
        cnt+=1;
        digit_count=0;
        break;
        }
    }
    // cout<<digit_count<<endl;
  }
  cout<<cnt<<endl;

  return 0;
}
