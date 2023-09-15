#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<tuple<int,int,int>> lines = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
	vector<int> a(9);
	for (int &x: a) cin >> x;

	vector<int> p(9);
	iota(begin(p), end(p), 0);

	int num = 0, denom = 0;
	do {
		bool bad = false;
		for (auto [i,j,k]: lines) {
			if (a[i] == a[j] && p[i] < p[k] && p[j] < p[k]) bad = true;
			if (a[j] == a[k] && p[j] < p[i] && p[k] < p[i]) bad = true;
			if (a[k] == a[i] && p[k] < p[j] && p[i] < p[j]) bad = true;
		}
		num += bad, denom++;
	} while (next_permutation(begin(p), end(p)));

	cout << fixed << setprecision(20) << double(denom-num)/denom << '\n';
}
