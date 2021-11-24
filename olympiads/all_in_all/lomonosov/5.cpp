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
bool cmp(pii a, pii b){
    if(a.second==b.second){
        if(a.first>b.first) return false;
        else return true;
    }
    else if(a.second>b.second) return false;
    else return true;
}
map <int,int> factoriz_with_map(int N){ 
    map <int,int> f;
    for(int i = 2; i * i <= N; i++){
        while(N%i == 0){
            f[i]++;
            N/=i;
        }
    }
    if (N > 1) f[N]++;
    return f;
}
inline void solve(){
    vii data;
    incr(i,0,100){
        int a, b;
        cin >> a >> b;
        data.pb({a,b});
    }
    sort(all(data),cmp);
    fca(it,data){
        cout << it.S << " " << " === ";
        map <int, int> fac = factoriz_with_map(it.S);
        fca(x,fac) cout << x.first <<"^" <<x.second << " ";
        cout << " -----> " << it.F << nl;
    }
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}

//pow2 => ind*3;
//div3 => ind-1
//end 4
//div6 = >ind+1
//end5 = > ind-1
//div10 => ind+1