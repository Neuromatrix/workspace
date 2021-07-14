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
//#define _DEBUG
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';

#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define sortest(obj,all) sort(obj.begin(),obj.end())
int abs_(int a) {return a <= 0 ? -a : a;}
inline void solve(){
	size_t n;
    cin >> n;
    vector <ll> pool(n);
    incr (i,0,n) cin >> pool[i];
    sortest(pool,all);
    ll res = 1;
    for(ll i = 0; i<n && res>=pool[i];i++){
        res+=pool[i];
    }
    cout << res <<nl;
    return;
}


int main(){
    #ifdef _DEBUG
        freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
        freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);

    #endif
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}