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
vc <bool> visited;
vc <vc <ll>> g;
inline void dfs_visited_from(int cur){
    visited[cur] = true;
    fca(u,g[cur]){
        if(!visited[u])
            dfs_visited_from(u);
    }
    return;
}

inline void solve(){
    size_t n, m;
    ll a, b;
    cin >> n >> m;
    n++;
    g.resize(n);
    incr(i,0,m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visited.assign(n,false);
    vc <ll> hi;
    ll ans = 0;
    incr(i,1,n){
        if(visited[i]==false){
            ans++;
            hi.push_back(i);
            dfs_visited_from(i);
        }
    }
    cout << ans-1 <<nl;
    if(ans > 1 )
	{
		int u = hi[0]; int v;
		for(auto i = 1; i < ans; i++)
		{
			v = hi[i];
			cout << u << " " << v << endl;
			u = v;
		}
	}
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}