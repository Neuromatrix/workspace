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
ll n, t[4*100000];
void build (vc <ll> a, ll v, ll tl, ll tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		ll tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
	}
}
 
void push (ll v) {
	if (t[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		t[v] = -1;
	}
}
 
void update (ll v, ll tl, ll tr, ll l, ll r, ll color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push (v);
		ll tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), color);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
	}
}
 
ll get (ll v, ll tl, ll tr, ll pos) {
	if (tl == tr)
		return t[v];
	push (v);
	ll tm = (tl + tr) / 2;
	if (pos <= tm)
		return get (v*2, tl, tm, pos);
	else
		return get (v*2+1, tm+1, tr, pos);
}
inline void solve(){
    ll d;
    cin >> n >> d;
    vc <ll> data;
    seev(data,n);
    int step = data[0]/(d)+1;
    incr(i,1,n){
        if(i+1<=step){
            int t = data[i]/d + i + 1;
            if(step<t){
                step = t;
            }
        } else break;
    }
    if(step>n) step = n;
    cout << step << nl;
//     vc <ll> visited(n,0);
//     build(visited,1,0,n-1);
//     incr(i,0,n){
//         ll step = data[i]/d;
//         if(get(1,0,n-1,i)>0 || i==0) update(1,0,n-1,i,min(i+step,n-1),1);
//         else continue;
//     }
//     decr(i,n-1,-1){
//         if(get(1,0,n-1,i)>0){
//             cout << i+1 << nl;
//             return;
//         }
//     }
//     return;
 }
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}