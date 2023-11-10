#include <iostream>
using namespace std;
// 再帰関数作って全探索したほうがいい気がする
void allPattern(int n,int& x,int midx,int& f, int& s,int& sum,int each_sum){
  // 処理0
    if(n<=0){
        sum=min(sum,each_sum);
        return;
    }
    // 処理1
    if( midx>0){
        int n1=n-midx;
        int mid1=midx-f;
        if(mid1<0)mid1=0;
        // cout<<n1<<' '<<x<<' '<<mid1<<' '<<f<<' '<<s<<' '<<sum<<' '<<each_sum<<endl;
        allPattern(n1,x,mid1,f,s,sum,each_sum+1);
    }
    // 処理2
    if(x>midx  && midx>=0){
        int mid2=midx+s;
        if(mid2>x)mid2=x;
        // cout<<n<<' '<<x<<' '<<mid2<<' '<<f<<' '<<s<<' '<<sum<<' '<<each_sum<<endl;
        allPattern(n,x,mid2,f,s,sum,each_sum+3);
    }
    return;
}
int main(void){
    int n,x,f,s,sum=1000000,each_sum=0;
    cin>>n>>x>>f>>s;
    int midx=x;
    allPattern(n,x,midx,f,s,sum,each_sum);
    cout<<sum<<endl;

    return 0;

}
