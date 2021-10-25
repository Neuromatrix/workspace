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
    int n,m;
    cin >> n >> m;
    vi to;
    seev(to,n);
    vi aback;
    seev(aback,n);
    vc <vi> G(2*n);
    incr(i,0,n){
        if(to[i]==1)
            incr(j,i+1,n){
                if(to[j]==1){
                    G[i].pb(j);
                }
            }
        if(aback[i]==1 && to[i]==1) G[i].push_back(i+n);
    }
    decr(i,n-1,-1){
        if(aback[i]==1)
            decr(j,i-1,-1){
                if(aback[j]==1){
                    G[i+n].pb(j+n);
                }
            }
        if(aback[i]==1 && to[i]==1) G[i+n].push_back(i);    
    }
    pair<vector <bool>,vector <int>> ans = bfs_distance_from(G,0);
    if(ans.first[m-1]==1 || ans.first[m+n-1]==1) cout <<"YES" << nl;
    else cout << "NO" << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}