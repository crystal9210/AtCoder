#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

void processA() {
  // 50%のリソース消費を模倣
  auto start=chrono::high_resolution_clock::now();
  while(true) {
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed=end-start;
    if(elapsed.count()>1000) {
      start=chrono::high_resolution_clock::now();
    }
  }
}

void processB() {
    // 20%のリソース消費を模倣
    auto start = chrono::high_resolution_clock::now();
    while(true) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        if(elapsed.count() > 500) { // 0.5秒ごとに少し休憩
            this_thread::sleep_for(chrono::milliseconds(200)); // 200ms休憩
            start = chrono::high_resolution_clock::now();
        }
    }
}

// void processC() {
//     // 100%のリソース消費を模倣
//     while(true) {
//         // 何もしない無限ループでCPUをフルに使う
//     }
// }

void processC() {
    // 改善後: CPUリソースを100%消費しないように調整
    auto start = chrono::high_resolution_clock::now();
    while(true) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        if(elapsed.count() > 100) { // 0.1秒ごとに少し休憩
            this_thread::sleep_for(chrono::milliseconds(100)); // 100ms休憩
            start = chrono::high_resolution_clock::now();
        }
    }
}


int main(){
  thread a(processA);
  thread b(processB);
  thread c(processC);

  a.join();
  b.join();
  c.join();

  return 0;

}
