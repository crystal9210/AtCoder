// quoted from https://qiita.com/drken/items/97e37dd6143e33a64c8c
// 2分探索→ソート済み配列の中から目的のものを探す
#include <iostream>
#include <vector>
using namespace std;

vector<int> a={1, 14, 32, 51, 51, 243, 419, 750, 910};

// 目的の値keyのindexを返すようにする(ない⇔-1)
int binary_search(int key){
  int left=0, right=(int)a.size()-1;  // それぞれ配列aの左側、右側のインデックス
  while(right>=left){
    int mid=left+(right-left)/2;  // 区間の真ん中
    if(a[mid]==key) return mid;
    else if (a[mid]>key) right=mid-1;
    else if (a[mid]<key) left=mid+1;
  }
  return -1;
}

int main(){
  cout<<binary_search(51)<<endl;
  cout<<binary_search(1)<<endl;
  cout<<binary_search(910)<<endl;

  cout<<binary_search(52)<<endl;
  cout<<binary_search(0)<<endl;
  cout<<binary_search(911)<<endl;
}
