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
    // size_t n, m;
    // ll a, b;
    // cin >> n;
    // n++;
    // vector<vector<ll>> g(n+1);
    // g.resize(n);
    // incr(i,1,n+1){
    //     int x;
    //     cin >> x;
    //     g[x].push_back(i);
    // }
    // fca(it,g){
    //     fca(x,it){
    //         cout << x << " ";
    //     }
    //     cout << nl;
    // }
    // pair <vc <bool>, vc <pair<ll,ll>>> aps = bfs(g,1);
    // vector <ll> sh_path;
    // ll i = n-1;
    // while(i>=1){
    //     sh_path.pb(i);
    //     i = aps.S[i].S;
    // }
    // decr(i,sh_path.sz-1,-1) cout << sh_path[i] << " ";cout << nl;
    int n;
    cin >> n;
    vi data;
    seev(data,n-1);
    int i = n-2;
    vi ans;
    ans.pb(n);
    while (true){
        // cout << i << nl;
        ans.push_back(data[i]);
        
        i = data[i]-2;
        if(i<0) break;
    }
    reverse(all(ans));
    fca(it,ans) cout << it <<" ";
    cout << nl;
    return;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}