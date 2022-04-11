#include <bits\stdc++.h>
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
const int N = 1e5+5;
set<pair<int,int>, greater<pair<int,int>>> sons[N];
set<int> nowcolor;
vector <int> counter;
vector <vector <int>> G;
inline void dfs1(int cur, int prev){
    counter[cur] = 1;
    for(const auto & nex: G[cur]){
        if(nex==prev) continue;
        dfs1(nex,cur);
        counter[cur]+=counter[nex];
    }
}
inline void dfs2(int cur, int prev){
    sons[cur].insert(make_pair(counter[cur],cur));
    for(const auto & nex: G[cur]){
        if(nex==prev) continue;
        dfs2(nex,cur);
        for (const auto & it : sons[nex]) {
            sons[cur].insert(make_pair(counter[nex],nex));
        }
    }
}
inline void solve(){
    int n;
    cin >> n;
    for (int i = 2; i < n+1; i++)
    {
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    int ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}