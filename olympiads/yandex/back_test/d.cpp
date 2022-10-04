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
const int MX = 1e6 + 5;
struct fenw
{
    vector <ll> bit;
    vector<ll> vals;
    void init(const vector <ll> &d){
        vals = d;
        bit.assign(MX,0);
    }
    void upd (ll i, ll val) {
        for (; i <= MX; i += i&(-i)) {
            bit[i] += val;
        }
    }

    void ad(ll x, ll b) {
        ll ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
        upd(ind, b);
    }

    ll sum (ll x) {
        ll res = 0;
        for (; x; x -= x&(-x)) {
            res += bit[x];
        }
        return res;
    }

    ll query(ll x) {
        ll ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
        return sum(ind);
    }
};





vector <ll> ende;
vector <ll> starte;
inline void solve(){
    ll n;
    cin >> n;
    vector <ll> ct(n), dur(n);
    vector <ll> prestarts(n),preend(n);
    for (ll i = 0 ; i < n; i++){
        ll a, b;
        cin >> a >>b ;
        ll cost;
        cin >> cost;
        ct[i] = cost;
        dur[i] = b-a;
        prestarts[i] = a;
        preend[i] = b;
    }
    ende = preend;
    starte = prestarts;
    ll q;
    cin >> q;
    vector <array <ll,3>> qu;
    while (q--){
        ll a, b, c;
        cin >> a>> b >> c;
        qu.push_back({a,b,c});
        starte.push_back(a);
        starte.push_back(b);
        ende.push_back(a);
        ende.push_back(b);

    }
    sort(ende.begin(), ende.end());
    sort(starte.begin(), starte.end());
    starte.erase(unique(starte.begin(), starte.end()), starte.end());
    ende.erase(unique(ende.begin(), ende.end()), ende.end());
    fenw duration;
    duration.init(ende);
    fenw costs;
    costs.init(starte);
    for(ll i = 0; i < n; i ++){
        duration.ad(preend[i],dur[i]);
        costs.ad(prestarts[i],ct[i]);
    }
    for (const auto & it : qu) {
        ll a  = it[0],b = it[1],c = it[2];
        if (c == 1){
            a--;
            cout << costs.query(b)-costs.query(a) << endl;
        } else {
            a--;
            cout << duration.query(b)-duration.query(a) << endl;
        }
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
