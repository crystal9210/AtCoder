#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int N;
  cin>>N;
  vector<vector<char>> S(N,vector<char>(N));
  vector<int> num(N,0);
  vector<int> index(N);
  rep(i,N)index[i]=i+1;
  rep(i,N)rep(j,N)cin>>S[i][j];
  rep(i,N){
    rep(j,N){
      if(S[i][j]=='o'){
        num[i]++;
      }
    }
  }
  // rep(i,N)cout<<index[i]<<' ';
  // cout<<endl;
  // rep(i,N)cout<<num[i]<<' ';
  // cout<<endl;

  for(int j=0; j<N; j++){
    for(int i=j+1; i<N; i++){
      if(num[i]>num[j] || (num[i]==num[j] && index[j]>index[i])){
        swap(num[i],num[j]);
        swap(index[i],index[j]);
      }
    }
}

  rep(i,N) cout << index[i] << " ";
  cout << endl;

  return 0;
}