#include <iostream>
#include <vector>
#include <tuple>
int main()
{
  using namespace std;

  unsigned long K;
  cin >> K;
  unsigned long Sx, Sy, Tx, Ty;
  cin >> Sx >> Sy >> Tx >> Ty;
  // K ずつ右上にずらしておく;タイルの配置を簡単にするための調整；よくわからん→タイルの境界処理が簡単になるらしい
  Sx += K;
  Sy += K;
  Tx += K;
  Ty += K;

  // 通行料の上界；直接的な最短距離を入れておく
  unsigned long dist{max(Tx, Sx) - min(Tx, Sx) + max(Ty, Sy) - min(Ty, Sy)};

  // 1 < K のとき、大タイルを経由する移動を考える
  if (1 < K)
  {
    vector<tuple<unsigned long, unsigned long, unsigned long>> large_start; // はじめに到達する大タイルの候補
    if (((Sx / K) ^ (Sy / K)) & 1)                                          // 開始位置が大タイルなら；排他的論理和(Sx / K) ^ (Sy / K)の再開ビットが1か0かを確認
      large_start.emplace_back(Sx / K, Sy / K, 0);                          // その大タイルを新しくベクトルの末尾に追加
    else
    {                                                           // そうでなければ、四方向いずれかで最も近い大タイルが候補；それぞれスタート地点から各方向に移動する際の移動距離および移動費を指示している、第一・二引数は移動先の隣接した各大タイルの位置を指示する数値と、第三引数は、その大タイルに移動する際に通行料の計算をしている
      large_start.emplace_back(Sx / K - 1, Sy / K, 1 + Sx % K); // 左
      large_start.emplace_back(Sx / K + 1, Sy / K, K - Sx % K); // 右
      large_start.emplace_back(Sx / K, Sy / K - 1, 1 + Sy % K); // 下
      large_start.emplace_back(Sx / K, Sy / K + 1, K - Sy % K); // 上
    }
    vector<tuple<unsigned long, unsigned long, unsigned long>> large_goal; // 最後に到達する大タイルの候補
    if (((Tx / K) ^ (Ty / K)) & 1)                                         // 終了位置が大タイルなら
      large_goal.emplace_back(Tx / K, Ty / K, 0);                          // その大タイル
    else
    {                                                          // そうでなければ、四方向いずれかで最も近い大タイルが候補
      large_goal.emplace_back(Tx / K - 1, Ty / K, 1 + Tx % K); // 左
      large_goal.emplace_back(Tx / K + 1, Ty / K, K - Tx % K); // 右
      large_goal.emplace_back(Tx / K, Ty / K - 1, 1 + Ty % K); // 下
      large_goal.emplace_back(Tx / K, Ty / K + 1, K - Ty % K); // 上
    }
    // K = 2 かどうかで場合分け
    if (K == 2)
      for (const auto &[x, y, d1] : large_start)
        for (const auto &[z, w, d2] : large_goal)
        {
          const auto x_diff{max(x, z) - min(x, z)}; // xとzの絶対的な距離差を計算してx_diffに代入
          const auto y_diff{max(y, w) - min(y, w)};
          // d1:スタート地点から大タイルまでの通行料、d2:大タイルからゴール地点までの通行料、x_diff:大タイルのX座標間の差、y_diff:大タイルのY座標間の差、(max(x_diff, y_diff) - min(x_diff, y_diff)) / 2：対角線移動の追加コスト
          dist = min(dist, d1 + d2 + x_diff + y_diff + (max(x_diff, y_diff) - min(x_diff, y_diff)) / 2);
        }
    else
      for (const auto &[x, y, d1] : large_start)
        for (const auto &[z, w, d2] : large_goal)
          dist = min(dist, d1 + d2 + max(x + y, z + w) - min(x + y, z + w) + max(x + w, z + y) - min(x + w, z + y));
  }
  cout << dist << endl;
  return 0;
}
