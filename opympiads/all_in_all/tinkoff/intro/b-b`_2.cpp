// #include <bits\stdc++.h>
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
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
class seg_tree {
private:
    vii tree;
    size_t n;
public:
    size_t sizee(void){return n;}
    void init(ll x) {
        n = 1;
        while (n < x) n += n;
        tree.assign(n + n - 1, make_pair(INF, 0));
    }
    void build(vi v) {
        init(v.size());
        for (ll i = n + v.size() - 2; i >= 0; i--)
            if (i + i + 2 > n + n - 2)
                tree[i].F = v[i - n + 1];
            else 
                tree[i].F = min(tree[i + i + 1].F, tree[i + i + 2].F);
    }
    void update (ll cur,ll tl, ll tr, ll l, ll r, ll ad) {
        if (r <= tl || l >= tr) return;
        if (tree[cur].S != 0){
            tree[cur].F += tree[cur].S;
            if (cur+cur+2 <= n+n-2) {
                tree[cur+cur+1].S += tree[cur].S;
                tree[cur+cur+2].S += tree[cur].S;
            }
            tree[cur].S=0;
        }
        if (tl>=l&&tr<=r) {
            tree[cur].S+=ad;
            tree[cur].F+=tree[cur].S;
            if (cur+ cur+ 2 <= n + n - 2) {
                tree[cur+ cur+ 1].S += tree[cur].S;
                tree[cur+ cur+ 2].S += tree[cur].S;
            }
            tree[cur].S = 0;
            while (cur> 0) {
                cur= (cur- 1)/2;
                tree[cur].F = min(tree[cur+ cur+ 1].F + tree[cur+ cur+ 1].S, tree[cur+ cur+ 2].F + tree[cur+ cur+ 2].S);
            }
        } else {
            ll tm = (tl + tr) / 2;
            update (cur*2+1, tl, tm, l, r, ad);
            update (cur*2+2, tm, tr, l, r, ad);
        }
    }
    ll exmin(ll l, ll r, ll x, ll tl, ll tr) {
        if (r <= tl || l >= tr) {
            return INF;
        }
        if (tree[x].S != 0) {
            tree[x].F += tree[x].S;
            if (x + x + 2 <= n + n - 2) {
                tree[x + x + 1].S += tree[x].S;
                tree[x + x + 2].S += tree[x].S;
            }
            tree[x].S = 0;
        }
        if (tl >= l && tr <= r) {
            return tree[x].F;
        }
        ll m = (tl + tr) / 2;
        ll min1 = exmin(l, r, 2 * x + 1, tl, m);
        ll min2 = exmin(l, r, 2 * x + 2, m, tr);
        return min(min1, min2);
    }
    void eupdate(ll l, ll r, ll ad) {
        update(0, 0, n, l, r, ad);
    }
    ll emin(ll l, ll r) {
        return exmin(l, r, 0, 0, n);
    }
};
inline void solve(){
    ll  n;
    cin >> n;
    vi data;
    seev(data,n);
    incr(i,0,n){
        data[i] = n - data[i] - 1;
    }
    seg_tree tr;
    vi rev(n);
    incr(i,0,n) rev[i] = i + 1;
    tr.build(rev);
    incr(i,0,n){
        tr.eupdate(data[i], n, -1);
        ll mn = tr.emin(data[i], n);
        if (mn <= 0){ cout << n - i - 1 << nl; return;}
    }

    return ;
}

int main(){ 
    IOS;
    //prepare();
    solve();
    return 0;
}


