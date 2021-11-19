#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
string longest_palindrom(string s){
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    string ann;
    int lens = max(2*(*max_element(d1.begin(),d1.end()))-1,2*(*max_element(d2.begin(),d2.end())));
    if(lens == 2*(*max_element(d1.begin(),d1.end()))-1){
        int ind = max_element(d1.begin(),d1.end()) - d1.begin();
        for (size_t i = ind-d1[ind]+1; i < ind-d1[ind]+lens+1; i++){
            ann.push_back(s[i]);
        }
        
    } else {
        int ind = max_element(d2.begin(),d2.end()) - d2.begin();
        for (size_t i = ind-d2[ind]; i < ind-d2[ind]+lens; i++){
            ann.push_back(s[i]);
        }
    }
    return ann;
}
inline void solve(){
    string data;
    cin >> data;
    // cout << longest_palindrom(data) <<nl;
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}