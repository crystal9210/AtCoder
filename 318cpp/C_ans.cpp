//referenced code written by tourist
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")   //コンパイラ最適化オプションを含むヘッダーファイルをインクルード
#pragma GCC optimize("unroll-loops")
using namespace std;

using ll=long long; //long longをllで利用するための宣言文
using ld=long double;
//定数の宣言
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()

template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>; //引数リスト→第一：要素の型の指定(ジェネリスクT)、第二：コンテナの指定;vectorは動的配列、要素が動的配列に格納されることが保証される、第三：デフォルトの比較関数、優先度付きキューを実装するために利用、

void solve();
// oddloop
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    //cin>>t;
    rep(i,0,t) solve(); //t=1より、solve()は一回だけ呼び出しされる
}

void solve(){
    int N=9;
    vector<int> p(N);
    rep(i,0,N) cin>>p[i];
    //数字の配置順序を示すためのベクトル、9個の数字が異なる順番で読まれる全ての可能性を試行するために利用
    vector<int> order(N);
    rep(i,0,N) order[i]=i;  //orderの初期化
    // 縦・横・斜めを示すためのベクトルを要素とするベクトルqの宣言と初期化。要素の各ベクトルは特定の列に対応する3つのますのインデックスを含む。最初の3つは縦の列、次の3つは横の列、足後の2つは斜めの列を示す。
    vector<vector<int>> q;
    //☆qのインデックス[0]:{0,3,6},[1]:{1,4,7},{2,5,8}→3*3マスの縦の3列のインデックスをqに追加する作業
    rep(i,0,3) q.push_back({i,i+3,i+6});    //push_back関数:指定された要素を動的配列の末尾に追加するための標準メンバ関数
    // qの横の3行のインデックスをqに追加→i = 0の場合: {0, 1, 2} を q に追加 → 1行目の横のマス、i = 1の場合: {3, 4, 5} を q に追加 → 2行目の横のマス、i = 2の場合: {6, 7, 8} を q に追加 → 3行目の横のマス
    rep(i,0,3) q.push_back({i*3,i*3+1,i*3+2});
    // qの要素の動的配列に3*3の斜めの列のインデックス群の追加
    q.push_back({0,4,8});
    q.push_back({2,4,6});
    ld X=0,Y=0;
    do{
        X++,Y++;
        // qベクトルの各要素を走査するためのループ文
        for(auto x:q){
            //l,r:xベクタ内の要素
            sort(all(x),[&](int l,int r){return order[l]<order[r];});
            if(p[x[0]]==p[x[1]]&&p[x[1]]!=p[x[2]]){
                Y--;
                break;
            }
        }
    }while (next_permutation(all(order)));
    // next_permutation(all(order))：orderというベクトルの要素を任意に並び替えたすべての順列を生成
    cout<<fixed<<setprecision(20)<<Y/X<<"\n";
}
