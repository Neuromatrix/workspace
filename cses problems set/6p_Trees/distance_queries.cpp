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
//! helpers
class ancestors_tree{
    private:
        int n;
        vvi gr;
        vvi data;
        int root = 1;
        inline void dfs(int cur, int prev){
            data[0][cur] = prev;
            fca(nex,gr[cur]){
                if(nex==prev) continue;
                dfs(nex,cur);
            }
        }
    public:
        void init(const vector <vector <int>> &graph){ 
            gr = graph;
            n = gr.size();
            data.resize(n+1);
            data[0].resize(n+1);
            dfs(root, 0);
            for (int i = 1; 1<<i <= n ; i++){ 
                data[i].resize(n+1);
                for (int j = 0; j <= n ; j++)
                    data[i][j] = data[i-1][data[i-1][j]];
            }
        }
 
        int query(int node, int k){
            int boss = node;
            for(int i=0; i<=20; i++)
                if(k & (1<<i))
                    boss = data[i][boss];
            return (boss==0 ? -1 : boss);
        }
};
template <typename T>
class sparse_table
{
private:
    vector <vector <T>> data;
    size_t size_it = 0;
public:
    void resize(size_t new_size){
        size_t t = __lg(new_size)+1;
        data.resize(t);
        for(size_t i = 0; i < t; i++){
            data[i].assign(new_size,INF);
        }
        size_it = new_size;
    }
    
    void init(vector <T> gh){
        resize(gh.size());
        data[0] = gh;
        for (int l = 0; l < __lg(size_it); l++){
            for (int i = 0; i + (2 << l) <= size_it; i++){
                data[l+1][i] = min(data[l][i], data[l][i + (1 << l)]);
            }
        }
    }
    T mins(size_t l, size_t r){ // [l,r)
        int t = __lg(r - l);
        return min(data[t][l], data[t][r - (1 << t)]);
    }
    void print(){
        for (int i = 0; i < data.size();i++){
            for (int j = 0; j < data[i].size();j++){
                if(data[i][j]==INF) cout << "-" <<" ";
                else cout << data[i][j] << " ";
            }
            cout << nl;
        }
    }
    sparse_table(size_t new_size = 0){
        resize(new_size);
    }
    sparse_table(vector <T> gh){
        resize(gh.size());
        init(gh);
    }
    sparse_table(size_t new_size, vector <T> gh){
        resize(new_size);
        init(gh);
    }
 
};
//!musthave lca
class NodesDist
{
private:
    int n;
    sparse_table <int> data;
    vector <vector <int>> gr;
    vector <int> depth;
    ancestors_tree ancset;
    vector <int> order;
    unordered_map <int, int> index;
    inline void dfs(int cur, int prev, int d = 1){
        depth.push_back(d);
        order.push_back(cur);
        for(const auto & nex: gr[cur]){
            if(nex==prev) continue;
            dfs(nex,cur,d+1);
            order.push_back(cur);
            depth.push_back(d);
        }
    }
public:
    void init(const vector <vector <int>> & graph){//!натуральная нумерация
        n = graph.size();
        gr = graph;
        dfs(1,0);
        for (size_t i = 0; i < order.size(); i++){
            index[order[i]] = i;
        }
        ancset.init(graph);
        data.init(depth);
    }
    int query(int a, int b){
        return depth[index[a]]+depth[index[b]]-
        2*depth[index[ancset.query(a,depth[index[a]]-data.mins(min(index[a],index[b]),
        max(index[a],index[b])+1))]];
        // return data.mins(min(index[a],index[b]),max(index[a],index[b])+1); Высота предка НАД a и b
    }
    NodesDist(){}
};
 
inline void solve(){
    int n;
    int q;
    cin >> n >> q;
    vvi G(n+1);
    incr(i,0,n-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }   
 
    NodesDist t;
    t.init(G);
    
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << t.query(a,b) << nl;
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