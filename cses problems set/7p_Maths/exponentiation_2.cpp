// https://cses.fi/problemset/task/1712
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
ull binPow(ull a, ull pow,ull mod){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a%=mod;
	} else {
		ull part = binPow(a, pow >> 1,mod)%mod;
		if (pow & 1) {
			return (((part * part)%mod) * a)%mod;
		} else {
			return (part * part)%mod;
		}
	}
}
inline void solve(){
    ull a, b, c;
    cin >> a >> b >> c;
    cout << binPow(a,binPow(b,c,1e9+6),1e9+7)<< nl;
    return;
}

int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}