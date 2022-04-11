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
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    int n;
    int k = 43;
    cin >> n;
    vector <ll> prefsum(n+1);
    vector <ll> ppprefsum(n+1);
    vector <ll> data;
    incr(i,0,n){
        ll x;
        cin >> x;
        data.pb(x);
    }
    prefsum[0] = 0;
    
    incr(i,1,n+1){
        prefsum[i] = prefsum[i-1] + data[i-1];
        
    }

    incr(i,0,n+1){
        ppprefsum[i]= prefsum[i]%k;
        
    }
    
    vector <ll> st(44,INF);
    vector <ll> en(44,0);
    cout << prefsum <<nl;
    incr(i,1,n+1){
        st[ppprefsum[i-1]] = min(i,st[ppprefsum[i-1]]);
    }
    incr(i,1,n+1){
        en[ppprefsum[i-1]] = max(i  ,en[ppprefsum[i-1]]);
    }
    ll mx = 0;
    ll mxlen = 0;
    cout << st << nl;
    cout << en << nl;
    incr(i,0,43){
        if(mx<=prefsum[en[i]+1]-prefsum[st[i]]){
            mx = prefsum[en[i]+1]-prefsum[st[i]];
            mxlen = en[i]-st[i];
        }
            
    }
    cout << mxlen << nl;
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}