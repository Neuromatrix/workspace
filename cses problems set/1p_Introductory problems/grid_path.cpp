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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
T pow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
bool valid(int i, int j, int vis[7][7]){
    if(i<0 || i>6 || j<0 || j>6) return false;
    if(vis[i][j]) return false;
    return true;
}
int n = 7;
bool visited[7][7];
int reserved[49];

void move(int r, int c, int &ans, int &steps)
{
    if (r == n - 1 && c == 0){
        ans += (steps == n * n - 1);
        return;
    }
    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;
    visited[r][c] = true;
    if (reserved[steps] != -1){
        switch (reserved[steps]){
        case 0:
            if (r - 1 >= 0){
                if (!visited[r - 1][c]){
                    steps++;
                    move(r - 1, c, ans, steps);
                    steps--;
                }
            }
            break;
        case 1:
            if (c + 1 < n){
                if (!visited[r][c + 1]){
                    steps++;
                    move(r, c + 1, ans, steps);
                    steps--;
                }
            }
            break;
        case 2:
            if (r + 1 < n){
                if (!visited[r + 1][c]){
                    steps++;
                    move(r + 1, c, ans, steps);
                    steps--;
                }
            }
            break;
        case 3:
            if (c - 1 >= 0){
                if (!visited[r][c - 1]){
                    steps++;
                    move(r, c - 1, ans, steps);
                    steps--;
                }
            }
            break;
        }
        visited[r][c] = false;
        return;
    }
    if (r + 1 < n){
        if (!visited[r + 1][c]){
            steps++;
            move(r + 1, c, ans, steps);
            steps--;
        }
    }
    if (c + 1 < n){
        if (!visited[r][c + 1]){
            steps++;
            move(r, c + 1, ans, steps);
            steps--;
        }
    }
    if (r - 1 >= 0){
        if (!visited[r - 1][c]){
            steps++;
            move(r - 1, c, ans, steps);
            steps--;
        }
    }
    if (c - 1 >= 0){
        if (!visited[r][c - 1]){
            steps++;
            move(r, c - 1, ans, steps);
            steps--;
        }
    }
    visited[r][c] = false;
}

inline void solve(){
    string path;
    cin >> path;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '?')
            reserved[i] = -1;
        else if (path[i] == 'U')
            reserved[i] = 0;
        else if (path[i] == 'R')
            reserved[i] = 1;
        else if (path[i] == 'D')
            reserved[i] = 2;
        else if (path[i] == 'L')
            reserved[i] = 3;
    }
    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}