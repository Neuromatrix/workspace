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
vector <vector <ll>> Floyd_Warshall(vector <vector<ll>> &G){
    int n = G.size(); // работает в натуральной нумерации
    vector <vector <ll>> distance(n,vector<ll> (n));
    for (size_t i = 1; i < n; i++){
        for(size_t j = 1; j < n; j++){
            if (i==j) distance[i][j] = 0;// заполняем distance в зависимости от ребер
            else if(!G[i][j]) distance[i][j] = LINF;
            else if (G[i][j]) distance[i][j] = G[i][j]; 
        }
    }
    for (size_t k = 1; k < n; k++){
        for (size_t i = 1; i < n; i++){
            for(size_t j = 1; j < n; j++){
                if (distance[i][k] < LINF && distance[k][j] < LINF)
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);// алгоитм флойда
            }
        }
    }
    return distance;
}
inline void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
    vc <vc <ll>> gr(n+1,vc<ll>(n+1,LINF));
    incr(_,0,m){
        ll a, b, w;
        cin >> a >> b >> w;
        gr[a][b] = min(w,gr[a][b]);
        gr[b][a] = min(w,gr[b][a]);
    }
    vc <vc <ll>> dist = Floyd_Warshall(gr);
    while (q--){
        ll a, b;
        cin >> a >> b;
        cout << (dist[a][b]==LINF ? -1 : dist[a][b]) << nl;
    }
    
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}