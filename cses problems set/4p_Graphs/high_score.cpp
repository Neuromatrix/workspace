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
bool flag = false;
vvi aa,bb;
vector <bool> vis1, vis2;
inline void dfs1(int cur = 1){
    vis1[cur] = true;
    for(auto v:aa[cur])
        if (!vis1[v])
            dfs1(v);
}
inline void dfs2(int cur){
    vis2[cur] = true;
    for(auto v:bb[cur])
        if (!vis2[v])
            dfs2(v);
}
vector <ll> Bellman_Ford(vector <tuple <int, int, int>> &edges, int start, int gsize){
    start--;// 0_N нумерация
    int a, b, w;
    int ex;
    vector <ll> distance(gsize);// колво вершин
    for (size_t i = 0; i < distance.size(); i++){
        distance[i] = INF;// заполняем бесконечностями
    }
    distance[start] = 0;
    for (size_t i = 0; i < distance.size()+5; i++){ //асимптотика O(nm), на каждой итерации перебираем все ребра
        flag = false;
        for(const auto & e : edges){
            tie(a, b, w) = e;
            a--;// 0_N нумерация
            b--;
            if (distance[a] < INF && vis1[a+1] && vis2[b+1]){
                if(distance[b]>distance[a]+w){
                    distance[b] = min(distance[b],distance[a]+w);
                    flag = true;  
                }          
            }
        }
        
    }
    return distance;
}
inline void solve(){
    int n, m;
    cin >> n >> m;
    vector <tuple <int, int, int>> edges;
    aa.resize(n+1);
    bb.resize(n+1);
    vis1.resize(n+1);
    vis2.resize(n+1);
    incr(_,0,m){
        int a, b ,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,-c});
        aa[a].push_back(b);
        bb[b].push_back(a); 
    }
    dfs1();
    dfs2(n);
    vector <ll> dist = Bellman_Ford(edges,1,n);
    cout << (flag? -1 : (-dist[n-1]==-INF ? -1 : -dist[n-1])) << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}