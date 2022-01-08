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
// constexpr int INF = INT_MAX-1;
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
class BEATS{
    public:
    static const int T = (40004);
    static const int INF = 1e9 + 7;
 
    struct Node {
        int max;
        long long sum;
    } tree[T];
 
    int n;
 
    inline void push(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].max = max(tree[2 * v].max, tree[2 * v + 1].max);
    }
 
    inline void init(int v, int l, int r, const vector<int>& inputArray) {
        if (l + 1 == r) {
            tree[v].max = tree[v].sum = inputArray[l];
        } else {
            int mid = (r + l) / 2;
            init(2 * v, l, mid, inputArray);
            init(2 * v + 1, mid, r, inputArray);
            push(v);
        }
    }
 
    inline void init(const vector<int>& inputArray) {
        n = inputArray.size();
        init(1, 0, n, inputArray);
    }
 
    inline void upd_seg(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql || tree[v].max < val) {
            return;
        }
        if (l + 1 == r) {
            tree[v].max %= val;
            tree[v].sum = tree[v].max;
            return;
        }
        int mid = (r + l) / 2;
        upd_seg(2 * v, l, mid, ql, qr, val);
        upd_seg(2 * v + 1, mid, r, ql, qr, val);
        push(v);
    }
 
    inline void upd_seg(int ql, int qr, int val) {
        upd_seg(1, 0, n, ql, qr, val);
    }
 
    inline void upd_o(int v, int l, int r, int qi, int val) {
        if (l + 1 == r) {
            tree[v].max = tree[v].sum = val;
            return;
        }
        int mid = (l + r) / 2;
        if (qi < mid) {
            upd_o(2 * v, l, mid, qi, val);
        } else {
            upd_o(2 * v + 1, mid, r, qi, val);
        }
        push(v);
    }
 
    inline void upd_o(int qi, int val) {
        upd_o(1, 0, n, qi, val);
    }
 
    inline long long findSum(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tree[v].sum;
        }
        int mid = (r + l) / 2;
        return findSum(2 * v, l, mid, ql, qr) + findSum(2 * v + 1, mid, r, ql, qr);
    }
 
    inline long long findSum(int ql, int qr) {
        return findSum(1, 0, n, ql, qr);
    }
};
struct JiDriverSegmentTree {
    static const int T = (400004);
    static const int INF = 1e9 + 7;
 
    struct Node {
        int max;
        long long sum;
    } tree[T];
 
    int n;
 
    inline void updateFromChildren(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].max = max(tree[2 * v].max, tree[2 * v + 1].max);
    }
 
    inline void build(int v, int l, int r, const vector<int>& inputArray) {
        if (l + 1 == r) {
            tree[v].max = tree[v].sum = inputArray[l];
        } else {
            int mid = (r + l) / 2;
            build(2 * v, l, mid, inputArray);
            build(2 * v + 1, mid, r, inputArray);
            updateFromChildren(v);
        }
    }
 
    inline void build(const vector<int>& inputArray) {
        n = inputArray.size();
        build(1, 0, n, inputArray);
    }
 
    inline int updateModEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr && tree[v].max < val) {
            return tree[v].sum;
        }
        if (l + 1 == r) {
            return tree[v].sum % val;
        }
        int mid = (r + l) / 2;
        updateFromChildren(v);
        return  updateModEq(2 * v, l, mid, ql, qr, val)+
        updateModEq(2 * v + 1, mid, r, ql, qr, val);
    }
 
    inline int updateModEq(int ql, int qr, int val) {
        return updateModEq(1, 0, n, ql, qr, val);
    }
} segTree;
int n, q;
map <tuple<int, int, int> ,int> answers;
unordered_map <int, vii> questions;
inline void solvemod(BEATS data, int x){
    vii qu = questions[x];
    data.upd_seg(0,n,x);
    fca(it,qu){
        answers[{it.first,it.second,x}] = data.findSum(it.first-1,it.second);
    }
    return;
}
BEATS datab;

inline void solve(int io){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> q;
    vector<int> inputArray(n);
    for (int &val : inputArray) {
        cin >> val;
    }
    vc <tuple<int, int, int>> inp;
    incr(i,0,q){
        int a, b,w;
        cin >> a>> b >>w;
        inp.push_back({a,b,w});
        questions[w].push_back({a,b});
    }
    if(/*pw(questions.size())<=n*4*/ io){
        
        datab.init(inputArray);
        fca(it,questions){
            solvemod(datab,it.first);
        }
        fca(it,inp){
            // cout << answers[it] << nl;
        }
    } else {
        segTree.build(inputArray);
        fca(it,inp){
            int ql, qr, x;
            tie(ql,qr,x) = it;
            ql--;
            // cout << segTree.updateModEq(ql, qr, x)<< nl;
        }
    }
    
}
void pp(int && rand){
    clock_t start = clock();
    int n = 1e8;
    ll x = 0;
    incr(i,1,n){
        //for(int j = 0; j < n; j+=i){
            x++;
        //}
    }
    cout << x << nl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << seconds << nl;
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) pp(1);
    return 0;
}