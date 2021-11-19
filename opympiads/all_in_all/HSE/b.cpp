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
int n;
set <int> used;
set <pii> rii;
void rec( int cur, int h, int m_h, int lf = 1){
    if(n<=0) return;
    if(h==m_h) return;
    else{
        if(rii.find({cur,*used.begin()})==rii.end()){
            cout << cur << " " << *used.begin() << nl;
            rii.insert({cur,*used.begin()});
        }   
        if(rii.find({cur,*next(used.begin())})==rii.end()){
            cout << cur << " " << *next(used.begin()) << nl;
            rii.insert({cur,*next(used.begin()});
        }   
        n-=2;
        rec(use-2,h+1,m_h);
        rec(use-1,h+1,m_h);
    }
}
void reccc( int cur, int h, int m_h){
    if(n<=0) return;
    if(h==m_h) return;
    else{
        if(rii.find({cur,use})==rii.end()){
            cout << cur << " " << use << nl;
            rii.insert({cur,use});
        }   
        if(rii.find({cur,use+1})==rii.end()){
            cout << cur << " " << use+1 << nl;
            rii.insert({cur,use+1});
        }   
        use+=2;
        n-=2;
        rec(use-2,h+1,m_h);
    }
}
inline void solve(){
    int  boss, h1, h2;
    cin >> n >> boss >> h1 >> h2;
    n-=3;
    if(boss!=(max(h1,h2)+1)){
        cout << "NO" << nl;
    } else if ((n) & 1){
        cout << "NO" << nl;
    } else if (2*h1+2*h2>n){
        cout << "NO" << nl;
    } else if(n>((1<<((max(h1+1,30))-1))+(1<<((max(h1+1,30))-1)))){
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        int ribs = n+2;//!
        cout << ribs << nl;
        n+=2;
        rec(1,1,boss+1);
    }
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}