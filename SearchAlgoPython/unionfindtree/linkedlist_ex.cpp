#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

class linkedlist{
  private:
  struct node{
    int value;
    node *next;
    // コンストラクタ
    node(int val):value(val),next(nullptr){}
  };
  node *head; // インスタンスの生成

  public:
  // これはlinkedlistのインスタンスの生成コンストラクタ→引数の指定はprivateのメンバより、headとして指定するものだけでok.なお、ノード数0で初期化している
  linkedlist():head(nullptr){}

  // linkedlistのデストラクタ;クラスのインスタンスが破棄されるときに自動的に呼び出される特別なメンバ関数。なお、理宇と内のすべてのノードを繰り返し削除してそれらが使用しているメモリを解放している
  ~linkedlist(){
    node *current=head;
    while(current!=nullptr){
      node *next=current->next;
      delete current;
      current=next;
    }
  }
  // add関数の計算時間は常にO(1)
  void add(int value){
    node *newnode=new node(value);
    newnode->next=head; // 有効な連結リストの最終尾に新しいノードを追加するのではなく、一番前に追加(head insertionという手法)→☆基本的かつ一般的、かつ効率的→連結リストの先頭へのアクセスはコストが一番低いから!
    head=newnode;
  }

  void print(){
    node *current=head; // printするために独立のポインタ変数をカウンタ変数の役割として作成
    while(current!=nullptr){
      cout<<current->value<<" ";
      current=current->next;
    }
  }
};

int main(){

  return 0;

}
