#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// resは各IDの人のそうめんの重さを保持するコンテナ
// retは列に並んでいない人の列に戻る時間(第一引数)、ID（第二引数）
// aliveは列に並んでる人のIDを保持

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin>>n>>m;

  set<pair<int ,int>> ret;
  set<int> alive;

  rep(i,n){
    alive.insert(i);
  }

  vector<long long> res(n); //intにするとエラーが出る
  while(m--){
    int t,w,s;
    cin>>t>>w>>s;
    while(!ret.empty()){
      auto it=ret.begin();
      if(it->first>t){
        break;
      }
      alive.insert(it->second);
      ret.erase(it);
    }
    if(!alive.empty()){
      auto it=alive.begin();
      res[*it]=w;
      ret.emplace(t+s,*it);
      alive.erase(it);
    }
  }

  rep(i,n){
    cout<<res[i]<<endl;
  }

  return 0;

}