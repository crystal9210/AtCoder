#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// TLEする→素数判定において、時間を節約するためにはエラトステネスの篩(ふるい)(Slave of Eratosthenes)が有効
vector<bool> sieve(int n){
  vector<bool> prime(n+1, true);  // 初期状態ではすべての数が素数と仮定している
  prime[0] = prime[1] = false; // 0と1は素数ではない
  // 2から始めてnの平方根までの範囲を検討→検討範囲を大幅に小さくする(これでいいらしい)
    for(int i = 2; i*i <= n; ++i) {
      // iが素数のときのみ実行するようにすることで正確に非素数を排除
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false; // iの倍数を非素数とマーク
            }
        }
    }
    return prime;
}

// この関数を利用するとTLEとなり×
// 素数判定をするための関数
// bool isPrime(int n){
//   rep(i,2,n)if(n%i==0)return false;
//   return true;
// }

int main(){
  int q;
  cin>>q;
  vector<bool> prime=sieve(300000);
  rep(i,0,q){
    int x;
    cin>>x;
    if(prime[x]){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }

  return 0;

}
