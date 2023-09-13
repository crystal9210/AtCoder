#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,k;
  long long p;  //p:1日周遊パスセットの値段
  cin>>n>>d>>p;

  vector<long long> f(n),s(n);
  for(int i=0;i<n;i++)cin>>f[i];  //各日ごとの通常の運賃
  sort(f.begin(),f.end());  //fの値を昇順に並べることで、1日周遊パスセットを使った方がいい枚数をもとめやすくする

  //s[i]はi日目までの交通費の累積和；1日周遊パスを一切使わない前提で初期化する
  s[0]=f[0];  
  for(int i=0;i<n-1;i++)s[i+1]=s[i]+f[i+1];

  k=(n+d-1)/d;  //kの整数部分をlとすると、=l+1；n日をカバーしきるだけの1日周遊パスのセット数の最低数

  long long ans=p*k;  //ans:全日周遊パスを使うとした場合の料金でansを初期化
  for(int i=0;i<k;i++){
    ans=min(ans,s[n-1-(i*d)]+(p*i));  //d:1日周遊パスのセット数→i*dは1日周遊パスセットをiセット分使った場合の1日周遊パスセットを使う日数i*d日→sは1日の運賃が昇順に並び替えされている/sのインデックス番号がn-1までなことに注意、また、ansはp*kで初期化されているので、for文のカウンタ変数iはk-1までのインクリメントで比較、必要があれば置換、で十分
  }

  cout<<ans<<endl;

  return 0;

}