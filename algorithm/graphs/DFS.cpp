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

inline vector <bool> dfs_visited_from(vector <vector <int>> graph, int cur,vector <bool> &visited){
    if (visited[cur]) return visited;
    visited[cur] = true;
    fca(u,graph[cur]){
        dfs_visited_from(graph,u,visited);
    }
    return visited;
}
inline vector <vector <int>> adjacency_lists(){
    int n, to_h;
    cin >> n;cin.ignore();
    n++;
    vector <vector <int>> graph(n); // списки смежности
    for(size_t i = 1; i < n; i++){
        while(cin.peek()!=nl){ 
            cin >> to_h;
            graph[i].push_back(to_h);
        }
        cin.ignore();
    }
    return graph;
}
inline void solve(){
    //алгоритм работает в натуральной системе отсчета, т.е. вершине 1 
    //сооствесвтует список с индексом 1, а не 0
    
}



int main()
{
    IOS;
    solve();
    return 0;
}