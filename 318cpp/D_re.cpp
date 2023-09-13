#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for (int i=0;i<(x);i++)

//

int main(){
  int n;
  cin>>n;

  vector<vector<int>> d(n,vector<int>(n,0));
  rep(i,n){
    for(int j=i+1;j<n;j++)cin>>d[i][j]; //各頂点の重み付き問題かな...?
  }

  // dp:1からNまでの頂点が選択されている、されていない、の2^Nの状態を保持するための配列
  vector<long long> dp(1<<n,0ll); //1<<n:要素数、2^(n-1) / 0ll:long long型の値0で全要素を初期化 

  //bは000...0から000...01,000...10,000...11,...と増えていき、最後には111...1となる、書き出すとわかるが、(1<<n)-1はバイナリ値表記したときに、1がn個並んだ数値
  rep(b,(1<<n)-1){
    int l=-1;
    //bをバイナリ値としてi=0からインクリメントしつつ各ループで、iだけ右シフトしていって最初に見つかった一の位が0のインデックスiをlに代入
    rep(i,n)if(!(b>>i&1)){
      l=i;
      break;
    }
    rep(j,n) if(!(b>>j&1)&&j!=l){
      int res=b | (1<<l) | (1<<j); //bをバイナリ値にして、そのバイナリ値のlとiの桁の数値を0から1に変更した結果をres(=result)に代入
      dp[res]=max(dp[res],dp[b]+d[l][j]); //dp[b],dp[res]の初期値は0llなはず。例えば、res=30=11110_[2]の場合、その前の状態として、b=10100,11000,10010,01110,01010,00110があるがそれぞれの状態からresになるのにd[l][j]を選ぶ必要があり、それらのうち、dp[res]が最大値をとるような前状態bとそれに対応するl,jが選択され、dp[res]に保存される。これを再帰的に繰り返してdpは最大値を格納する役割を果たす
    }
}

// if (n % 2 == 0) {
//     cout << dp.back() << endl; // 偶数の場合は、最後の要素が最大値
// } else {
//     cout << *max_element(dp.begin(), dp.end()) << endl; // 奇数の場合は、dpの中の最大値を取得
// } 下のコードでおっけー
  cout<<dp.back()<<endl;

}
