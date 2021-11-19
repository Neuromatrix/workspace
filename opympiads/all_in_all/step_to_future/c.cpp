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
constexpr ll MOD = 1000000007;
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
#define rall(x) x.rbegin(),x.rend()
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
int arr[2005][2005];
int possible[2005][2005];
vii moves = {{0,-1},{0,1},{1,0},{-1,0}};
bool valid(int i, int j){
    if(i<0 || i >2000  || j <0 || j>2000) return false;
    if (possible[i][j]) return false;
    if (arr[i][j]) return true;
    return false;
}
ll ans = 0;
void dfs(int i,int j){
    possible[i][j] = true;
    fca(it, moves){
        if (valid(i+it.first, j+it.second)){
            dfs(i+it.first, j+it.second);
            ans++;
        }
    }
}
inline void solve(){
    int n;
    cin >> n;
    incr(i,0,n){
        int x1,y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=1000;
        x2+=1000;
        y1+=1000;
        y2+=1000;
        incr(i,x1,x2){
            incr(j,y1,y2){
                arr[i][j] = 1;
            }
        }
    }
    ll op = -INF;
    incr(i,0,2001){
        incr(j,0,2001){
            if(arr[i][j]==1){
                dfs(i,j);
                op = max(op,ans+1);
                ans = 0;
            }
        }
    }
    cout << op << nl;

}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}