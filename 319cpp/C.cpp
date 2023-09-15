#include <array>
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
int main() {
    using namespace std;
    array<int, 9> cells;
    for (auto &&c : cells)
        cin >> c;
    // 縦・横・斜めの列の一覧
    vector<tuple<int, int, int>> row{{0, 1, 2}, // 上から 1 行目
                                     {3, 4, 5}, // 上から 2 行目
                                     {6, 7, 8}, // 上から 3 行目
                                     {0, 3, 6}, // 左から 1 列目
                                     {1, 4, 7}, // 左から 2 列目
                                     {2, 5, 8}, // 左から 3 列目
                                     {0, 4, 8}, // 左上から右下
                                     {2, 4, 6}};// 右上から左下
    array<int, 9> order; // i 個めのマスが何回目に開けられるか
    iota(begin(order), end(order), 0);
    int not_disappoint = 0, all = 0; // がっかりしない開け方の個数, 開け方の総数
    do {
        ++all;
        bool disappoint_flag = false; // この開け方でがっかりするかを判定
        for (auto &&[a, b, c] : row) // 1 列に並んでいるマス a, b, c について
            // マス a と マス b が同じ数字 && マス c が最後に開けられたらがっかり
            if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
                disappoint_flag = true;
            // 同じ数字のペアが残り 2 通りの場合も同様
            else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b])
                disappoint_flag = true;
            else if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])
                disappoint_flag = true;
        // がっかりしなかったら、カウントを増やす
        if (!disappoint_flag)
            ++not_disappoint;
    } while (ranges::next_permutation(order).found); // 開け方を全通り試す
    // 10 桁ぶん出力するように設定
    cout << setprecision(10);
    // がっかりしない知り方の個数を総数で割って出力
    // 小数として計算する必要があることに注意
    cout << (double)not_disappoint / all << endl;
    return 0;
}