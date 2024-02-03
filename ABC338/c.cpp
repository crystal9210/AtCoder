#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int cntmeal(const vector<int>& q, vector<int>& a, const vector<int>& b){
  int n = q.size();
   vector<vector<int>> dp(n+1, vector<int>(10001, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            if (dp[i][j] == -1) continue;

            // 料理Aに材料を割り当てる
            if (j + a[i] <= 10000) {
                dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]], dp[i][j]);
            }

            // 料理Bに材料を割り当てる
            if (b[i] > 0) {
                int mealsB = min(q[i] / b[i], dp[i][j] + (q[i] - dp[i][j] * b[i]) / a[i]);
                dp[i+1][j] = max(dp[i+1][j], mealsB);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 10000; ++j) {
        ans = max(ans, dp[n][j]);
    }

    return ans;
}

int main(){
  int n;
  cin>>n;
  vector<int> q(n),a(n),b(n);
  rep(i,0,n)cin>>q[i];
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)cin>>b[i];
  int ans=cntmeal(q,a,b);
  cout<<ans<<endl;

  return 0;

}
