#include <bits\stdc++.h>
#include <ext/rope>




using namespace std;
using ll = long long;
using ld = long double;
constexpr char nl = '\n';
constexpr ld eps = 1e-9;
constexpr ll MOD = 0;
constexpr ll INF = INT_MAX-1;
#define incr(i,a,b) for(ll i = a; i < b; i++) 
#define vi vector <int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    int n;
    cin >> n;
    vector<ll> data(n);
    incr(i,0,n){
        cin >> data[i];
    }
    sort(rall(data));
    cout << data[0] + data[1] << nl;
}
signed main(){
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}