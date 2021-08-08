// https://cses.fi/problemset/task/1667
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
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
inline pair<vector <bool>,vector <pair <ll,ll>>> bfs(vector<vector<ll>> graph, ll cur){ // работает со списком смежности
    queue <ll> q;
    vc <pair <ll,ll>> distance(graph.size());
    vector <bool> visited(graph.size());
    distance[cur].F = 0;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty()){
        cur = q.front();
        q.pop();
        fca(u,graph[cur]){ // проход по всем вершинам в которые  ведут ребра
            if(visited[u]) continue; // вершина посещена
            visited[u] = true; 
            distance[u].F = distance[cur].F + 1;// расстояние для вершины в которую ведут ребра cur увеличиваем
            distance[u].S = cur;
            q.push(u); 
        }
    }
    return {visited, distance};
}
inline void solve(){
    size_t n, m;
    ll a, b;
    cin >> n >> m;
    n++;
    vector<vector<ll>> g(n);
    g.resize(n);
    incr(i,0,m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pair <vc <bool>, vc <pair<ll,ll>>> aps = bfs(g,1);
    vector <ll> sh_path;
    if (aps.F[1] == true && aps.F[n-1] == true){
        cout << aps.S[n-1].F+1 << nl;
        ll i = 10;
        while(i>=1){
            sh_path.pb(i);
            i = aps.S[i].S;
        }
        decr(i,sh_path.sz-1,-1) cout << sh_path[i] << " ";cout << nl;
    }
    else cout << "IMPOSSIBLE" << nl;
    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}