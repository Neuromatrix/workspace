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

inline void solve(){
    ll n, h , w;
    ll counter = 1;
    cin >> w >> h >> n;
    if (h & 1 && w & 1){
        if (counter<n) cout << "NO" << nl;
        else cout << "YES" <<nl;
    }
    else if (!(h & 1) && (w & 1)){
        while(h%2==0){
            h/=2;
            counter*=2;
        }
        if (counter<n) cout << "NO" << nl;
        else cout << "YES" <<nl;
    }
    else if ((h & 1) && !(w & 1)){
        while(w%2==0){
            w/=2;
            counter*=2;
        }
        if (counter<n) cout << "NO" << nl;
        else cout << "YES" <<nl;
    }
    else{
        while(w%2==0){
            w/=2;
            counter*=2;
        }
        while(h%2==0){
            h/=2;
            counter*=2;
        }
        if (counter<n) cout << "NO" << nl;
        else cout << "YES" <<nl;
    }
    return;
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}