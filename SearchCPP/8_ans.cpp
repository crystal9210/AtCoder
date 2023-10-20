// I referred to HellKitsune's one for learning purposes.
// 問題の題意を正確にとらえることで、特定の制約の元で全探索をする範囲を大幅に省略できる問題例;ABC057-C
// 問:整数 Nが与えられます。ここで、2 つの正の整数 A,B に対して、F(A,B) を「10 進表記における、A の桁数と B の桁数のうち大きい方」と定義します。例えば、F(3,11) の値は、3 は 1 桁、11 は 2 桁であるため、F(3,11)=2 となります。2 つの正の整数の組 (A,B) が N=A×B を満たすように動くとき、F(A,B) の最小値を求めてください。
// 制約:1≦N≦10^10,Nは整数
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long LL; //LLという別名をlog longに設定
typedef pair<int, int> PII;

// 方針:一般に、入力された整数の桁数=2つの因数に分解した後の因数の桁数の和、が成立することから、nに対する因数aとしてa*a<=nなる最大のaの桁数を保持、その因数aでnを割った数numの桁数が、aの桁数以上になり、かつ、二つの因数の組のうち、その最大の桁数が最小になるような数である

int main(){
  LL n;
  cin>>n;
  LL small_factor=1;  //nに対するf(a,b)が最小となるような2つの因数の組のうち、大きさが小さいほうの因数
  for(LL a=2;a*a<=n;++a){
    if(n%a==0){
        small_factor=a;
      }
  }
  LL big_factor=n/small_factor;  // f(a,b)が最小になるような2つの因数のうち大きい因数を保持
  int ans=0;
  // f(a,b)を決定する因数の桁数を計算
  while(big_factor){
    big_factor/=10;  // numの桁数を1減らす
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
