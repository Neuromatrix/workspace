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
int n, m;
int sx , sy, ex,ey;
vii monsters;
vvi G;
vc <vc <bool>> Npossible;
vii moves = {{-1,0},{0,-1},{1,0},{0,1}};
bool valid(int x, int y, int t){
    if(x<0 or x>=n or y<0 or y>=m) return false;
    if(Npossible[x][y]) return false;
    if(G[x][y]<= t) return false;
    return true;
}
bool end(int x, int y,int timer){
    if(!valid(x,y,timer)) return false;
    if(x==n-1 or x==0 or y==m-1 or y==0) return true;
    return false;
}
map<pair<int,int>, pair<int,int>> par_mp;
bool bfs2d(){
    queue <tuple<int, int, int> > q;
    int timer, x, y;
    q.push({0,sx,sy});
    G[sx][sy] = 0;
    par_mp[{sx,sy}] = {-1,-1};
    while (!q.empty()){
        tie(timer,x,y) = q.front();
        q.pop();
        timer++;
        fca(it, moves){
            int nx = x+it.first;
            int ny = y+it.second;
            if(end(nx,ny,timer)){
                par_mp[{nx,ny}] = {x,y};
                ex = nx; ey = ny;
                return true;
            } if (valid(nx, ny, timer)){
                par_mp[{nx,ny}] = {x,y};
                q.push({timer,nx,ny});
                G[nx][ny] = timer;
            }
        }
        
    }
    return false;
}
void mosterbfs(){
    queue <tuple<int, int, int> > q;
    fca(it,monsters){
        q.push({0,it.first,it.second});
        G[it.first][it.second] = 0;
    }
    int timer, x, y;
    while (!q.empty()){
        tie(timer,x,y) = q.front();
        q.pop();
        timer++;
        fca(it, moves){
            int nx = it.first;
            int ny = it.second;
            if(valid(x+nx,y+ny,timer)){
                q.push({timer,x+nx,y+ny});
                G[x+nx][y+ny] = timer;
            }
        }
    }
    
}
inline void solve(){
    cin >> n >> m;
    G.resize(n);
    Npossible.resize(n);
    incr(i,0,n){
        G[i].assign(m,INF);
        Npossible[i].resize(m);
        incr(j,0,m){
            char c;
            cin >> c;
            if(c=='#') Npossible[i][j] = true;
            if(c=='A') {sx = i; sy = j;}
            if(c=='M') monsters.push_back({i,j});
        }
    }
    if(sx == 0 or sy == 0 or sx == n-1 or sy == m-1) 
    {
        cout << "YES" << endl;
        cout << 0;
        return;
    }
    mosterbfs();
    if(bfs2d()) {
    
        cout << "YES" << nl;
        pair<int,int> tmp = {ex,ey};
        pair<int,int> tmp1 = par_mp[{ex,ey}];
        pair<int,int> ed = {-1,-1}; 
        string ans;
        while(tmp1 != ed){
            if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
            {
            ans.push_back('R');
            }
            if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
            {
            ans.push_back('L');
            }
            if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
            {
            ans.push_back('D');
            }
            if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
            {
            ans.push_back('U');
            }
            tmp = par_mp[tmp];
            tmp1 = par_mp[tmp];
        }
        reverse(all(ans));
        cout << ans.size() << nl;
        cout << ans  << nl;
    } else {
        cout <<"NO" << nl;
    }
    
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}