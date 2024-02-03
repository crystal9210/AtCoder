#include <iostream>
#include <vector>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

// 前方宣言
class Container;

class Iterator {

  private:
  const Container& c;
  int index;

  public:
  Iterator(const Container& container, int startIndex);

  // 内部関数

  // イテレータを次の要素に進める
  Iterator& operator++(); // l:

  // イテレータが指す要素を返す
  int operator*() const;

  // イテレータの等価性をチェック
  bool operator!=(const Iterator& other) const;

};

class Container {
  public:
  int* data; // コンテナのデータ配列
  int size;

  Container(int size): size(size),data(new int[size]) {
    // コンテナの初期化(この形式で普通初期化せんやろw)
    rep(i,0,size){
      data[i]=i;
    }
  }

  // デストラクタ；Containerオブジェクトが破棄される際、動的に確保された配列dataを解法する。これによりメモリリークを防ぐ(vectorならなくておっけー。今回は実装するために静的配列を利用)
  ~Container() {
    delete[] data;
  }

  Iterator begin() const {
    return Iterator(*this, 0);
  }

  // コンテナ―の最後の要素の次を指すイテレータを返す；C++での標準ライブラリでのイテレーションの慣習に従い、この終端イテレータはコンテナの要素範囲の外にある
  // const:end関数がmain関数内でインスタンス名.end()としたときのインスタンスに対し内部的な変更を加えることを不可とすることを意味
  Iterator end() const {
    return Iterator(*this, size);
  }
};

// クラス間の共依存関係によるコンパイルエラーを避けるため、イテレータクラスの具体的な各関数の処理実装は外部定義
// const:変更不可
Iterator::Iterator(const Container& container, int startIndex) : c(container), index(startIndex) {}
// ☆:参照型メンバ変数、constメンバ変数はそれぞれ初期化リストを使用して初期化しなければならない。コンストラクタの初期化の本体中では不可

Iterator& Iterator::operator++() {
    ++index;
    return *this;
}

int Iterator::operator*() const {
    return c.data[index];
}

// Iteratorクラスの二つのインスタンスが異なる要素を指しているかどうかを判断するためにオーバーロードされた
bool Iterator::operator!=(const Iterator& other) const {
    return index != other.index;
}


int main(){
  int n;
  cout<<"please determine the size of a container you will make:";
  cin>>n;
  Container container(n);
  for(Iterator it=container.begin();it!=container.end();++it){
    cout<<*it<<" ";
  }

  cout<<endl;

  return 0;

}

// C++のイテレータがインデックスン最後尾+1までアクセスできる理由:イテレーションの終了条件を表現するため
