#include <bits/stdc++.h>
using namespace std;

int main(){
  int M;
  cin>>M;
  string S1,S2,S3;
  S1.resize(M);
  S2.resize(M);
  S3.resize(M);
  cin>>S1;
  cin>>S2;
  cin>>S3;

  int min_time=-1;

  for (int t1 = 0; t1 < M; t1++) {
        for (int t2 = 0; t2 < 2*M; t2++) {
            for (int t3 = 0; t3 < 3*M; t3++) {
                char c1 = S1[t1];
                char c2 = S2[t2%M];
                char c3 = S3[t3%M];
                if (c1 == c2 && c2 == c3 && t1!=t2 && t2!=t3 && t3!=t1 ) {
                    int max_t = max({t1, t2, t3});
                    if (min_time == -1 || max_t < min_time) {
                        min_time = max_t;
                    }
                }
            }
        }
    }

  cout<<min_time<<endl;

  return 0;
}