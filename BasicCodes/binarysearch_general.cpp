// std::lower_bound()　→　a[index]>=keyを満たす最小の index を見つけたい

#include <bits/stdc++.h>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// index が条件を満たすかどうか
bool isOK(int mid_index, int key){
  if(a[mid_index]>=key)return true; // これはmid_indexの値より求めたいkeyが前のインデックスにあることを意味
  else return false;
}

// 汎用的な二分探索のテンプレ関数
int binary_search(int key){
  int left=-1;
  int right=(int)a.size();

  // 二分探索によらず同じ書き方ができる
  while(right-left>1){
    int mid=left+(right-left)/2; // a/2について、端数は切り捨てなので、right-left<=0となる可能性はない
    if(isOK(mid,key))right=mid; // この時、right>mid>leftに注意して、rightをleftに寄せている
    else left=mid;
  }
  // なぜこのロジックで書くのか→参照先：https://algo-logic.info/binary-search/

  // left：条件を満たさない最大の値、right：条件を満たす最小の値
  return right;
}

int main(){
   cout << binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10 (場外)
}
