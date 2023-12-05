#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

class arraylist{
  private:
  vector<int> data;

  public:
  void add(int value){
    data.push_back(value);
  }

  int get(int index){
    return data[index];
  }

  void remove(int index){
    data.erase(data.begin()+index);
  }

  int size(){
    return data.size();
  }
}

int main(){

  return 0;

}
