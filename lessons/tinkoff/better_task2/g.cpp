#include <bits\stdc++.h>
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
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
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
constexpr int N = 2e5+5;
int color[N];
vi visited(N,0);
vi h(N,0),dp(N,0);
vi g[N],g1[N];
void dfs1(int v, int col, int cmp)
{
    if (visited[v]) return;
    if (color[v] != col) return;
    visited[v] = true;
    h[v] = cmp;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs1(to, col, cmp);
    }
}
int ans = 0;
void dfs2(int v, int p = -1)
{
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < g1[v].size(); i++)
    {
        int to = g1[v][i];
        if (to == p) continue;
        dfs2(to, v);
        int val = dp[to] + 1;
        mx2 = max(mx2, val);
        if (mx1 < mx2) swap(mx1, mx2);
    }
    dp[v] = mx1;
    ans = max(ans, mx1 + mx2);
}
inline void solve(){
    int n;
    cin >> n;
    int ioio[2];
    ioio[1] = 0;
    ioio[0] = 0;
    incr(i,1,n+1){
        cin >> color[i];
        ioio[color[i]]++;
    }
    incr(i,0,n-1){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(ioio[1]*ioio[0]==0){
        cout << 0 << nl;
        return;
    } else {
        int x = 0;
        incr(i,1,n+1)
            if (!visited[i])
                dfs1(i, color[i], x++);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < g[i].size(); j++)
            {
                int to = g[i][j];
                if (h[i] != h[to])
                    g1[h[i]].push_back(h[to]);
            }
            dfs2(0);
        cout << (ans + 1) / 2 << nl;
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