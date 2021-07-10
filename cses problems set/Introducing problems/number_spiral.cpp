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

#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define sortest(obj,all) sort(obj.begin(),obj.end())
#define F first
#define S second

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}



inline void solve(){
    ll x, y;
    cin >> x >> y;
    if (x==y){
        cout << x*x-y+1 << nl;
    }
    else if (x<y){
        if (y%2==0){
            cout << y*y-y+1-(y-x) << nl;
        }
        else{
            cout << y*y-y+1+(y-x) << nl;
        }
    }
    else{
        if (x%2==0){
            cout << x*x-x+1 +(x-y) <<nl;
        }
        else{
            cout << x*x-x+1 -(x-y) <<nl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}