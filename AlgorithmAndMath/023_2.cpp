// Dice Expectation
#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<(x);i++)
#define dice_num 2

// exe time:21ms
int main(){
  int n;
  cin>>n;

  vector<int> B(n,0),R(n,0);
  rep(j,n)cin>>B[j];
  rep(j,n)cin>>R[j];

  int b_sum=0;
  int r_sum=0;

  rep(j,n)b_sum+=B[j];
  rep(j,n)r_sum+=R[j];

  //b_exにdoubleを入れるにはaからbを割る前に両者をdoubleに変換する必要がある
  double b_ex=(double)b_sum/(double)n;
  double r_ex=(double)r_sum/(double)n;

  cout<<fixed;
  cout<<setprecision(12)<<(b_ex+r_ex)<<endl;

  return 0;
}