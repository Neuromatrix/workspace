#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
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
    int n;
    cin >> n;
    vi data;
    seev(data,n);
    ll ans = 0;
    incr(i,0,n){
        if(data[i]>1){
            ans+=data[i]-1;
            data[i]=1;
        } else if(data[i]<-1){
            ans+=abs(data[i])-1;
            data[i]=-1;
        }
    }
    int zero = count(all(data),0);
    if(zero>0){
        cout << ans + zero << nl;
    } else {
        int min_one = count(all(data),-1);
        if(min_one & 1){
            cout << ans + 2 << nl;
        } else {
            cout << ans << nl;
        }
    }
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}