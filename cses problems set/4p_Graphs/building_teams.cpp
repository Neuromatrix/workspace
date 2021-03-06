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
int n, m;
vi colors;
bool exx;
vc <vi> graph;
vector <bool> visited;
inline vector <bool> dfs_visited_from(int cur,int color = 0){
    if (visited[cur] && colors[cur]!=color && colors[cur]!=3) {exx=true;return visited;}
    if (visited[cur]) {return visited;}
    colors[cur] = color;
    visited[cur] = true;
    fca(u,graph[cur]){
        dfs_visited_from(u,(color+1)%2);
    }
    return visited;
}
inline void solve(){
    cin >> n >> m;
    graph.resize(n+1);
    incr(i,0,m){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    colors.resize(n+1,3);
    visited.assign(n+1,false);
    incr(i,1,n+1){
        if(colors[i]==3) dfs_visited_from(i);
    }
    if(exx){
        cout <<"IMPOSSIBLE" << nl;
        return;
    }
    incr(i,1,n+1){
        cout << colors[i]+1 << " ";
    }
    cout << nl;
    return;
}

int main(){
    IOS;
    // prepare();
    solve();
    return 0;
}