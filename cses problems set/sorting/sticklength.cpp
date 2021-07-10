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
    incr(i,0,n) cin >> pool[i];
    sortest(pool,all);
    ll median,med_number,ans=0,ans_l=0;
    if (pool.size()%2){
        median = pool.size()/2;
        med_number= pool[median];
        incr(i, 0, n) ans+=abs_(pool[i]-med_number);
        cout << ans << nl;
    }
    else{
        median = pool.size()/2;
        med_number= pool[median];
        incr(i, 0, n) ans+=abs_(pool[i]-med_number);
        median = pool.size()/2-1;
        med_number= pool[median];
        incr(i, 0, n) ans_l+=abs_(pool[i]-med_number);
        cout << min(ans_l,ans)<<nl;
    }
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