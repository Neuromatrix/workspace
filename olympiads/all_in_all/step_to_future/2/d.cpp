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
template <typename T> inline T abss(T x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.fi << " " << v.se;return out;}
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
int t[4*22][4*22],tt[4*22][4*22],ttt[4*22][4*22];
vvi a;
int n, m;
void mmbuild_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = min(t[vx*2][vy],t[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		mmbuild_y (vx, lx, rx, vy*2, ly, my);
		mmbuild_y (vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}
 
void mmbuild_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		mmbuild_x (vx*2, lx, mx);
		mmbuild_x (vx*2+1, mx+1, rx);
	}
	mmbuild_y (vx, lx, rx, 1, 0, m-1);
}
int mmin_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return max(mmin_y (vx, vy*2, tly, tmy, ly, min(ry,tmy)),
		mmin_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}
 
int mmin_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return mmin_y (vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return max(mmin_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		 ,mmin_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}
void mbuild_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = min(t[vx*2][vy],t[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		mbuild_y (vx, lx, rx, vy*2, ly, my);
		mbuild_y (vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}
 
void mbuild_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		mbuild_x (vx*2, lx, mx);
		mbuild_x (vx*2+1, mx+1, rx);
	}
	mbuild_y (vx, lx, rx, 1, 0, m-1);
}
int min_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return min(min_y (vx, vy*2, tly, tmy, ly, min(ry,tmy)),
		min_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}
 
int min_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return min_y (vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return min(min_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		 ,min_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}
void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			tt[vx][vy] = (a[lx][ly] < 0 ? 0 : a[lx][ly]);
		else
			tt[vx][vy] = tt[vx*2][vy] + tt[vx*2+1][vy];
	else {
		int my = (ly + ry) / 2;
		build_y (vx, lx, rx, vy*2, ly, my);
		build_y (vx, lx, rx, vy*2+1, my+1, ry);
		tt[vx][vy] = tt[vx][vy*2] + tt[vx][vy*2+1];
	}
}
 
void build_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x (vx*2, lx, mx);
		build_x (vx*2+1, mx+1, rx);
	}
	build_y (vx, lx, rx, 1, 0, m-1);
}

int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return tt[vx][vy];
	int tmy = (tly + try_) / 2;
	return sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		+ sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}
 
int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		+ sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
}
inline bool check(int x1, int x2, int y1, int y2,int x3, int x4, int y3, int y4,int minn){
    if(y1>0){
        if(mmin_x(1,0,n-1,x1,x4,y1-1,y1-1)>=minn) return false;
    }
    if(x1>0){
        if(mmin_x(1,0,n-1,x1-1,x1-1,y1,y3)>=minn) return false;
    }
    if(x4<n-1){
        if(mmin_x(1,0,n-1,x4+1,x4+1,y1,y3)>=minn) return false;
    }
    if(y2<m-1){
        if(mmin_x(1,0,n-1,x1,x4,y4+1,y4+1)>=minn) return false;
    }
    return true;
}
inline void solve(){
     int k;
    cin >> n >> m >> k;
    a.resize(n);

    incr(i,0,n){
        a[i].resize(m);
        incr(j,0,m){
            cin >> a[i][j];
        }
    }
    map <int, pair<pii,pii>> data;
    mmbuild_x(1,0,n-1);
    mbuild_x(1,0,n-1);
    build_x(1,0,n-1);
    // cout << min_x(1,0,n-1,0,1,0,1) << nl;
    incr(x1,0,n){
        incr(y1,0,m){
            incr(x2,0,n){
                incr(y2,0,m){
                    ll x3 = x1, y3 = y2;
                    ll x4 = x2, y4 = y1;
                    int ele = (abss(x3-x1)+1)*(abss(y2-y4)+1);
                    if(sum_x(1,0,n-1,x1,x2,y1,y2)/ele>k){
                        if(check( x1,  x2,  y1,  y2, x3,  x4,  y3,  y4, min_x(1,0,n-1,x1,x2,y1,y2))){
                            data[ele] = {{x1+1,y1+1},{x2+1,y2+1}};
                        }
                    }
                }
            }
        }
    }
    cout << (*prev(data.end())).second.first.first << " " << (*prev(data.end())).second.first.second <<
    " " << (*prev(data.end())).second.second.first << " " << (*prev(data.end())).second.second.second << nl;

}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}