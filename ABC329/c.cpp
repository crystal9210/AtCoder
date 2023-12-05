#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

void countnum(const vector<char>& s, const vector<char>& uniqueArr, vector<int>& intArr) {
    int n = s.size();
    rep(i,0,(int)uniqueArr.size()){
        int max_m=0;
        int j=0; // インデックスをループ外に移動
        while(j<n){
            if (s[j]==uniqueArr[i]){
                int cnt=1;
                while(j<n-1&&s[j]==s[j+1]){
                    j++;
                    cnt++;
                }
                max_m = max(max_m, cnt);
            }
            j++; // インデックスを増加させて次の文字をチェック
        }
        intArr[i] = max_m;
    }
}
int main(){
  int n;
  cin>>n;
  vector<char> s(n);
  rep(i,0,n)cin>>s[i];
  set<char> unique;
  for(char c:s){
    unique.insert(c);
  }
  vector<char> uniqueArr(unique.begin(), unique.end());
  // for(char c:uniqueArr){
  //   cout<<c<<endl;
  // }
  vector<int> intArr(unique.size(), 0);
  countnum(s,uniqueArr,intArr);
  int ans=0;
  rep(i,0,(int)uniqueArr.size()){
    // cout<<intArr[i]<<endl;
    ans+=intArr[i];
  }
  cout<<ans<<endl;
  return 0;

}
