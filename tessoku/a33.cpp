#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

//対称・非対称がどういうことを意味しているか：☆ゴールがすべての石がなくなったとき→先手が対称な状態だと後手が先手が次に取るときに常にxorSum=0となるように取ることで確実に先手の番で0を実現→最後すべての石がなくなった状態で先手の番がくる
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int xorSum=0;
  rep(i,0,n){
    cin>>a[i];
    xorSum^=a[i]; // 各山の石の数のXORを計算→☆原理はl:27以降
  }

  if(xorSum!=0){
    cout<<"First"<<endl;
  }else{
    cout<<"Second"<<endl;
  }

  return 0;

}
// 【原理】
// Nimゲームにおいて、全ての山の石の数をXORした結果が0でない場合、これは少なくとも1つのビット位置において1の数が奇数であることを意味。これは、ゲームの現在の状態が非対称であることを示していて、先手は次の一手でこの非対称性を利用して、XORの結果を0にすることができる「有利な」手を打つことができる。
// 具体的には、XORの結果が0でない場合、先手は適切な山から適切な数の石を取り除くことで、全体のXORの結果を0に変更することが可能。XORの結果を0にすることで、先手はゲームを「対称な」状態に持ち込む。この対称な状態では、後手がどのような手を打っても、XORの結果を0以外に変えざるを得なくなり、結果的に先手が再びXORの結果を0に戻すことができる手を打つことができるようになる。
