// Dice Expectation
#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<(x);i++)
#define dice_num 2

// exe time:21ms

int main(){
  int n;
  cin>>n;

  vector<vector<int>> input(2,vector<int>(n,0));
  rep(i,dice_num)rep(j,n)cin>>input[i][j];

  int sum=0;
  rep(i,dice_num)rep(j,n)sum+=input[i][j];

  double ex=(double)sum/(double)n;

  cout<<fixed<<setprecision(12)<<ex<<endl;

  return 0;
}