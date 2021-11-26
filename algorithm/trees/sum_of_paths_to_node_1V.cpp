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
template <typename T>
class lseg_tree
{
    private:
        vector <T> tree;
        vector <T> mod; 
        ll size_it = 0;
        void push(ll v, ll tl, ll tr) {
            if (mod[v] != 0 && v * 2 + 1 < 4*size_it){
                mod[v * 2] = mod[v * 2 + 1] = mod[v];
                mod[v] = 0;
                ll tm = (tl + tr) / 2;
                tree[v * 2] += (tm - tl + 1) * mod[v * 2];
                tree[v * 2 + 1] += (tr - tm) * mod[v * 2 + 1];
            }
        }
        void build (const vector <T> &a, ll v, ll tl, ll tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                ll tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }
        void update (ll v, ll tl, ll tr, ll l, ll r, ll val) {
            if (l <= tl && tr <= r) {
                tree[v] += val * (tr - tl + 1);
                mod[v] = val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            ll tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
        T sum (ll v, ll tl, ll tr, ll l, ll r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return 0;
            }
            push(v, tl, tr);
            ll tm = (tl + tr) / 2;
            return sum( v * 2, tl, tm, l, r)
                + sum(v * 2 + 1, tm + 1, tr, l, r);
        }
    public:
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
        T get(ll pos){
            return sum(1,0,size_it-1,pos,pos);
        }
        void update(ll l, ll r, ll add){
            update(1,0,size_it-1,l,r,add);
        }
        T sum(ll l, ll r){
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
class sum_of_paths
{
private:
    ll n;
    vector <ll> ksum;
    vector <ll> counter;
    map <ll, ll> index;
    vector <vector <ll>> G;
    vector <ll> id;
    lseg_tree <ll> io;
    vector <ll> to_sum;
    vector <ll> now;
    inline void dfs(ll cur, ll prev,vector <ll> &sum){
        to_sum[cur] = to_sum[prev]+sum[cur];
        id.push_back(cur);
        counter[cur] = 1;
        for(const auto & nex: G[cur]){
            if(nex==prev) continue;
            dfs(nex,cur,sum);
            counter[cur]+=counter[nex];
    }
}
public:
    void init(vector <vector <ll>> &gr,vector <ll> &ssum){
        G = gr;
        n = G.size();
        counter.resize(n);
        now = ssum;
        id.push_back(0);
        ksum.resize(n);
        to_sum.resize(n);
        dfs(1,0,ssum);
        for (size_t i = 1; i < n; i++){
            index[id[i]] = i;
        }
        for (size_t i = 1; i < n; i++){ 
            ksum[index[i]] = to_sum[i];
        }
        io.init(ksum);
    }
    ll query(ll s){
        return io.get(index[s]);//,index[s]+counter[s]-1
    }
    void change(ll s, ll x){
        
        io.update(index[s],index[s]+counter[s]-1, - now[s] + x);
        now[s] = x;
    }
    sum_of_paths(/* args */){}
};
inline void solve(){
    ll n, q;
    cin >> n >> q;
    vector <ll> sum(n+1);
    for (size_t i = 1; i <= n; i++){
        cin >> sum[i];
    }
    vc <vc <ll>> G(n+1);
    incr(i,0,n-1){
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    } 
    sum_of_paths h;
    h.init(G,sum);
    while (q--){
        ll comm;
        cin >> comm;
        if(comm==2){
            ll s;
            cin >> s;
            cout << h.query(s) << nl;
        } else {
            ll s, x;
            cin >> s >> x;
            h.change(s,x);
        }
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