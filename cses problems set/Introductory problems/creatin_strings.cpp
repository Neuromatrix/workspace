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
ll fac(int n){
    if (n==1) return 1;
    return n*fac(n-1);
}
inline void solve(){
    string pool,s_pool;
    cin >> pool;
    map <char, int> num;
    int n = pool.size();
    ll permutations = fac(n);
    incr(i,0,n){
        num[pool[i]]++;
    }
    fca(it, num) permutations/=fac(it.S);
    cout << permutations <<nl;
    fca(it, num){
        incr(i,0,it.S) s_pool.push_back(it.F);
    }
    do
    {
        cout << s_pool << nl;
    } while (next_permutation(s_pool.begin(),s_pool.end()));
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}