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
template <typename T>
class lseg_tree
{
    private:
        vector <T> tree;
        vector <T> mod; 
        int size_it = 0;
        void push(int v, int tl, int tr) {
            tree[v*2] += mod[v];
            mod[v*2] += mod[v];
            tree[v*2+1] += mod[v];
            mod[v*2+1] += mod[v];
            mod[v] = 0;
        }
        void build (const vector <T> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = max(tree[v * 2],tree[v * 2 + 1]);
            }
        }
        void update (int v, int tl, int tr, int l, int r, int val) {
            if (l <= tl && tr <= r) {
                tree[v] += val;
                mod[v] += val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = max(tree[v * 2],tree[v * 2 + 1]);
        }
        T maximum(int v, int tl, int tr, int l, int r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return -INF;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return max(maximum( v * 2, tl, tm, l, r)
                ,maximum(v * 2 + 1, tm + 1, tr, l, r));
        }
    public:
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
        void update(int l, int r, int add){
            update(1,0,size_it-1,l,r,add);
        }
        T maximum(int l, int r){
            return maximum(1,0,size_it-1,l,r);
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


inline void solve(){
    int n;
    cin >> n;
    vc<ll> data;
    seev(data,n);
    
    lseg_tree <ll> tr(data);
    int q;
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        if(c=='a'){
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            tr.update(l,r,x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << tr.maximum(l,r) << nl;
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