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

int fast_powtw(int k) { return 2 << (k - 1);}

inline void solve(){
    ll n;
    cin >> n;n++;
    vector <ll> dp(n);
    ll mod = binPow(10,9)+7;
    dp[0]=1;
    incr(i,1,n){
        incr(j,1,6+1){
            if (i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
    }
    cout << dp[n-1] <<nl;
    return;
}



int main()
{
    size_t tests = 1;
    //cin >> tests;
    tests=1;
    for (int i = 0; i < tests;i++)
        solve();
    return 0;
}