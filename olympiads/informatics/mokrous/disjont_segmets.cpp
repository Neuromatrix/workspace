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
template <typename T>
class lseg_tree
{
    private:
        vector <T> tree;
        vector <T> mod; 
        int size_it = 0;
        void push(int v, int tl, int tr) {
            if (mod[v] != 0 && v * 2 + 1 < 4*size_it){
                mod[v * 2] = mod[v * 2 + 1] = mod[v];
                mod[v] = 0;
                int tm = (tl + tr) / 2;
                tree[v * 2] = (tm - tl + 1) * mod[v * 2];
                tree[v * 2 + 1] = (tr - tm) * mod[v * 2 + 1];
            }
        }
        void build (const vector <T> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }
        void update (int v, int tl, int tr, int l, int r, int val) {
            if (l <= tl && tr <= r) {
                tree[v] = val * (tr - tl + 1);
                mod[v] = val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
        T sum (int v, int tl, int tr, int l, int r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return 0;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return sum( v * 2, tl, tm, l, r)
                + sum(v * 2 + 1, tm + 1, tr, l, r);
        }
    public:
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
        T get(int pos){
            return sum(1,0,size_it-1,pos,pos);
        }
        void update(int l, int r, int add){
            update(1,0,size_it-1,l,r,add);
        }
        T sum(int l, int r){
            return sum(1,0,size_it-1,l,r);
        }
        lseg_tree(vector <T> a){
            init(a);
        }
        lseg_tree(){}
        void print(){
            incr(i,0,tree.size()){
                cout << tree[i] << " ";
            }
            cout << nl;
        }
};
inline void solve(){
    int n, k;
    cin >> n >> k;
    map <int,pii> group;
    set <int> not_used;
    vi segments(n);
    
    incr(i,1,n+1){
        not_used.insert(i);
    }
    lseg_tree <int> tree(segments);
    while (k--){
        int comm;
        cin >> comm;
        if(comm == 1){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if(tree.sum(l,r)==0){
                cout << 1 << nl;
                int indg = *not_used.begin();
                tree.update(l,r,indg);
                group[indg] = {l,r};
                not_used.erase(not_used.begin());
            } else {
                cout << 0 << nl;
            }
        } else {
            int seg;
            cin >> seg;
            seg--;
            
            if(tree.get(seg)==0){
                cout << 0 << " " << 0 << nl;
            } else {
                int indg = tree.get(seg);
                int l = group[indg].first, r = group[indg].second;
                cout << l+1 << " " << r+1 << nl;
                tree.update(l,r,-indg);
                not_used.insert(indg);
            }
        }
    }
    
}
signed main(){
    IOS;
    //  prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}