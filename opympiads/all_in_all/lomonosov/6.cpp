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
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1999871;
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
struct node {
private:
    ull count = 0, sum = 0, xum = 0;
    vc <ull> vt;
    node * next;
public:
    node (ull x, ull sm) {
        count = x; 
        sum = sm;
        vt.resize(count);
    } 
    node(ull x, ull sm, node* prnt) {
        count = x; 
        sum = sm;
        vt.resize(count);
        prnt->next = this;
    } 
    
    void valid() {
        if(next == nullptr) return;
        if(xum != next->sum) {
            incr(i,0,count){
                if(vt[i] != 1) {vt[i]++; xum++; xum %= MOD;}
            }
        }
    }
    void init() {
        incr(i,0,count){
            cin >> vt[i];
            xum += vt[i];
            xum %= MOD;
        }
    }
    void add(vc <ull> & vec) {
        incr(i,0,count) vec[vt[i] - 1]++;
        return;
    }
};
inline void solve(){
    int k, a, b;
    cin >> k >> a >> b;
    vc <node> data;
    vc <ull> vt;
    vt.assign(k,0);
    data.pb(node(a, b));
    data[0].init();
    incr(i,1,INT_MAX){
        cin >> a >> b;
        if(a == 0) {
            data.pb(node(a, b, &data[i - 1]));
            data[i - 1].valid();
            data[i - 1].add(vt);
            break;
        }
        data.pb(node(a, b, &data[i - 1]));
        data[i].init();
        data[i - 1].valid();
        data[i - 1].add(vt);
    }
    incr(i,0,k) cout << vt[i] << " ";
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}