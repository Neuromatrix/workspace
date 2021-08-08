// https://cses.fi/problemset/task/1163
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
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    ll n, lights, new_l, l ,r;
    cin >> n >> lights;
    multimap <ll, ll> pool;
    multiset <pair <ll, ll>> maxx; 
    maxx.insert({n,0});
    pool.insert({0,n});
    incr(i,0,lights){
        cin >> new_l;
        auto it = prev(pool.lower_bound(new_l));
        l = (*it).first;
        r = (*it).second;
        ll dist = r-l;
        maxx.erase({dist,l});
        pool.erase(it);
        pool.insert({l, new_l});
        pool.insert({new_l, r});    
        maxx.insert({new_l-l,l});
        maxx.insert({r-new_l,new_l});
        cout << (*prev(maxx.end())).first<<nl;
    }
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}