#include <bits/stdc++.h>
using namespace std;

// exe time:1ms

int main(){
  int X;
  cin>>X;
  vector<bool> is_power_num(X+1,false);
  is_power_num[1]=true;
  //2以上X以下のべき乗数のインデックス番号に一致するis_power_num配列のインデックスのbool値を全てtrueにする
  for(int b=2;b<=X;b++){
    int v=b*b;
    while(v<=X){
      is_power_num[v]=true;
      v*=b;
    }
  }

  //X未満のis_power_numのインデックスでtrueなもののうちインデックス番号が最大のものを出力し、終了
  for(int i=X;i>=1;i--)if(is_power_num[i]){
    cout<<i<<endl;
    return 0;
  }
}