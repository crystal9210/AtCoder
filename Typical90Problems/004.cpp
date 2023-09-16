// Cross Sum
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// exe time:696ms
int main(){
  int H,W;
  cin>>H>>W;

  vector<vector<int>> nums(H,vector<int>(W,0));
  vector<vector<int>> sums(H,vector<int>(W,0));
  vector<int> row_sums(H,0),column_sums(W,0);
  
  rep(i,H)rep(j,W)cin>>nums[i][j];
  rep(i,H)rep(j,W)row_sums[i]+=nums[i][j];
  rep(j,W)rep(i,H)column_sums[j]+=nums[i][j];
  rep(i,H)rep(j,W)sums[i][j]=row_sums[i]+column_sums[j]-nums[i][j];

  rep(i,H){
    rep(j,W){
      cout<<sums[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;

}