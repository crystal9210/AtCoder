#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;

  if (S.length() != 16) {
        std::cerr << "入力文字列は16文字" << std::endl;
        return 1;
    }
  if(S[1]%2==0 && S[3]%2==0 && S[5]%2==0 && S[7]%2==0 && S[9]%2==0 && S[11]%2==0 && S[13]%2==0 && S[15]%2==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

  return 0;

}