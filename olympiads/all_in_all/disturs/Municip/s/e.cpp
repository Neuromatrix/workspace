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
int binPow(int a, int pow){ // помощь для переовда строкив  число
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
int stringToInt(string a){// перевод стркои в число
    int max_pow = a.size() - 1;
    int res = 0;
    for (int i = 0; i < a.size(); i++){
        res += (a[i] - '0') * (binPow(10, max_pow));
        max_pow--;
    }
    return res;
}
int dif_time(string a, string b){
    int atime = stringToInt(a.substr(0,2))*3600+stringToInt(a.substr(3,2))*60+stringToInt(a.substr(6,2));
    int btime = stringToInt(b.substr(0,2))*3600+stringToInt(b.substr(3,2))*60+stringToInt(b.substr(6,2));
    return btime-atime;
}
inline void solve(){
    int n;
    cin >> n;
    vector <pair <string, pair<int, int>>> data(n);
    incr(i,0,n){
        cin >> data[i].first >> data[i].second.first >> data[i].second.second;
    }
    sort(all(data));
    vc <ld> ans;
    incr(i,0,n-1){
        ld x1 = data[i].second.first, y1 = data[i].second.second;
        ld x2 = data[i+1].second.first, y2 = data[i+1].second.second;
        ld dist = sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
        ans.pb(dist/dif_time(data[i].first,data[i+1].first));
    }
    setpr(10000);
    sort(all(ans));
    cout << ans[0] << " " << ans[n-2] << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}