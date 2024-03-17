#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n,upper=10000;
  ll ans=0;
  cin>>n;
  vector<pair<char, int>> p(n);
  rep(i,0,n)cin>>p[i].first>>p[i].second;
  rep(i,0,n){
    if(p[i].first=='+'){ans+=p[i].second;
    }else if(p[i].first=='-'){ans-=p[i].second;
    }else if(p[i].first=='*'){ans*=p[i].second;
    }else{
      cout<<"your input was invalid."<<endl; return -1;
    }
    ans%=upper;
    if(ans<0)ans+=upper;  // 要件に「あまりを出力」とあるので正の値を出力するようにする必要がある
    cout<<ans<<endl;
  }

  return 0;

}
