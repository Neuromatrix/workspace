#include <bits\stdc++.h>
#include <iterator>
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
    int n, m;
    cin >> n >> m;
    map<int, int> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[y] |= (1 << (x - 1));
    }
    const int FULL = 3;
    v[2e9] = FULL;
    int hasLast = 0, lastColor = 0;
    for (auto c : v) {
        auto x = c.first;
        auto mask = c.second ;
        if (mask != FULL && hasLast) {
        int color = (x + mask) % 2;
        if (lastColor == color) {
            cout << "NO\n";
            return;
        } else {
            hasLast = false;
        }
        } else if (mask == FULL && hasLast) {
            cout << "NO\n";
            return;
        } else if (mask != FULL) {
        lastColor = (x + mask) % 2;
        hasLast = true;
        }
    }
    cout << "YES\n";
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}