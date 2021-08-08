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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';

#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define all(obj) obj.begin(),obj.end()
#define F first
#define S second

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int abs_(int a) {return a <= 0 ? -a : a;}
inline void solve(){
    ll n;size_t maximus=0, counter=1;
    cin >> n;
    vector <ll> playlist(n);
    incr(i,0,n) cin >> playlist[i];
    int i = 1, j = 0;
    while(i < n && j < n){
        cout << j << " " << i <<"--" << counter<<nl;
        if(playlist[i]==playlist[j]){
            j++;
            maximus=max(counter,maximus);
            if(i==j) i++;
            counter=i-j;

        } else {
            i++;
            counter++;
        }
    }
    cout << counter << nl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prepare();
    size_t tests = 1;
    //cin >> tests;
    for (size_t i = 0; i < tests; i++)
        solve();
    return 0;
}