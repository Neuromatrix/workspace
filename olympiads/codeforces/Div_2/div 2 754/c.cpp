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
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int ans = 0;
int n;
string ss;
inline void solve(){
    cin >> n;
    cin >> ss;
    n = ss.length();
    int min_dist = INF,now = 0;
    int ca = 0, cb = 0, cc = 0;
    incr(i,0,n){
        if(ss[i]=='c'){
            cc++;
        } else if (ss[i]=='b'){
            cb++;
        } else {
            ca++;
        }
        now++;
        if(cb>ca || cc>ca){
            now = 0;
            cb = 0, cc = 0, ca = 0;
        } else if(ca>cb && ca>cc && now>=2){
            min_dist = min(min_dist,now);
            now = 1;
            cb = 0, cc = 0, ca = 1;
        }
    }
    if(cb>=ca || cc>=ca) now = INF;
    ans = (min(min_dist,now < 2 ? INF : now) == INF ? -1 : min(min_dist,now < 2 ? INF : now));
    cout << ans << nl;
    
}
void idiot(){
    incr(i,0,n-ans+1){
        if(count(ss.begin()+i,ss.begin()+i+ans,'a')>count(ss.begin()+i,ss.begin()+i+ans,'b') && count(ss.begin()+i,ss.begin()+i+ans,'a')>count(ss.begin()+i,ss.begin()+i+ans,'c')){
            cout << "ACC" << nl;
            return;
        }
    }
    cout << "FAIL" << nl;
    cout << ss << " " << ans << nl;
}
void randstring(){
    string x;
    incr(i,0,200){
        if(x.back()!='a') x.push_back('a'+rand()%3);
    }
    cout << sz(x) << nl;
    cout << x << nl;
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) {solve(); idiot();}
    return 0;
}