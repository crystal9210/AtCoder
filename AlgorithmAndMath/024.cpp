// Answer Exam Randomly
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++) 

// exe time:1ms
int main(){
  int N;
  cin>>N;

  vector<vector<int>> q(N,vector<int>(2,0));
  rep(i,N)rep(j,2)cin>>q[i][j];

  double ex=0;
  rep(i,N)ex+=(double)q[i][1]/(double)q[i][0];

  cout<<fixed<<setprecision(12)<<ex<<endl;

  return 0;
}