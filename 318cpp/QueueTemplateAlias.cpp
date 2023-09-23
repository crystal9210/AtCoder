#include <bits/stdc++.h>
using namespace std;

//優先度付きキューのエイリアスのテンプレートの定義
template<class T>
using _pq = priority_queue<T, vector<T>, greater<T>>;


int main(){
  //int型の要素を持つ_pqのインスタンスを宣言
  _pq<int> min_heap;

  min_heap.push(5);
  min_heap.push(2);
  min_heap.push(8);

  int min_element=min_heap.top();
  cout<<"最小値："<<min_element<<endl;

  min_heap.pop();

  min_element=min_heap.top();
  cout<<"新しい最小値:"<<min_element<<endl;

  return 0;

}

//defineマクロを使用した場合↓
// #include <iostream>
// #include <queue>
// #include <vector>

// #define _pq std::priority_queue

// int main() {
//     // int 型の要素を持つ _pq（優先度付きキュー）を宣言
//     _pq<int, std::vector<int>, std::greater<int>> min_heap;

//...(略)
//     return 0;
// }
