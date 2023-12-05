#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// https://atcoder.jp/contests/abc132/tasks/abc132_d
// 解法:組み合わせの利用。今回は特に、k個を分割する事のみに着目するので、その組み合わせk-1Ci-1を考える。i-1<=n-kであることに注意。また、
// 青ボール:k個、赤ボール:n-k個
// 条件を満たす数値(組み合わせ)を求めるためのユーザ定義関数
void comb(vector<vector<ll>> &v){
  // v[i][j]=jCiを意味→0<=i<=j
  rep(i,0,(int)v.size()){
    v[i][0]=1;
    v[i][i]=1;
  }
  rep(i,1,(int)v.size())rep(j,0,i){
    v[i][j]=(v[i-1][j-1]+v[i-1][j])%1000000007;
  }
}

int main(){
  int n,k;
  cin>>n>>k;
  // 今回はnClに対し、n=k-1,l=i(i<=k-1)の場合を考えるため
  // k-1⋚=n-kで場合わけ→出力する値がmin(n-k,k)により、結局dpとして、利用する組み合わせの値を求めるためのiのループがmin(n-k,k)に等しい場合までなのでその最小値を最初に求めて利用する
  int t=min(n-k,k),s=max(n-k,k);
    vector<vector<ll>> v(s,vector<ll>(t,0));
    comb(v);
    rep(i,1,t){
      cout<<v[k-1][i-1]*v[n-k-i][i-1]<<endl;
    }
  return 0;

}
