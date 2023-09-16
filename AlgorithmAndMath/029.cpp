// Climb Stairs;漸化式問題
#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// exe time:1ms
int main(){
  int N;
  cin>>N;

  vector<long long> pattern(N,0);
  pattern[0]=1;
  pattern[1]=2;

  rep(i,N-2)pattern[i+2]=pattern[i]+pattern[i+1];

  cout<<pattern[N-1]<<endl;

  return 0;

}