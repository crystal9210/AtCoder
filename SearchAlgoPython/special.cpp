#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, x) for (int i = m; i < (x); i++)
typedef long long ll;

// すべての桁が1以上m以下であり桁が保持する数字が増加的なn桁の整数を生成するテンプレコード

// 特定の長さnに対し、各桁1以上m以下の範囲の数値を含む増加するシーケンス(数列)を生成するための再帰関数
void generateIncreasingSequences(int n, int m, int last,
                                 vector<int> &sequence) {
  if (sequence.size() == n) {
    // ここでsequenceにはn桁の増加的な整数が格納されている、出力や他の用途のために利用できる
    for (int num : sequence)
      cout << num << " ";
    cout << endl;
    return;
  }

  rep(i, last, m + 1) {
    sequence.push_back(i); // 現在の文字をシーケンスに追加
    generateIncreasingSequences(n, m, i, sequence);
    sequence.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> sequence; // 数列を格納するベクター
  // special配列の初期状態の確認
  cout << "The initial components of sequence:";
  if (sequence.size() >= 1) {
    for (int num : sequence) {
      cout << num << " ";
    }
  } else {
    cout << " No components.";
  }
  cout << endl;

  // 再帰関数呼び出し
  generateIncreasingSequences(n, m, 1, sequence); // sequence=[]

  return 0;
}
