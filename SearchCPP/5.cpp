#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)

// 問:

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> min(n,0),s(m,0),c(m,0),cnt(n,0);
  // rep(i,0,n)cout<<min[i];
  // cout<<endl;
  rep(i,0,m)cin>>s[i]>>c[i];
  bool flag=false;
  rep(i,0,m){
    if(s[i]==1 && c[i]>=1){
      flag=true;
    }
  }
  if(flag==false){
    cout<<-1<<endl;
    return 0;
    }
  if(n==1){
    min[0]=c[0];
    rep(i,0,m){
      if(min[0]>c[i])min[0]=c[i];
    }
    cout<<min[0]<<endl;
    return 0;
  }

  // n=2,3のケース
  rep(i,0,m){
    int a=s[i]-1,b=c[i];
    // cout<<a<<' '<<b<<endl;
    if(a!=0 && cnt[a]==0){
      min[a]=b;
      cnt[a]+=1;
    }
    if(a==0 && cnt[a]==0){
      if(b>0){
        min[0]=b;
        cnt[a]+=1;
      }else{
        continue;
      }
    }
    if(cnt[a]==1 && a==0 && b>0 && min[0]>b)min[a]=b;
    if(cnt[a]==1 && a!=0 && min[a]>b)min[a]=b;
  }
  rep(i,0,n)cout<<min[i];
  cout<<endl;

  return 0;

}
