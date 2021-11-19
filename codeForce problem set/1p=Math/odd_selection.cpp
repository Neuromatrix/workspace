#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
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
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (int i=a; i<b; ++i)
#define decr(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    int n, x;
    cin >> n >> x;
    vi data;
    seev(data,n);
    int sum = 0;
    int fch = 0, fnch = 0;
    incr(i,0,x-1){
        sum+=data[i];
        if(data[i] & 1) fnch++;
        else fch++;
    }
    sum%=2;
    int ch = 0, nch = 0;
    incr(i,x-1,n){
        if(data[i] & 1) nch++;
        else ch++;
    }
    if(sum==1 && ch>0) cout << "Yes" << nl;
    else if(sum==0 && nch>0) cout <<"Yes" << nl;
    else if(sum==0 && ch>1 && fnch>0) cout << "Yes" << nl;
    else if(sum==1 && nch>1 && fch>0) cout << "Yes" << nl;
    else cout << "No" << nl; 
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}