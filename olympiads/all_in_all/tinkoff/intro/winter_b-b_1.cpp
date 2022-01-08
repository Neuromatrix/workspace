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
constexpr int N  = 100005;
vvi adj;
vii tree[N];
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
struct tmp
{
    int base_array[N];
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
        
        void init(T a[],int n){
            vector <T> tmp(n);
            for (int i = 0; i < n; ++i){
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
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;
    void init(vector<vector<int>> &adj, int root = 0){
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
void addEdge(int e, int u, int v, int w){
    tree[u-1].pb({v-1,e-1});
    tree[v-1].pb({u-1,e-1});
    adj[u-1].pb(v-1);
    adj[v-1].pb(u-1);
    edge[e-1].weight = w;
}
void dfs(int cur, int prev, int dep, int n){
    node[cur].par = prev;
    node[cur].depth = dep;
    node[cur].size = 1;
    fca(it,tree[cur]){
        int j = it.first;
        int rib = it.second;
        if (j!=cur && j!=node[cur].par && j!=prev){
            edge[rib].deeper_end = j;
            dfs(j, cur, dep+1, n);
            node[cur].size+=node[j].size;
        }
    }
}
//!!some implementations were taken from the site https://www.geeksforgeeks.org/ 
//!!this site is educational like https://e-maxx.ru/algo/
// ^_^
void hld(int cur_node, int id, int *edge_counted, int *cur_chain, int n, int heads[])
{
    if (heads[*cur_chain]==-1)
        heads[*cur_chain] = cur_node;
    node[cur_node].chain = *cur_chain;
    node[cur_node].pos_segbase = *edge_counted;
    s.base_array[(*edge_counted)++] = edge[id].weight;
    int spcl_chld = -1, spcl_edg_id;
    fca(it,tree[cur_node]){
        int j = it.first;
        int rib = it.second;
        if (j!=cur_node && j!=node[cur_node].par)
            if (spcl_chld==-1 || node[spcl_chld].size < node[j].size)
                spcl_chld = j, spcl_edg_id = rib;
    }
    if (spcl_chld!=-1)
        hld(spcl_chld, spcl_edg_id, edge_counted, cur_chain, n, heads);
    fca(it,tree[cur_node]){
        int j = it.first;
        int rib = it.second;
        if (j!=cur_node && j!=node[cur_node].par && j!=spcl_chld){
            (*cur_chain)++;
            hld(j, rib, edge_counted, cur_chain, n, heads);
        }
    }
}
lseg_tree <int> x;
LCA fasCA;
void change(int u, int v, int val, int n, int heads[],int mm){
    int chain_u, chain_v = node[v].chain, ans = 0;
    for(;;){
        chain_u = node[u].chain;
        if (chain_u==chain_v){
            if (u==v) {/*pass*/}
            else x.update(node[v].pos_segbase+1, node[u].pos_segbase, val);
            break;
        }
        else{
            x.update(node[heads[chain_u]].pos_segbase,node[u].pos_segbase,val);
            u = node[heads[chain_u]].par;
        }
    }
}

int query(int qs, int qe, int n){
    return x.sum(qs,qe);
}
void upd_color(int u, int v, int val, int n, int heads[]){
    int lca = fasCA.lca(u,v);
    change(u,lca,val,n,heads,0);
    change(v,lca,val,n,heads,0);
}

void solve(){
    
    int n;
    cin >> n;
    adj.resize(n);
    incr(i,1,n){
        int a, b;
        cin >> a>> b;
        addEdge(i, a, b, 0);
    }
    fasCA.init(adj);
    int root = 0, parent_of_root=-1, depth_of_root=0;
    dfs(root, parent_of_root, depth_of_root, n);
    int heads[N];
    memset(heads, -1, sizeof(heads));
    int edge_counted = 0;
    int cur_chain = 0;
    hld(root, n-1, &edge_counted, &cur_chain, n, heads);
    x.init(s.base_array,n);
    int m;
    cin >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        upd_color(u-1, v-1,1, n,heads);
    }
    int result = 0;
    incr(i,1,n){
        if(!x.get(i)){
            result++;
        }
    }
    cout << result << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}