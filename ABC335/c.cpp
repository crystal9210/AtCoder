#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 注意:頭意外のすべてのパーツは前のパーツが動いたときにそのパーツが元々あった位置に自動で移動する

int main(){
  int n,q;
  cin>>n>>q;
  vector<pair<int, int>> moves(n+1);
  int mv_cnt=0;
  while(q--){
    int type;
    cin>>type;

    if(type==1){
      char c;
      cin>>c;
      int dx=0,dy=0;

      if(c=='R')dx++;
      else if(c=='L')dx--;
      else if(c=='U')dy++;
      else if(c=='D')dy--;

      moves.push_back({dx,dy});
      mv_cnt++;
    }else if(type==2){
      int t,x=0,y=0;
      cin>>t;
      if(mv_cnt>t-1){
        rep(i,0,mv_cnt-t+1){
          x += moves[i].first;
          y += moves[i].second;
        }
        cout<<x<<" "<<y<<endl;
      }else{
        int x=t-mv_cnt,y=0;
        cout<<x<<" "<<y<<endl;
      }
    }
  }

  return 0;

}
