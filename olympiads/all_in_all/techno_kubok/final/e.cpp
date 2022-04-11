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
#define fca(it,s) for(const auto &it : s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    int n;
    cin >> n;
    vi data(n);
    incr(i,0,n){
        cin >> data[i];
    }
    vector <pair<ld,ld>> pt;
    incr(i,1,n){
        pt.push_back({data[i],data[i-1]});
    }
    int mn = n-2;
    map <ld,int> cnt;
    incr(i,0,1e3){
        fca(it,pt){
        ld x = (it.first-i)/it.second;
        cnt[x]++;
    }
    }
    
    fca(it,cnt){
        cout << it.first << " " << it.second << nl; 
        mn = min(n-it.second,mn);
    }
    cout << mn << nl;
}
signed main(){
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}