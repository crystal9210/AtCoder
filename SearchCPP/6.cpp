#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
// 問:1からNまでの数の中から重複なしで3津の数を選び、合計がxとなるような場合の数を求めよ。
// 方針:合計の数と、用いる数が3個と決まっているなら、x+y+z=a(aは合計の数かつ定数)として、x,yの2つの数だけ決定すればzは自動的に求まる(自由度-1)
// 解法における注意点:下のループでは、kの定義上、kとjが互いに対称な場合を含んでしまう(重複)→j<kまたはj>Kという制約を加えることにより一意性を保証する
int main(){
  int n,x,ans=0;
  cin>>n>>x;
  rep(i,1,n+1)rep(j,i+1,n+1){
    int k=x-i-j;
    if(j<k && k<=n)ans+=1;
  }
  cout<<ans<<endl;

  return 0;
}
