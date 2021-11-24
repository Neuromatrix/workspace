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
ll abs_(ll x) {
    if (x < 0) return -x;
    else return x;
}
inline void solve(){
    int n;
    ll start, end;
    cin >> start >> end >> n;
    vc <ll> data;
    seev(data,n);
    sort(all(data));
    ll idiot = abs_(end - start);
    ll min_s = INF, min_e = INF;
    incr(i,0,n){
        min_s = min(min_s, abs_(max(data[i],start)-min(data[i],start)));
    }
    incr(i,0,n){
        min_e = min(min_e, abs_(max(data[i],end)-min(data[i],end)));
    }
    cout << min((min_s + min_e + 1),idiot) << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}