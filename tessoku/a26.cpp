#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// TLEする→素数判定において、時間を節約するためにはエラトステネスの篩(Slave of Eratosthenes)が有効
vector<bool> sieve(int n){
  vector<bool> prime(n+1, true);
}

// 素数判定をするための関数
bool isPrime(int n){
  rep(i,2,n)if(n%i==0)return false;
  return true;
}

int main(){
  int q;
  cin>>q;
  rep(i,0,q){
    int x;
    cin>>x;
    if(isPrime(x)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }

  return 0;

}
