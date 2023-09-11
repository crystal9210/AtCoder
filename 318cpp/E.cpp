#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// g++ -std=c++17 E.cpp -o out
// If you descript the line 21 as 'p.size()', you can compile with 'g++ E.cpp -o out' command.ちなみに、p.size()の方が若干早いし、メモリも少ない


int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  vector<vector<ll>> pos(N);
  for(int i=0;i<N;++i){
    cin>>a[i];
    --a[i];
    pos[a[i]].push_back(i);
  }
  ll res=0;
  for(auto p:pos){
    ll n=size(p);
    for(int m=0;m<n-1;++m){
      res+=(p[m+1]-p[m]-1)*(m+1)*(n-(m+1));
    }
  }
  cout<<res<<endl;
}