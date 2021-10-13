// https://cses.fi/problemset/task/1192
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
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
#define incr(i,a,b) for (int i=a; i<b; ++i)
#define decr(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int n, m;
vc <vc <bool>> possible;
vii moves = {{0,-1},{0,1},{1,0},{-1,0}};
bool valid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    if (possible[i][j]) return false;
    return true;
}
void dfs(int i,int j){
    possible[i][j] = true;
    fca(it, moves){
        if (valid(i+it.first, j+it.second)){
            dfs(i+it.first, j+it.second);
        }
    }
}
inline void solve(){
    cin >> n >> m;
    vc <string> data(n);
    int ans = 0;
    incr(i,0,n){
        cin >> data[i];
    }
    possible.resize(n);
    incr(i,0,n){
        possible[i].resize(m);
        incr(j,0,m){
            if(data[i][j]=='#') possible[i][j] = true;
            else false;
        }
    }
    incr(i,0,n){
        incr(j,0,m){
            if(!possible[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << nl;
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}