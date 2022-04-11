#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
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
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    vvi data(10,vi(10));
    incr(i,0,10){
        string x;
        cin >> x;
        incr(j,0,10){
            if(x[j]=='*') data[i][j] = 1;
            else data[i][j] = 0;
        }
    }
    fca(it, data){
        cout << it << endl;
    }
    ll cnt = 0;
    bool fl = 0;
    int n = 10;
    incr(x,0,n){
        incr(y,0,n){
            if(data[x][y]==1) continue;
            fl = false;
            int i = x, j = y;
            while (data[i+1][j]!=1){
                i++;
                if(i+1>=n){
                    cnt++;
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
            while (data[i][j+1]!=1){
                j++;
                if(j+1>=n){
                    cnt++;
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
            while (data[i-1][j]!=1){
                i--;
                if(i-1<0){
                    cnt++;
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
            while (data[i][j-1]!=1){
                j--;
                if(j-1<0){
                    cnt++;
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
            while (data[i-1][j]!=1){
                i--;
                if(i-1<0){
                    cnt++;
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
        }
    }
    cout << cnt << nl;
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}