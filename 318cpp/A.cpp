#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,p;
  cin>>n>>m>>p;
  int res=0;
  while(m<=n){
    res++;
    m+=p;
  }
  cout<<res<<endl;
  return 0;
}