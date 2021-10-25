#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
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
#define rall(x) x.rbegin(),x.rend()
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
inline pair<vector <bool>,vector <int>> bfs_distance_from(vector<vector<int>> graph, int cur){ // работает со списком смежности
    queue <int> q;
    vector <int> distance(graph.size());
    vector <bool> visited(graph.size());
    distance[cur] = 0;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty()){
        cur = q.front();
        q.pop();
        fca(u,graph[cur]){ // проход по всем вершинам в которые  ведут ребра
            if(visited[u]) continue; // вершина посещена
            visited[u] = true; 
            distance[u] = distance[cur] + 1; // расстояние для вершины в которую ведут ребра cur увеличиваем
            q.push(u); 
        }
    }
    return {visited, distance};
}
inline void solve(){
    int n,t ;
    cin >> n >> t;
    vc <vi> g(n);
    incr(i,0,n-1){
        int x;
        cin >> x;
        g[i].push_back(i+x);
    }
    vc <bool> vis = bfs_distance_from(g,0).first;
    if(vis[t-1]==1) cout << "YES" << nl;
    else cout <<"NO" << nl;
} 
int main(){
    IOS;
    //  prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}