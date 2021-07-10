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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
#define fca(a,s) for(const auto & a: s)
#define incr(i,k,n) for (ll i = k; i < n; i++)
#define decr(i,k,n) for (ll i = k; i > n; i--)

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