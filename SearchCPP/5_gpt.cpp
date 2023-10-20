#include <bits/stdc++.h>
using namespace std;
// AC
// 方針：判定する数字が3桁なので、乱数を小さいものから生成し、その乱数が標準入力で受け取った配列の要素と一致するものがあるかどうかを判定(全探索的解法)
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> s(M), c(M);
    for(int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
    }

    for(int num = 0; num < 1000; num++) {
        string numStr = to_string(num);

        // 数字がN桁でないならスキップ
        if(numStr.size() != N) continue;

        bool valid = true;
        for(int i = 0; i < M; i++) {
            // 指定された桁の数字が一致しない場合
            // 判定文中の-'0'について:文字列型の数字Aについて、'A'-'0'=A
            if(numStr[s[i] - 1] - '0' != c[i]) {
                valid = false;
                break;
            }
        }
        // 全ての条件を満たす数字が見つかった
        if(valid) {
            cout << num << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

// 追記:
// for(int i = 0; i < M; i++) {
// 指定された桁の数字が一致しない場合
// // 判定文中の-'0'について:文字列型の数字Aについて、'A'-'0'=A
// if(numStr[s[i] - 1] - '0' != c[i]) {
//     valid = false;
//     break;
//     }
// }部分の処理は、0から1000までの数字において、その数字の各桁すべてが入力から受け取ったs,c内のデータの組に入るかどうかを判定し、その判定元の数字自体が小さいものから行うため、最終的に1つでも一致する数字があった場合、それを出力すれば要件を満たすことになる、ということ
