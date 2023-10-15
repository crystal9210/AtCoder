#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

// 問題：N種類のスライム、サイズSi,個体数Ci(i=0,1,..,N)がいて、任意回数同じサイズのスライム2匹を合成する。合成後、合成元のスライム2匹は消失。スライムの個体数を最小にする処理を実装する。
// 方針：入力されたうち、サイズが小さいスライムから順に昇順に並び替える。→pythonでいうタプルを要素にする動的配列を生成し、その第一引数を元に入力されたデータを動的配列で受け取り、それに対し、先頭インデックスから順に処理する

int main(){
  int n;
  long long sum_num=0;
  cin>>n;
  // 動的配列vecにタプル(第一引数：si、第二引数：ci)を格納
  vector<pair<long long, long long>> vec;
  vec.reserve(n);
  rep(i,n){
    int s,c;
    cin>>s>>c;
    vec.push_back({s,c});
  }
  // vecの各要素を第一引数を元にして昇順にソート
  sort(vec.begin(), vec.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b){
    return a.first<b.first;
  });

  //ソートができてるかの確認
  // for(const auto& p : vec) {
  //   cout << p.first << " " <<p.second << endl;
  // }


  // ペアの要素のままだと計算コストが高くなる＋メイン処理がしにくい関係で、ここで第一引数、第二引数ごとに動的配列に分割
  vector<long long> s(n);
  vector<long long> c(n);
  rep(i,n)s[i]=vec[i].first;
  rep(i,n)c[i]=vec[i].second;

  // vecのメモリを解放
  vec.clear();
  vec.shrink_to_fit();

  //メイン処理
  rep(i,s.size()){
    long long mix_num=c[i]%2,new_size=2*s[i];
    rep(j,s.size()){
      if(new_size==s[j]){
        c[i]=1;
        c[j]+=mix_num;
        break;
      }
    }
    if(!(c[i]==0 || c[i]==1)){
      c[i]=1;
      //new_sizeより大きい要素を探す
      auto it=upper_bound(s.begin(),s.end(), new_size);

      //見つかった場所の前にnew_sizeを追加
      size_t idx=distance(s.begin(), it);
      s.insert(it, new_size);
      c.insert(c.begin()+idx, mix_num);
    }
  }

  rep(i,c.size())sum_num+=c[i];
  rep(i,c.size())cout<<c[i]<<endl;
  cout<<sum_num<<endl;

  return 0;

}
