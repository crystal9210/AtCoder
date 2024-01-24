#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int h,w,k,cnt=0;
  cin>>h>>w>>k;
  vector<string> grid(h);
  rep(i,0,h)cin>>grid[i];
  vector<vector<int>> sum(h,vector<int> (w,0)),dp(h,vector<int> (w,0));
  // dp初期化
  rep(i,0,h){
    rep(j,0,k){
      if(grid[i][j]=='o')cnt++;
      if(grid[i][j]=='x')cnt=0;
    }
    sum[i][k]=cnt;
    cnt=0;
  }
  rep(j,0,w){
    rep(i,0,k){
      if(grid[i][j]=='o')cnt++;
      if(grid[i][j]=='x')cnt=0;
    }
    sum[k][j]=cnt;
    cnt=0;
  }
  int max=1000000007;
  int minop=max;
  rep(i,0,h)rep(j,0,w){
    if(sum[i][j]>=k || (j>=k-1 && sum[j][j-k+1]>=k)){
      minop=min(minop,k-sum[i][j]);
    }
    if(sum[i][j]>=k || (i>=k-1 && sum[i-k+1][j]>=k)){
      minop=min(minop,k-sum[i][j]);
    }
  }

  if(minop==max){
    cout<<-1<<endl;
  }else{
    cout<<minop<<endl;
  }

  // rep(i,0,h){
  //   rep(j,0,w){
  //     if(dp[i][j]=='o'){
  //       dp[i][j]++;
  //     }
  //   }
  // }


  return 0;

}
