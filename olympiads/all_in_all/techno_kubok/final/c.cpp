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
multiset<ll> arr;
bool R(ll s){
    if(arr.size()==0) return false;
    if(arr.find(s)!=arr.end()){
        arr.erase(arr.find(s));
        return true;
    } else if(arr.find(s)==arr.end() and s<=1) return false;
    if(s&1){
        if(R(s/2+1) and R(s/2)) return true;
        else return false;
    } else{
        if(R(s/2) and R(s/2)) return true;
        else return false;
    }
}
inline void solve(){
    int n;
    cin >> n;
    ll s = 0;
    incr(i,0,n){
        int x;
        cin >> x;
        s+=x;
        arr.insert(x);
    }
    if(R(s)) cout << "YES" <<nl;
    else cout << "NO" << nl;
    
}
signed main(){
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}