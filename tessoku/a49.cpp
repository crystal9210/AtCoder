#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
#define rep_ll(i, m, x) for (ll i = m; i < (x); i++)
typedef long long ll;
typedef long double lb;

// 要素数20の配列が最初用意され、各要素は0で初期化されている、操作ごとに要素を3つ選択する必要があり、それらに対し、+1,-1のいずれかの処理を選択する必要がある。そして、各処理回ごとに全体として0の要素の個数が多くなるように処理Aまたは処理Bを選択し、選択したほうの処理を出力するように設計

// 方針：ビームサーチ
// やったことなかったので解答を参考にした、確認として提出
// 参照先：https://github.com/E869120/kyopro-tessoku/blob/main/codes/cpp/chap07/answer_A49.cpp

// ビームサーチで利用する盤面の状態を保持する構造体
struct State
{
  int score;     // 暫定スコア
  int x[29];     // 現在のxの値
  char lastMove; // 最後の動き('A'or'B')
  int lastPos;   // Beam[i-1][ どこ ]から遷移したか
};

// 比較演算子のオーバーロード
// State構造体のインスタンス同士を比較するためのメソッド
bool operator>(const State &a1, const State &a2)
{
  if (a1.score > a2.score)
    return true;
  else
    return false;
}

// 種類が多いのでなるべく最初の方に確保しておいた方がよさそう
const int width = 10000; // ビームサーチで一度に保持する状態の最大数(ビーム幅を指定)
const int n = 20;
int t, p[109], q[109], r[109]; // 各操作におけるインデックスを保持する配列
int numState[109];             // 各手順での状態の数を保持
State Beam[109][width];        // State構造体をメンバに持つ2次元配列、各構造体は各ビームサーチの状態を保持
char answer[109];              // 最適な操作シーケンスを保持する配列、最適な操作シーケンスを復元するために使用

// ビームサーチ関数
void BeamSearch()
{
  // 0手目の状態を設定
  numState[0] = 1;
  Beam[0][0].score = 0;
  rep(i, 1, n + 1) Beam[0]
                       [0]
                           .x[i] = 0; // ここの原理わからん

  // ビームサーチ
  rep(i, 1, t + 1)
  {
    vector<State> candidate;
    rep(j, 0, numState[i - 1]) // l:90の処理結果を反映することで適切に処理ができるようにしている、処理ブロック内のBeamのインデックスが[i-1][j]となっていることで適切に処理が走るようになっていることを確認
    {
      // 操作Aのケース
      State a = Beam[i - 1][j];
      a.lastMove = 'A';
      a.lastPos = j;
      // 処理A
      a.x[p[i]] += 1;
      a.x[q[i]] += 1;
      a.x[r[i]] += 1;
      rep(k, 1, n + 1)
      {
        if (a.x[k] == 0)
          a.score += 1;
      }

      // 操作Bのケース
      State b = Beam[i - 1][j];
      b.lastMove = 'B';
      b.lastPos = j;
      // 処理B
      b.x[p[i]] -= 1;
      b.x[q[i]] -= 1;
      b.x[r[i]] -= 1;
      rep(k, 1, n + 1)
      {
        if (b.x[k] == 0)
          b.score += 1;
      }

      // 候補に追加
      candidate.push_back(a);
      candidate.push_back(b);
    }

    // そーとしてBeam[i]の結果を計算、このソートではスコアが高いものを最初に持ってくる；降順
    sort(candidate.begin(), candidate.end(), greater<State>());
    // 今回のループで得られたStateの数を格納・保持→l:52にて次のステップの処理に利用
    numState[i] = min(width, (int)candidate.size());
    rep(j, 0, numState[i]) Beam[i][j] = candidate[j];
  }
}

int main()
{
  cin >> t;
  rep(i, 1, t + 1) cin >> p[i] >> q[i] >> r[i];

  // ビームサーチ
  BeamSearch();

  // ビームサーチの復元(crrentPlaceは配列beamのどの位置を参照しているかをしめす)
  int currentPlace = 0;
  for (int i = t; i >= 1; i--)
  {
    answer[i] = Beam[i][currentPlace].lastMove;
    currentPlace = Beam[i][currentPlace].lastPos; // lastPos：Beam[i-1][ どこ ]から遷移したか
  }

  rep(i, 1, t + 1) cout << answer[i] << endl;

  return 0;
}
