#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
typedef long long ll;
// 方針:bit全探索
// 問:N個の硬貨がある。番号iの硬貨はAi円。硬貨の選び方は2^N通りあるがその中で合計価格がちょうどX円になる選び方はあるか。

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a(n); // C++ではスマートポインタ（std::shared_ptr や std::unique_ptr）や、コンテナクラス（std::vector や std::string）などを利用することをお勧めします。これらの機能を使うと、メモリ管理が自動的に行われ、メモリリークのリスクが低減します。
  bool flag=false;
  rep(i,n,i++)cin>>a[i];
  // メイン処理;外側ループ:全ての硬貨の裏表の組を調べるためのループ(2^n通り)
  rep(i,0,(1<<n)){  //(1<<n)=2^n
  // bit:各組合せを表現するために利用、sum=合計金額を保持するための変数
    int bit[n],sum=0;
    rep(j,0,n){
    int div=(1<<j); //2のべき乗の計算、各硬貨の選択状態を表現
    bit[j]=(i/div)%2; // ビット列iのうち、j番目のビットを取り出し、bit[j]に保持
    }
    rep(j,0,n)sum+=a[j]*bit[j];
    if(sum==x)flag=true;
  }
  if(flag==true)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}

// 2進数変換をするアルゴリズム
void Binary(int x){
  int bit[30];
  for(int i=0;i<30;i++){
    int div=(1<<i);
    bit[i]=(x/div)%2;
  }
}
