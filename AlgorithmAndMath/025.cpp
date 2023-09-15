// Jiro's Vacation
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// exe time:41ms
int main(){
  int N;
  cin>>N;

  vector<vector<int>> studytime(2,vector<int>(N,0));
  rep(i,2)rep(j,N)cin>>studytime[i][j];

  double sum=0;

  rep(j,N)sum+=((double)studytime[0][j]/(double)3);
  rep(j,N)sum+=((double)studytime[1][j]*2/(double)3);

  cout<<fixed<<setprecision(12)<<sum<<endl;

  return 0;

}