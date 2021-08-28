#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
bool check_res__0(int a,int b, int k,int n){
    int mid = n/2;
    k = max(k,k-mid);
    if (a-k==b+k || a+k==b-k) return true;
    else return false;
}
bool check_res__1(int a,int b, int k,int n){
    n--;
    int mid = n/2;
    k = max(k,k-mid);
    if (a-k+1==b+k || a+k-1==b-k) return true;
    else return false;
}
inline void solve(){
    int a, b;
    cin >> a >> b;
    int n = a + b;
    if (n%2==0){
        incr(i,0,n+1){
            if(check_res__0(a,b,i,n)) cout << i << " ";
        }
        cout << nl;
    } else {
        incr(i,0,n+1){
            if(check_res__1(a,b,i,n)) cout << i << " ";
        }
        cout << nl;
    }
    return;
}

int main(){
    IOS;
    prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}