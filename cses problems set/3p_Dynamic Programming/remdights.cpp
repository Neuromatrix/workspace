// https://cses.fi/problemset/task/1637
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
int binPow(int a, int pow){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a;
	} else {
		int part = binPow(a, pow >> 1);
		if (pow & 1) {
			return (((part * part)) * a);
		} else {
			return (part * part);
		}
	}
}
inline vector <short> inttovec(ll n){
    vector <short> pool;
    
    while (n>0){
        short k = n % 10;
        pool.push_back(k);
        n /= 10;

    }
    return pool;
}
int fast_powtw(int k) { return 2 << (k - 1);}

inline void solve(){
    ll n;
    cin >> n;n++;
    vector <ll> dp(n);
    if (n-1 <10) {cout << 1 << nl; return;}
    vector <short> number;
    incr(i,1,10) dp[i] = 1;
    dp[0]=0;
    incr(i,10,n){
        number=inttovec(i);
        dp[i]=INT_MAX;
        fca(a,number){
            dp[i]=min(dp[i],dp[i-a]+1);
        }
    }
    cout << dp[n-1] <<nl;
    return;
}



int main()
{
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests;i++)
        solve();
    return 0;
}