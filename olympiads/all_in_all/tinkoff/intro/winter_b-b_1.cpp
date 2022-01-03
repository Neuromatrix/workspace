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
// #include <ext/rope>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
// template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
#define N 1024

int tree[N][N];
struct treeNode
{
    int par;   
    int depth; 
    int size; 
    int pos_segbase;
    int chain;
} node[N];
struct Edge
{
    int weight;
    int deeper_end;
} edge[N];
struct segmentTree
{
    int base_array[N], tree[6*N];
} s;
template <typename T>
class lseg_tree
{
    private:
        vector <T> tree;
        vector <T> mod; 
        int size_it = 0;
        void push(int v, int tl, int tr) {
            if (mod[v] != 0 && v * 2 + 1 < 4*size_it){
                mod[v * 2] = mod[v * 2 + 1] = mod[v];
                mod[v] = 0;
                int tm = (tl + tr) / 2;
                tree[v * 2] += (tm - tl + 1) * mod[v * 2];
                tree[v * 2 + 1] += (tr - tm) * mod[v * 2 + 1];
            }
        }
        void build (const vector <T> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }
        void update (int v, int tl, int tr, int l, int r, int val) {
            if (l <= tl && tr <= r) {
                tree[v] += val * (tr - tl + 1);
                mod[v] = val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
        T sum (int v, int tl, int tr, int l, int r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return 0;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return sum( v * 2, tl, tm, l, r)
                + sum(v * 2 + 1, tm + 1, tr, l, r);
        }
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
    public:
        
        void init(T a[]){
            vector <T> tmp(N);
            for (int i = 0; i < N; ++i){
                tmp[i] = a[i];
            }
            init(tmp);
        }
        T get(int pos){
            return sum(1,0,size_it-1,pos,pos);
        }
        void update(int l, int r, int add){
            update(1,0,size_it-1,l,r,add);
        }
        T sum(int l, int r){
            return sum(1,0,size_it-1,l,r);
        }
        lseg_tree(vector <T> a){
            init(a);
        }
        lseg_tree(){}
        void print(){
            incr(i,0,tree.size()){
                cout << tree[i] << " ";
            }
            cout << nl;
        }
};
void addEdge(int e, int u, int v, int w){
    tree[u-1][v-1] = e-1;
    tree[v-1][u-1] = e-1;
 
    edge[e-1].weight = w;
}
void dfs(int curr, int prev, int dep, int n){
    node[curr].par = prev;
    node[curr].depth = dep;
    node[curr].size = 1;
    for (int j=0; j<n; j++)
    {
        if (j!=curr && j!=node[curr].par && tree[curr][j]!=-1)
        {
            edge[tree[curr][j]].deeper_end = j;
            dfs(j, curr, dep+1, n);
            node[curr].size+=node[j].size;
        }
     }
}
void hld(int curr_node, int id, int *edge_counted, int *curr_chain,
         int n, int chain_heads[])
{
    if (chain_heads[*curr_chain]==-1)
        chain_heads[*curr_chain] = curr_node;
    node[curr_node].chain = *curr_chain;
    node[curr_node].pos_segbase = *edge_counted;
    s.base_array[(*edge_counted)++] = edge[id].weight;
    int spcl_chld = -1, spcl_edg_id;
    for (int j=0; j<n; j++)
      if (j!=curr_node && j!=node[curr_node].par && tree[curr_node][j]!=-1)
        if (spcl_chld==-1 || node[spcl_chld].size < node[j].size)
           spcl_chld = j, spcl_edg_id = tree[curr_node][j];
    if (spcl_chld!=-1)
      hld(spcl_chld, spcl_edg_id, edge_counted, curr_chain, n, chain_heads);
    for (int j=0; j<n; j++)
    {
      if (j!=curr_node && j!=node[curr_node].par &&
            j!=spcl_chld && tree[curr_node][j]!=-1)
      {
        (*curr_chain)++;
        hld(j, tree[curr_node][j], edge_counted, curr_chain, n, chain_heads);
      }
    }
}
lseg_tree <int> x;

void change(int u, int v, int val, int n, int chain_heads[],int mm)
{
    int chain_u, chain_v = node[v].chain, ans = 0;
 
    while (true)
    {
        chain_u = node[u].chain;
        if (chain_u==chain_v)
        {
            if (u==v);   //trivial
            else
              x.update(node[v].pos_segbase+1, node[u].pos_segbase, val);
            break;
        }
        else
        {
            x.update(node[chain_heads[chain_u]].pos_segbase,
                          node[u].pos_segbase,val);
 
            u = node[chain_heads[chain_u]].par;
        }
    }
}
int LCA(int u, int v, int n){
    int LCA_aux[n+5];
    if (node[u].depth < node[v].depth)
       swap(u, v);
    memset(LCA_aux, -1, sizeof(LCA_aux));
 
    while (u!=-1)
    {
        LCA_aux[u] = 1;
        u = node[u].par;
    }
    while (v)
    {
        if (LCA_aux[v]==1)break;
        v = node[v].par;
    }
 
    return v;
}

int RMQ(int qs, int qe, int n){
    if (qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }
    return x.sum(qs,qe);
}
int crawl_tree(int u, int v, int n, int chain_heads[])
{
    int chain_u, chain_v = node[v].chain, ans = 0;
 
    while (true)
    {
        chain_u = node[u].chain;
        if (chain_u==chain_v)
        {
            if (u==v);   //trivial
            else
              ans +=RMQ(node[v].pos_segbase+1, node[u].pos_segbase, n);
            break;
        }
        else
        {
            ans +=RMQ(node[chain_heads[chain_u]].pos_segbase,
                          node[u].pos_segbase, n);
 
            u = node[chain_heads[chain_u]].par;
        }
    }
 
    return ans;
}
int maxEdge(int u, int v, int n, int chain_heads[])
{
    int lca = LCA(u, v, n);
    int ans = crawl_tree(u, lca, n, chain_heads)+
                  crawl_tree(v, lca, n, chain_heads);
    return ans;
}
void change(int u, int v, int val, int n, int chain_heads[]){
    int lca = LCA(u, v, n);
    change(u,lca,val,n,chain_heads,0);
    change(v,lca,val,n,chain_heads,0);
}
 

void solve(){
    memset(tree, -1, sizeof(tree));
    
    int n;
    cin >> n;
    vii rribs;
    incr(i,1,n){
        int a, b;
        cin >> a>> b;
        addEdge(i, a, b, 0);
        rribs.pb({a,b});
    }
    int root = 0, parent_of_root=-1, depth_of_root=0;
    dfs(root, parent_of_root, depth_of_root, n);
    int chain_heads[N];
    memset(chain_heads, -1, sizeof(chain_heads));
    int edge_counted = 0;
    int curr_chain = 0;
    hld(root, n-1, &edge_counted, &curr_chain, n, chain_heads);
    x.init(s.base_array);
    int m;
    cin >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        change(u-1, v-1,1, n,chain_heads);
    }
    int result = 0;
    incr(i,0,n-1){
        int u = rribs[i].first, v = rribs[i].second;
        if(!maxEdge(u-1, v-1, n, chain_heads)){
            result++;
        }
    }
    cout << result << nl;
}
// inline void solve() {
//     memset(tree, -1, sizeof(tree));
 
//     int n;
//     cin >> n;
//     vii rribs;
//     incr(i,1,n){
//         int a, b;
//         cin >> a>> b;
//         addEdge(i, a, b, 0);
//         rribs.pb({a,b});
//     }
//     int root = 0, parent_of_root=-1, depth_of_root=0;
//     dfs(root, parent_of_root, depth_of_root, n);
//     int chain_heads[N];
//     memset(chain_heads, -1, sizeof(chain_heads));
//     int edge_counted = 0;
//     int curr_chain = 0;
//     hld(root, n-1, &edge_counted, &curr_chain, n, chain_heads);
//     x.init(s.base_array);
//     int u = 1, v  = 2; 
//     cout << "Max edge between " << u << " and " << v << " is ";
//     maxEdge(u-1, v-1, n, chain_heads);
//     // // change(u-1, v-1,1, n,chain_heads);
 
//     // cout << "After Change: max edge between " << u << " and "
//     //      << v << " is ";
//     // maxEdge(u-1, v-1, n, chain_heads);
 
//     // v = 2; u = 8;
//     // cout << "Max edge between " << u << " and " << v << " is ";
//     // maxEdge(u-1, v-1, n, chain_heads);
//     // cout << "After Change: max edge between " << u << " and "
//     //      << v << " is ";
//     // change(u-1, v-1,1, n,chain_heads);
//     // maxEdge(u-1, v-1, n, chain_heads);
// }
signed main(){
    
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}