/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,sse4.2,popcnt,lzcnt")
*/

#include <bits/stdc++.h>
#define taskname ""
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define isz(x) (int)x.size()
using namespace std;

const int mxN = 2e5 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18;

int a[3][3];

bool check(vector<int> &perm) {
    for (int i = 0; i < 3; ++i) {
        if (a[i][0] == a[i][1] && perm[i * 3 + 0] < perm[i * 3 + 2] && perm[i * 3 + 1] < perm[i * 3 + 2]) {
            return false;
        }
        if (a[i][0] == a[i][2] && perm[i * 3 + 0] < perm[i * 3 + 1] && perm[i * 3 + 2] < perm[i * 3 + 1]) {
            return false;
        }
        if (a[i][1] == a[i][2] && perm[i * 3 + 1] < perm[i * 3 + 0] && perm[i * 3 + 2] < perm[i * 3 + 0]) {
            return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (a[0][i] == a[1][i] && perm[i + 0] < perm[i + 6] && perm[i + 3] < perm[i + 6]) {
            return false;
        }
        if (a[0][i] == a[2][i] && perm[i + 0] < perm[i + 3] && perm[i + 6] < perm[i + 3]) {
            return false;
        }
        if (a[1][i] == a[2][i] && perm[i + 3] < perm[i + 0] && perm[i + 6] < perm[i + 0]) {
            return false;
        }
    }
    if (a[0][0] == a[1][1] && perm[0] < perm[8] && perm[4] < perm[8]) {
        return false;
    }
    if (a[0][0] == a[2][2] && perm[0] < perm[4] && perm[8] < perm[4]) {
        return false;
    }
    if (a[1][1] == a[2][2] && perm[4] < perm[0] && perm[8] < perm[0]) {
        return false;
    }

    if (a[0][2] == a[1][1] && perm[2] < perm[6] && perm[4] < perm[6]) {
        return false;
    }
    if (a[0][2] == a[2][0] && perm[2] < perm[4] && perm[6] < perm[4]) {
        return false;
    }
    if (a[1][1] == a[2][0] && perm[4] < perm[2] && perm[6] < perm[2]) {
        return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> perm(9);
    iota(all(perm), 0);
    int tot = 0, res = 0;
    do {
        ++tot;
        res += check(perm);
    } while (next_permutation(all(perm)));
    cout << fixed << setprecision(12) << 1.0 * res / tot << endl;
}

signed main() {

#ifndef CDuongg
    if(fopen(taskname".inp", "r"))
        assert(freopen(taskname".inp", "r", stdin)), assert(freopen(taskname".out", "w", stdout));
#else
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();

#ifdef CDuongg
   auto end = chrono::high_resolution_clock::now();
   cout << "\n"; for(int i = 1; i <= 100; ++i) cout << '=';
   cout << "\nExecution time: " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif

}
