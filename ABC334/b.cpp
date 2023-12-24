#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,x) for(int i=m;i<(x);i++)
#define rep_ll(i,m,x) for(ll i=m;i<(x);i++)
typedef long long ll;
typedef long double lb;

int main(){
    ll a,m,l,r,under,sup,ans=0;
    cin>>a>>m>>l>>r;

    if(r-l<m){
        sup=(r-a)/m;
        under=(l-a)/m;
        // cout<<sup<<endl;
        // cout<<l-a<<endl;
        // cout<<under<<endl;
        if(sup!=under)ans++;
        if((r-a)%m==0 && r==l)ans++;
        else if(l<=a && a<=r)ans++;
    }else if(l<=a && a<=r){
        // lとrの間に木が少なくとも1本あるケース
        sup=(r-a)/m;
        under=(a-l)/m;
        ans=sup+under+1;
    }else if(a<=l && a<=r){
        sup=(r-a)/m+1;
        under=(l-a)/m+1;
        ans=sup-under;
        if((a-l)%m==0)ans++;
    }else if(l<=a && r<=a){
        sup=(a-r)/m+1;
        under=(a-l)/m+1;
        ans=under-sup;
        if((r-a)%m==0)ans++;
    }

    cout<<ans<<endl;

    return 0;
}
