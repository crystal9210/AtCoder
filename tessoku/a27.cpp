#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;


// ユークリッドの互除法によるGCDの計算
// 一般式を関数にするだけ
int gcd(int a,int b){
    while(b!=0){
      int r=a%b;
      a=b;
      b=r;
    }
    return a;
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;

    return 0;
}
