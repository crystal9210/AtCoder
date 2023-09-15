// Frog1
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// exe time:15ms
int main(){
  int N;
  cin>>N;

  vector<int> height(N,0),cost(N,0);
  rep(i,N)cin>>height[i];

  cost[1]=abs(height[1]-height[0]);

  rep(i,N-2)cost[i+2]=min(cost[i+1]+abs(height[i+2]-height[i+1]),cost[i]+abs(height[i+2]-height[i]));

  cout<<cost[N-1]<<endl;

  return 0;

}