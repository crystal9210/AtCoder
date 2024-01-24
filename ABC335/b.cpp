#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
  int n;
  cin>>n;
  vector<tuple<int, int, int>> comb;

  for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (i + j + k <= n) {
                    comb.push_back(std::make_tuple(i, j, k));
                }
            }
        }
    }

  sort(comb.begin(),comb.end());
  for(auto &com:comb){
    cout<<get<0>(com)<<" "<<get<1>(com)<<" "<<get<2>(com)<<endl;
  }

  return 0;

}
