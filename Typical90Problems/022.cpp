// Cubic Cake
#include <bits/stdc++.h>
using namespace std;

// exe time:1ms
long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
    //bが0でない、つまり真ならば、gcd(b, a%b)を返し、0つまり偽ならばaを返す
}


int main(){
  long long A,B,C;
  cin>>A>>B>>C;

  long long g=gcd(C,gcd(A,B));
  long long ans=(A+B+C)/g-3;

  cout<<ans<<endl;

  return 0;

}