#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=16;

ll dp[1<<MAXN],g[MAXN][MAXN],n;

ll solve(int mk){
	if(!mk) return 0;
	ll &r=dp[mk];
	if(r>=0) return r;
	
	int f=-1;
	fore(i,0,n) if(f<0 && (mk&(1<<i))) f=i;
	
	r=solve(mk^(1<<f));
	
	fore(i,f+1,n) if(mk&(1<<i)) r=max(r, g[f][i]+solve(mk^(1<<f)^(1<<i)));
	
	return r;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n) fore(j,i+1,n) cin>>g[i][j], g[j][i]=g[i][j];
	memset(dp,-1,sizeof(dp));
	cout<<solve((1<<n)-1)<<"\n";
}