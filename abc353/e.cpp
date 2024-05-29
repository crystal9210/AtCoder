#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int max_n = 300005;
const int alphabet_size = 26;

// トライの各ノードにおける、そのノードを通過する文字列の数をカウントするための配列：prefixCount
int trie[max_n][alphabet_size], nodeCount, prefixCount[max_n];
ll lcp_sum = 0;

// トライに文字列を挿入する関数
void insertString(const string &s)
{
  int node = 0;
  for (char ch : s)
  {
    int index = ch - 'a'; // 文字をインデックスに変換;'a'のインデックスは0→l:9の数値を利用、これはアルファベットの順番を指示
    if (!trie[node][index])
    {
      trie[node][index] = ++nodeCount; // ノードが存在しない場合、新しいインデックスを割り当てる
    }
    node = trie[node][index];       // ここで親ノードの子ノードを(次のノード処理のために)親ノードにする処理をしている
    lcp_sum += prefixCount[node]++; // 現在のノードを通過する文字列の数をインクリメントし、それをansに加算する→処理の詳細は最下部のコメントアウトに記述
  }
}

// メイン関数
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> strings(n);
  for (int i = 0; i < n; ++i)
    cin >> strings[i];

  for (const string &s : strings)
    insertString(s);

  cout << lcp_sum << endl;
  return 0;
}

// lcp_sum += prefixCount[node]++;
// の動作　特にこのコメントアウトの一番下を見るとわかりやすいと思う。原理的にはdp的な加算方式を使ってる
// この式の動作を理解するために、具体的な文字列例を使って説明します。例として、以下の3つの文字列を考えます：

// abcd
//     abce
//         abef
//             文字列 abcd の挿入 'a' の処理 :

//     node = 0(ルートノード)
//         index = 'a' - 'a' = 0 trie[0][0] が 0 なので、新しいノード 1 を作成
//                     node = 1 に更新
//                         lcp_sum += prefixCount[1]++（prefixCount[1] は 0 から 1 にインクリメント、lcp_sum に 0 を加算） 'b' の処理 :

//     node = 1 index = 'b' - 'a' = 1 trie[1][1] が 0 なので、新しいノード 2 を作成
//                          node = 2 に更新
//                              lcp_sum += prefixCount[2]++（prefixCount[2] は 0 から 1 にインクリメント、lcp_sum に 0 を加算） 'c' の処理 :

//     node = 2 index = 'c' - 'a' = 2 trie[2][2] が 0 なので、新しいノード 3 を作成
//                          node = 3 に更新
//                              lcp_sum += prefixCount[3]++（prefixCount[3] は 0 から 1 にインクリメント、lcp_sum に 0 を加算） 'd' の処理 :

//     node = 3 index = 'd' - 'a' = 3 trie[3][3] が 0 なので、新しいノード 4 を作成
//                          node = 4 に更新
//                              lcp_sum += prefixCount[4]++（prefixCount[4] は 0 から 1 にインクリメント、lcp_sum に 0 を加算）
//                                  文字列 abce の挿入 'a' の処理 :

//     node = 0 index = 'a' - 'a' = 0 trie[0][0] は既にノード 1 を指しているので新しいノードは作成しない
//                          node = 1 に更新
//                              lcp_sum += prefixCount[1]++（prefixCount[1] は 1 から 2 にインクリメント、lcp_sum に 1 を加算） 'b' の処理 :

//     node = 1 index = 'b' - 'a' = 1 trie[1][1] は既にノード 2 を指しているので新しいノードは作成しない
//                          node = 2 に更新
//                              lcp_sum += prefixCount[2]++（prefixCount[2] は 1 から 2 にインクリメント、lcp_sum に 1 を加算） 'c' の処理 :

//     node = 2 index = 'c' - 'a' = 2 trie[2][2] は既にノード 3 を指しているので新しいノードは作成しない
//                          node = 3 に更新
//                              lcp_sum += prefixCount[3]++（prefixCount[3] は 1 から 2 にインクリメント、lcp_sum に 1 を加算） 'e' の処理 :

//     node = 3 index = 'e' - 'a' = 4 trie[3][4] が 0 なので、新しいノード 5 を作成
//                          node = 5 に更新
//                              lcp_sum += prefixCount[5]++（prefixCount[5] は 0 から 1 にインクリメント、lcp_sum に 0 を加算）
//                                  文字列 abef の挿入 'a' の処理 :

//     node = 0 index = 'a' - 'a' = 0 trie[0][0] は既にノード 1 を指しているので新しいノードは作成しない
//                          node = 1 に更新
//                              lcp_sum += prefixCount[1]++（prefixCount[1] は 2 から 3 にインクリメント、lcp_sum に 2 を加算） 'b' の処理 :

//     node = 1 index = 'b' - 'a' = 1 trie[1][1] は既にノード 2 を指しているので新しいノードは作成しない
//                          node = 2 に更新
//                              lcp_sum += prefixCount[2]++（prefixCount[2] は 2 から 3 にインクリメント、lcp_sum に 2 を加算） 'e' の処理 :

//     node = 2 index = 'e' - 'a' = 4 trie[2][4] が 0 なので、新しいノード 6 を作成
//                          node = 6 に更新
//                              lcp_sum += prefixCount[6]++（prefixCount[6] は 0 から 1 にインクリメント、lcp_sum に 0 を加算） 'f' の処理 :

//     node = 6 index = 'f' - 'a' = 5 trie[6][5] が 0 なので、新しいノード 7 を作成
//                          node = 7 に更新
//                              lcp_sum += prefixCount[7]++（prefixCount[7] は 0 から 1 にインクリメント、lcp_sum に 0 を加算）
//                                             合計
//                                                 文字列 abcd の挿入で lcp_sum は 0 文字列 abce の挿入で lcp_sum は 3 追加
//                                                     文字列 abef の挿入で lcp_sum は 4 追加
//                                                         最終的な lcp_sum は 0 +
//                                         3 + 4 = 7 です。
