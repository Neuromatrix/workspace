#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr ll INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#define pb push_back
#define F first
#define S second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (ll)x.size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
inline T bpow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
constexpr ll N = 1e4+5;
ll dp[N][2];
bool oper[N];
bool can[N];
vi G[N];
ll n;
void rec(ll v){
    ll ch1 = v*2+1, ch2 = v*2+2;
    if(ch1>=n) return;
    if(!can[v]){
        if(oper[v]==1){
            dp[v][1] = dp[ch1][1] + dp[ch2][1];
            dp[v][0] = min({
                dp[ch1][1] + dp[ch2][0],
                dp[ch1][0] + dp[ch2][1],
                dp[ch1][0] + dp[ch2][0]
            });
        } else {
            
            dp[v][0] = dp[ch1][0] + dp[ch2][0];
            dp[v][1] = min({
                dp[ch1][1] + dp[ch2][0],
                dp[ch1][0] + dp[ch2][1],
                dp[ch1][1] + dp[ch2][1]
            });
        }
    }
    else{
        dp[v][0]= min({
            dp[ch1][0] + dp[ch2][0]+(ll)(oper[v]!=1),
            dp[ch1][0] + dp[ch2][1]+(ll)(oper[v]!=1),
            dp[ch1][1] + dp[ch2][0]+(ll)(oper[v]!=1),
            dp[ch1][0] + dp[ch2][0]+(ll)(oper[v]!=0)
        });
        dp[v][1] = min({
            dp[ch1][1] + dp[ch2][1]+(ll)(oper[v]!=1),
            dp[ch1][0] + dp[ch2][1]+(ll)(oper[v]!=0),
            dp[ch1][1] + dp[ch2][0]+(ll)(oper[v]!=0),
            dp[ch1][1] + dp[ch2][1]+(ll)(oper[v]!=0)
        });
    }
}
void dfs(ll v, ll p){
    fca(it,G[v]){
        if(it!=p){
            dfs(it,v);
        }
    }
    rec(v);
}

inline void solve(){
    ll  x;
    cin >> n >> x;
    vii pr;
    incr(i,0,N)
        fill(dp[i],dp[i]+2,INF);
    incr(i,0,n){
        if(2*i+1<n){
            G[i].pb(2*i+1);
            G[2*i+1].pb(i);
        }
        if(2*i+2<n){
            G[i].pb(2*i+2);
            G[2*i+2].pb(i);
        }
    }
    incr(i,0,(n-1)/2){
        ll a,b;
        cin >> a >> b;
        oper[i] = a;
        can[i] = b;
    }
    incr(i,(n-1)/2,n){
        ll v;
        cin >> v;
        dp[i][v] = 0;
        
        v = (v+1)%2;
        dp[i][v] = INF;
    }

    dfs(0,-1);
    if(dp[0][x]>=INF/2){
        cout << "IMPOSSIBLE" << nl;
    } else {
        cout << dp[0][x] <<nl;
    }
    
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}