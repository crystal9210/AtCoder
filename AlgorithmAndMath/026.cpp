// Coin Gacha
#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=1;i<=(x);i++)

// exe time:2ms
int main(){
  int N;
  cin>>N;

  double ex=0;
  rep(i,N)ex+=((double)N/(double)i);

  cout<<fixed<<setprecision(12)<<ex<<endl;

  return 0;

}