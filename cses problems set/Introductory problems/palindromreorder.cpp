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
#define all(obj) obj.begin(),obj.end()
#define F first
#define S second

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    string pool,ans;
    cin >> pool;
    char ex = '1';
    int n = pool.size();
    int mods = pool.size() & 1;
    map <char,int> sorted;
    incr(i,0,n) sorted[pool[i]]++;
    if (!mods){
        fca (it, sorted){
            if ((it.S & 1)) {cout << "NO SOLUTION" << nl; return;}
        }
        fca (it, sorted){
            incr(i,0,it.S >> 1) ans.push_back(it.F);
        }
        incr(i,0,n/2) ans.push_back(ans[n/2-1-i]);
        cout << ans << nl;
    }
    else{
        fca (it, sorted){
            if (it.S & 1){
                if (ex=='1'){
                    ex=it.F;
                }
                else {cout << "NO SOLUTION" << nl; return;}
                
            }
        }
        fca (it, sorted){
            incr(i,0,it.S >> 1) if(it.F!=ex) ans.push_back(it.F);
        }
        int sii = ans.size() - 1;
        incr(i,0,sorted[ex]) ans.push_back(ex); 
        decr(i,sii,-1) ans.push_back(ans[i]);
        cout << ans << nl; 
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //dprepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}