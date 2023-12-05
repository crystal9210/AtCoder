#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;
// 方針:2分探索
// ☆upper_bound,lower_boundはそれぞれ内部的に二分探索をする
// https://atcoder.jp/contests/arc084/tasks/arc084_a
// ☆lower_boundは、探索したいkey以上のイテレータを返す
// ☆upper_boundは、探索したいkeyより大きいイテレータを返す
// https://qiita.com/ganyariya/items/33f1326154b85db465c3


int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int it1=0,it2=0;

    long long count = 0;
    rep(i,0,n){
		while(it1 < n && a[it1] < b[i]) it1++;
		while(it2 < n && c[it2] <= b[i]) it2++;
		count += (ll)it1 * (n - it2);
	}
    cout<<count<<endl;
    return 0;

}
