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
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.fi << " " << v.se;return out;}
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
T pow(T a, T poww,long long mod = LLONG_MAX){
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
class DSUe2//!две евристики и наутральная нумерация
{
    private:
        vector <int> parent;
        vector <int> rank;
    public:
        void add(int v) {
            parent[v] = v;
            rank[v] = 0;
        }
        void init(int n){// ?сменить нумерацию можно здесь
            parent.resize(n+1);
            rank.resize(n+1);
            for (size_t i = 1; i <= n; i++) add(i);
        }
        int find(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (rank[a] < rank[b])
                    swap (a, b);
                parent[b] = a;
                if (rank[a] == rank[b])
                    ++rank[a];
            }
        }
        bool same(int a, int b){
            return (find(a)==find(b));
        }
        DSUe2(){}
        DSUe2(int n){init(n);}
};
//!первый вес//
vector < pair<int,int> > Kruskal(vector <tuple<int, int, int>> g /*список ребер*/, int n){
    DSUe2 dsu(n);
    vector < pair<int,int> > res;
    int m = g.size();
    sort (g.begin(), g.end());
    for (int i=0; i<m; ++i) {
        int a, b, w;
        tie(w,a,b) = g[i];
        if (!dsu.same(a,b)) {
            res.push_back({a,b});
            dsu.unite(a, b);
        }
    }
    return res;
}
//!первый вес//
long long Kruskal_cost(vector <tuple<int, int, int>> g /*список ребер*/, int n){
    DSUe2 dsu(n);
    long long cost = 0;
    int m = g.size();
    sort (g.begin(), g.end());
    for (int i=0; i<m; ++i) {
        int a, b, w;
        tie(w,a,b) = g[i];
        if (!dsu.same(a,b)) {
            cost+=w;
            dsu.unite(a, b);
        }
    }
    return cost;
}
inline void solve(){
    
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}