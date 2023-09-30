#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> re_time(n,0); // N番目の人が列に戻るまでの時間
    vector<int> somen_sum(n,0); // 各人がGETしたそうめんの合計量

    vector<int> W(m), S(m), T(m);
    rep(i,m){
        cin >> T[i] >> W[i] >> S[i];
    }

    int prev_time = 0;
    rep(i, m){
        // 一番前の人を探す
        int front_person = -1;
        rep(j, n){
            if(re_time[j] <= T[i] - prev_time){ // 戻る時間が経過していればその人が一番前
                front_person = j;
                break;
            }
        }

        if(front_person != -1){ // 一番前の人が存在する場合
            somen_sum[front_person] += W[i];
            re_time[front_person] += S[i];
        }

        rep(j, n){
            // 時間経過に伴うre_timeの更新
            if(j != front_person){ // 一番前の人以外
                re_time[j] -= (T[i] - prev_time);
                if(re_time[j] < 0) re_time[j] = 0;
            }
        }

        prev_time = T[i];
    }

    cout<<endl;

    //結果の出力
    rep(i,n) cout << somen_sum[i] << endl;

    return 0;
}
