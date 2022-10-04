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
const int mx = 1e3;
#define r 2
#define l 1
int cur_root = 1;
int g[mx][3];
void output(int v){
    if (g[v][l]!=0){
        output(g[v][l]);
    }
    cout << v << " ";
    if (g[v][r]!=0){
        output(g[v][r]);
    }
}
void gswap(int p, int v){
    int pp = g[p][0];
    int vl = g[v][l];
    int vr = g[v][r];
    int pr = g[p][r];
    int pl = g[p][l];
    int ppl = g[pp][l];
    int ppr = g[pp][r];
    if (pl == v){ //left
        g[vl][0] = p;
        g[p][l] = vl;
        if(ppl == p){
            g[pp][l] = v;
            g[v][0] = pp;

        } else {
            g[pp][r] = v;
            g[v][0] = pp;
        }
        g[v][l] = p;
        g[p][0] = v;
    } else {
        g[vr][0] = p;
        g[p][r] = vr;
        if(ppl == p){
            g[pp][l] = v;
            g[v][0] = pp;

        } else {
            g[pp][r] = v;
            g[v][0] = pp;
        }
        g[v][r] = p;
        g[p][0] = v;
    }
    if(cur_root== p) cur_root = v;

}
inline void solve(){
    for(int i = 0; i < mx; i++){
        for(int j = 0; j < 3; j++){
            g[i][j] = 0;
        }
    }
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        if(i>=2){
            if (i&1){
                g[i][0] = (i-1)/2;
            } else{
                g[i][0] = i/2;
            }
        }
        if(2*i>n) continue;
        g[i][l] = 2*i;
        if(2*i+1>n) continue;
        g[i][r] = 2*i+1;
    }
    for (int j = 0; j < q; j ++){
        int ch, p;
        cin >> ch;
        if(ch==cur_root) continue;
        p = g[ch][0];
        gswap(p,ch);
    }
    output(cur_root);


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
