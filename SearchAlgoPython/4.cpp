#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
// 問:ABC洋菓子店では1個4ドルのケーキと1個7ドルのドーナツが売られている。このとき合計金額がNドルとなる買い方はあるか判定せよ。ただし、同じ商品を2個以上買ってもいい＋買わない手品があってもいい
// 制約:Nは1以上100以下の整数

// 計算量：O(n^2)

int main(){
  int n,max_cake=0,max_donut=0;
  bool ans=false;
  cin>>n;

  // 計算量:最大n/4
  while(max_cake<=n){
    max_cake+=4;
  }

  // 計算量:最大n/7
  while(max_donut<=n){
    max_donut+=7;
  }

  // 計算量はO(n^2)の範囲に収まる→2重ループのため / この計算が主計算となる
  rep(i,0,max_cake)rep(j,0,max_donut){
    if(4*i+7*j==n){
      ans=true;
      break;
    }
  }

  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

  return 0;

}
