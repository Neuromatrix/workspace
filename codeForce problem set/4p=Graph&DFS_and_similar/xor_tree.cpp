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
const int N=100100;
vector<int> g[N],v;
int n,f[N];
void go(int a,int p,int q,int b=0)
{
  if(p^f[a])
    v.push_back(a),p^=1;
  for(int i=0;i<g[a].size();++i)
    if(g[a][i]!=b)
        go(g[a][i],q,p,a);
}
inline void solve(){
    cin>>n;
    for(int i=1,a,b;i<n&&cin>>a>>b;++i)
            g[a].push_back(b),g[b].push_back(a);
    for(int i=1;i<=n;++i)
            cin>>f[i];
    for(int i=1,x;i<=n&&cin>>x;++i)
            f[i]^=x;
    go(1,0,0);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;

}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}