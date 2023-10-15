// this is the code I reffered to from SSRS for learning purposes.
#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> S(N), C(N);
  for (int i = 0; i < N; i++){
    cin >> S[i] >> C[i];
  }
  map<int, long long> mp;
  for (int i = 0; i < N; i++){
    int k = __builtin_ctz(S[i]);  //__builtin_ctzは、整数の最も下位の1の位置（0-based）を返すGCC組み込み関数:例えばS[i]=8の時、8=1000_[2]より、3を返す。
    mp[S[i] >> k] += (long long) C[i] << k;
  }
  int ans = 0;
  for (pair<int, long long> P : mp){
    ans += __builtin_popcountll(P.second);  //__builtin_popcountll:引数のビット数中の1の数を数える関数
  }
  cout << ans << endl;
}

// 同じサイズグループのスライムの数を集計する：
// サイズ128のスライムは、2の7乗であり、サイズ2のスライムが64匹分存在することを意味する。したがって、正確にはサイズ2のスライムが100 + 64 = 164匹存在することになる。
// 再度、164を2進数で表すと、10100100になる。これをもとに、どのサイズのスライムがいくつ生成されるのかを判断できる。





