#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
constexpr ll MAX = 2000000000000000000;
constexpr ld PI = 3.14159265358979;
constexpr ll MOD = 0;//2024948111;
ld dotorad(ld K){ return PI * K / 180.0; }
ld radtodo(ld K){ return K * 180.0 / PI; }
mt19937 mt;
void randinit(){ srand((unsigned)time(NULL));mt = mt19937(rand()); }
ll N;
vector<vector<ll>> D(17,vector<ll>(17,0));
vector<ll> memo(1LL << 17,-1);
ll ans = 0;
ll solve(ll bit){
    if(memo[bit] != -1) return memo[bit];
    if(bit == (1LL << N) - 1) return memo[bit] = 0;
    ll res = 0,I = -1;
    for(ll i = 0;i < N;i++){
        if(!(bit & (1LL << i))){
            I = i;
            break;
        }
    }
    if(I == -1) return memo[bit] = 0;
    for(ll i = I + 1;i < N;i++){
        if(!(bit & (1LL << i))){
            res = max(res,solve(bit | (1LL << I) | (1LL << i)) + D[I][i]);
        }
    }
    res = max(res,solve(bit | (1LL << I)));
    ans = max(ans,res);
    return memo[bit] = res;
}
int main(){
    cin >> N;
    for(ll i = 0;i < N;i++){
        for(ll j = i + 1;j < N;j++){
            cin >> D[i][j];
        }
    }
    solve(0);
    cout << ans << endl;
}
