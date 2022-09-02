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
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
bool cnt(pair<int,int> x, int n){
    if(n>=x.first and n<=x.second) return true;
    return false;
}
bool del(int n, int m){
    if(n%m) return false;
    else return true;
}
inline void solve(int && y){
    int a = 0;
    for (int  a = 1; a < 10000; a++)
    {
        bool ok = true;
        for (int x = 1; x <10000; x++){
            if(((del(x,2) <= ! del(x,5)) or (x+a>=90))==false) ok = false;
        }
        if (ok){
            cout << a << nl;
            return;
        }
    }
}
inline void solve(){
    for (int i = 0; i < 1000; i++){
        int a = i;
        bool ok = true;
        for (int x = 0; x < 1000; x++){
            for (int y = 0 ; y < 1000; y++){
                if((x>39 or y>26 or (2*x+4*y<a))==false) ok = false;
            }
        }
        if(ok) cout << a << nl;
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}