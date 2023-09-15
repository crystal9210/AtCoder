// Sorting
#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<(x);i++)

// exe time:73ms
int main(){
  int N;
  cin>>N;

  vector<int> nums(N,0);
  rep(i,N)cin>>nums[i];
  sort(nums.begin(),nums.end());

  for(int i:nums)cout<<i<<" ";
  cout<<endl;

  return 0;

}