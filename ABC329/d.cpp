#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n, 0);
    vector<int> a(m, 0);

    priority_queue<pair<int, int>> max_heap; // 最大ヒープ (得票数, 候補者番号) を保持

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--; // 候補者番号は0からn-1までの範囲に合わせる
        p[a[i]]++;

        max_heap.push({p[a[i]], a[i]});

        while (!max_heap.empty()) {
            auto top = max_heap.top();
            if (p[top.second] != top.first) {
                max_heap.pop(); // 最大の得票数でない場合、取り出して破棄
            } else {
                cout << top.second + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
