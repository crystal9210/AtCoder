// 2,3次元いもす法
// 問題：あなたは様々な種類のモンスターを捕まえるゲームをしています．今あなたがいるのは W×H のタイルからなる草むらです．この草むらでは N 種類のモンスターが現れます．モンスター i は Ai≦x<Bi, Ci≦y<Di の範囲にしか現れません．このゲームを効率的に進めるため，1 つのタイル上で現れるモンスターの種類の最大値が知りたいです．（ただし，W×H は計算可能な程度の大きさとし，N は大きくなりうるものとします．）

// 方針：
// 求：1つのタイル上で現れるモンスターの種類の最大値
// 使用パラメータ：最大値を保持するm、種類n、種類iのモンスターの生息範囲を格納するためのa,b,c,d;a-b：横、c-d：縦、各タイルに出現するモンスターの種類を保持する2次元配列tiles

#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
  int n,w,h,m=0;
  cin>>n>>w>>h;
  vector<int> a(n),b(n),c(n),d(n);
  vector<vector<int>> tiles(h,vector<int>(w));
  rep(i,n)cin>>a[i]>>b[i]>>c[i]>>d[i];

  // メイン処理
  // 重みの加算;累積和の考え方の利用→図を書いてそれを元に走査をイメージする
  rep(i,n){
    tiles[c[i]][a[i]]++;
    tiles[c[i]][b[i]]--;
    tiles[d[i]][a[i]]--;
    tiles[d[i]][b[i]]++;
  }

  // 横方向への累積和
  rep(y,h)rep(x,w)tiles[y][x]+=tiles[y][x-1];

  // 縦方向への累積和
  rep(y,h)rep(x,w)tiles[y][x]+=tiles[y-1][x];

  // 最大値を調べる
  rep(y,h)rep(x,w)if(m<tiles[y][x])m=tiles[y][x];

  cout<<m<<endl;

  return 0;

}
