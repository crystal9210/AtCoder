#include <bits/stdc++.h>
using namespace std;

class Vector {
public:
    int x, y;

    //+演算子のオーバーロードを宣言
    Vector operator+(const Vector& other) {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

    
    // Vector オブジェクトを出力するための operator<< 関数を追加；クラスのインスタンスそのものを出力するのに、それの各メンバを出力できる形式に変換して出力する必要がある→デフォルトでは出力できない。
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main(){
  Vector vector1;
  vector1.x=1;
  vector1.y=2;

  Vector vector2;
  vector2.x = 3;
  vector2.y = 4;

  Vector result=vector1+vector2;
  cout<<result<<endl;

  return 0;
}