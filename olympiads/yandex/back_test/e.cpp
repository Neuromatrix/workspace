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
pair <int,int> a = {1,0};
pair <int,int> b = {0,1};
vector <vector<int>> data;
vector<bool> wecan;
map <int, pair<int,int>> need;
vector <int> was;
bool cook(int v,int start){
    if(was[start] >= 2) return false;
    was[v]++;
    if(need[v]!=make_pair(0,0)) return true;
    if(!wecan[v]) return false;
    else{
        pair <int,int> now;
        for(int i = 0; i < data[v].size(); i++){

            if(cook(data[v][i],v)){
                now.first+=need[data[v][i]].first;
                now.second+=need[data[v][i]].second;
            } else {
                wecan[v] = false;
                return false;
            }
        }
        need[v] = now;
    }
    return true;
}
inline void solve(){
    int n;
    cin>> n;
    data.resize(n+1);
    wecan.resize(n+1,1);
    was.assign(n+1,0);
    need[1] = a;
    need[2] = b;
    for (int i = 3; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int tm;
            cin >> tm;
            data[i].push_back(tm);
        }
    }
    for (int i = 3; i <= n; i++){
        cook(i,i);
        was.assign(n+1,0);
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        int r;
        cin >> a >> b;
        cin >> r;
        if (!wecan[r])cout <<'0';
        else if(-need[r].first+a<0 or -need[r].second+b<0) cout <<"0";
        else cout << "1";
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
