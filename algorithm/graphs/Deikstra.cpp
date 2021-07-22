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
#define fca(a,s) for(const auto & a : s)

inline vector <vector <pair <int, int>>> adjacency_lists_with_weight(){
    int n, to_h, W;
    cin >> n;cin.ignore();
    n++;
    vector <vector <pair <int, int>>> graph(n); // списки смежности
    for(size_t i = 1; i < n; i++){
        while(cin.peek()!=nl){ 
            cin >> to_h  >> W; // сначала вершина потом веса
            graph[i].push_back({to_h,W}); // записываем в пару
        }
        cin.ignore();
    }
    return graph;
}

vector <ll> Deikstra(vector <vector <pair <int, int>>> G, int start){
    int gsize = G.size();
    priority_queue <pair<int, int>> q;
    vector <ll> distance(G.size());
    vector <bool> processed(G.size());
    for (size_t i = 1; i < G.size(); i++){
        distance[i] = INF;
        processed[i] = false;
    }
    distance[start] = 0;
    q.push({0,start});
    while (!q.empty()){
        int a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(const auto & u : G[a]){
            int b =  u.first, w = u.second;
            if (distance[a]+w < distance[b]){
                distance[b] = distance[a] + w;
                q.push({-distance[b],b});
            }
        }
    }
    return distance;
}


inline void solve(){
    /*
        .....
    */
   return;
}

int main(){
    IOS;
    solve();
    return 0;
}