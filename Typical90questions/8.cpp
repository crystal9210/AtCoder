#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 動的計画法？

const int MOD=1e9+7;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  string t="atcoder";
  vector<ll> dp(t.size()+1,0);
  dp[0]=1;

  for(char i:s)for(int j=t.size()-1;j>=0;j--){
    if(i==t[j]){
      dp[j+1]+=dp[j];
      dp[j+1]%=MOD;
    }
  }
  cout<<dp[t.size()]<<endl;

  return 0;

}
