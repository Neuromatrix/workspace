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
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
#define fca(iterator,object) for (const auto & iteratot: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)

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
    size_t n;
    cin >> n;
    vector <string> parspool(n);
    vector <vector <ll>> dp(n,vector <ll> (n));
    vector <vector <bool>> possible(n,vector <bool> (n));
    ll mod = binPow(10,9) + 7;
    
    incr(i,0,n) cin >> parspool[i];
    incr(i,0,n){
        incr(j,0,n){
            if (parspool[i][j]=='.') possible[i][j] = true;
            else possible[i][j] = false;
        }
    }
    if(possible[0][0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    incr(i,0,n){
        incr(j,0,n){
            if(possible[i][j]){
                if (i-1 >= 0 && possible[i-1][j]==true){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=mod;
                }
                if (j-1 >= 0 && possible[i][j-1]==true){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=mod;
                }
            }   
        }   
    }
    cout << dp[n-1][n-1] << nl;
    return;

}

int main(){
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}