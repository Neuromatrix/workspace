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
string lcs(string a, string b){
    int n = a.size();
    int m = b.size();
    vvi data(n+1,vi(m+1));
    incr(i,0,n+1){
        incr(j,0,m+1){
            if(i==0 || j==0){
                data[i][j] = 0;
            } else if (a[i-1]!=b[j-1]){
                data[i][j] = 0;
            } else if(a[i-1]==b[j-1]){
                data[i][j] = data[i-1][j-1]+1;
            }
        }
    }
    int mx = -INF;
    int ii, jj;
    incr(i,0,n+1){
        incr(j,0,m+1){
            if(data[i][j]>mx){
                mx = data[i][j];
                ii = i;
                jj = j;
            }
        }
        
    }
    return a.substr(ii-mx,mx);
}
inline void solve(){
    lcs("SUBSEQUENCE", "SUBEUENCS");
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}