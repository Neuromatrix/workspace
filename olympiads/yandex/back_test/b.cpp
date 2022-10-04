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
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    vector <pair<vector<int>,char>> data;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int d, h, m;
        int id;
        char cmd;
        cin >> d >> h >> m >> id >> cmd;
        vector<int> tmp = {id,(d*24+h)*60+m};
        data.push_back({tmp,cmd});
    }
    sort(data.begin(), data.end());
    map <int,int> ans;
    int cur_fl = 0;
    for (const auto & it : data) {
        char cmd = it.second;
        if (cmd == 'A'){
            cur_fl = it.first[1];
        } else if (cmd == 'C' or cmd == 'S'){
            ans[it.first[0]] += it.first[1]-cur_fl;
        }
    }
    for (const auto & it : ans) {
        cout << it.second << " ";
    }


}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}
