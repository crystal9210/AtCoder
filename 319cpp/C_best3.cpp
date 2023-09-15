#include <bits/stdc++.h>
using namespace std;
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define ff(i,j,k) for(int i=(j),end_i=(k);i< end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
#define debug(x) cerr<<#x<<"="<<x<<endl
#define debugv(x) cerr<<#x<<" : "; ff(i,0,(x).size()) cerr<<(x)[i]<<(i==(x).size()-1?'\n':' ')
#define all(x) (x).begin(),(x).end()
#define cle(x) memset(x,0,sizeof(x))
#define lowbit(x) ((x)&-(x))
#define VI vector<int>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define lb long db
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
template<class T>inline void read(T &x) {
    x=0; char ch=getchar(); bool f=0;
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch^48);
    if(f) x=-x;
}
template<class T, class... V>
inline void read(T &a, V&... b){read(a); read(b...);}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int b[4][4], c[4][4], a[10];
int main() {
    int cnt = 0;
    fo(i,1,3)
        fo(j,1,3) {
            cin >> c[i][j];
            b[i][j] = ++cnt;
        }
    fo(i,1,9) a[i] = i;
    int sum = 0, ans = 0;
    do {
        auto check = [&](int a1, int b1, int a2, int b2, int a3, int b3) -> bool {
            if (c[a1][b1] == c[a2][b2] && a[b[a1][b1]] < a[b[a3][b3]] && a[b[a2][b2]] < a[b[a3][b3]])
                return 1;
            swap(a1, a3);
            swap(b1, b3);
            if (c[a1][b1] == c[a2][b2] && a[b[a1][b1]] < a[b[a3][b3]] && a[b[a2][b2]] < a[b[a3][b3]])
                return 1;
            swap(a2, a3);
            swap(b2, b3);
            if (c[a1][b1] == c[a2][b2] && a[b[a1][b1]] < a[b[a3][b3]] && a[b[a2][b2]] < a[b[a3][b3]])
                return 1;
            return 0;
        };
        bool flag = 1;
        fo(i,1,3)
            if (check(i,1,i,2,i,3) || check(1,i,2,i,3,i)) {
                flag = 0;
                break;
            }
        if (check(1,1,2,2,3,3))
            flag = 0;
        if (check(1,3,2,2,3,1))
            flag = 0;
        if (flag) sum ++;
        ans ++;
    } while(next_permutation(a+1, a+10));
    printf("%.10lf\n", sum * 1.0 / ans);
    return 0;
}