#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,q,sum1=0,sum2=0;
  cin>>n;
  vector<int> c(n+1),p(n+1),dp1(n+1),dp2(n+1);
  rep(i,1,n+1)cin>>c[i]>>p[i];
  // rep(i,1,n+1)cout<<c[i]<<' '<<p[i]<<endl;
  rep(i,1,n+1){
    if(c[i]==1){
      sum1+=p[i];
      dp1[i]=sum1;
    }else{
      dp1[i]=dp1[i-1];
    }
    if(c[i]==2){
      sum2+=p[i];
      dp2[i]=sum2;
    }else{
      dp2[i]=dp2[i-1];
    }
  }
  cin>>q;
  vector<int> l(q),r(q);
  rep(i,0,q){
    cin>>l[i]>>r[i];
    l[i]--;
    }
  rep(i,0,q)cout<<(dp1[r[i]]-dp1[l[i]])<<' '<<(dp2[r[i]]-dp2[l[i]])<<endl;

  return 0;

}
