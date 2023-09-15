#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
const ll ILL=2167167167167167167;
const int INF=2100000000;
const int mod=998244353;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}
int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}



void solve();
// oddloop
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    //cin>>t;
    rep(i,0,t) solve();
}

void solve(){
    int N=9;
    vector<int> p(N);
    rep(i,0,N) cin>>p[i];
    vector<int> order(N);
    rep(i,0,N) order[i]=i;
    vector<vector<int>> q;
    rep(i,0,3) q.push_back({i,i+3,i+6});
    rep(i,0,3) q.push_back({i*3,i*3+1,i*3+2});
    q.push_back({0,4,8});
    q.push_back({2,4,6});
    ld X=0,Y=0;
    do{
        X++,Y++;
        for(auto x:q){
            sort(all(x),[&](int l,int r){return order[l]<order[r];});
            if(p[x[0]]==p[x[1]]&&p[x[1]]!=p[x[2]]){
                Y--;
                break;
            }
        }
    }while (next_permutation(all(order)));
    cout<<fixed<<setprecision(20)<<Y/X<<"\n";
}
