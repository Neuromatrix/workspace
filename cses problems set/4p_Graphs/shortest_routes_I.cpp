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
constexpr ll LINF = LLONG_MAX-1;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<   ,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (int i=a; i<b; ++i)
#define decr(i,a,b) for (int i=a; i>b; --i)
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
inline vector <vector <pair <ll, ll>>> adjacency_lists_with_weight(){
    ll n, m, to_h, W;
    cin >> n >> m;
    n++;
    vector <vector <pair <ll, ll>>> graph(n); // списки смежности
    for (size_t i = 0; i < m; i++)
    {
        ll k;
        cin >> k >> to_h >> W;
        graph[k].push_back({to_h,W});
    }
    
    return graph;
}

vector <ll> Deikstra(vector <vector <pair <ll, ll>>> G, ll start){
    ll gsize = G.size();
    priority_queue <pair<ll, ll>> q;
    vector <ll> distance(G.size());
    vector <bool> processed(G.size());
    for (size_t i = 1; i < G.size(); i++){
        distance[i] = LINF;
        processed[i] = false;
    }
    distance[start] = 0;
    q.push({0,start});
    while (!q.empty()){
        ll a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(const auto & u : G[a]){
            ll b =  u.first, w = u.second;
            if (distance[a]+w < distance[b]){
                distance[b] = distance[a] + w;
                q.push({-distance[b],b});
            }
        }
    }
    return distance;
}
inline void solve(){
    ll i = 0;

    fca(a,Deikstra(adjacency_lists_with_weight(),1)){
        if(i)cout << a << " ";
        i++;
    }
    cout << nl;
}
signed main(){
    IOS;
    //prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}
