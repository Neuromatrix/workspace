#include <bits\stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
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


class ancestors_tree{
    private:
        int n;
        vvi gr;
        vvi data;
        int root = 1;
        inline void dfs(int cur, int prev){
            data[0][cur] = prev;
            fca(nex,gr[cur]){
                if(nex==prev) continue;
                dfs(nex,cur);
            }
        }
    public:
        void init(const vector <vector <int>> &graph){
            
            gr = graph;
            n = gr.size();
            data.resize(n+1);
            data[0].resize(n+1);
            dfs(root, 0);
            for (int i = 1; 1<<i <= n ; i++){ 
                data[i].resize(n+1);
                for (int j = 0; j <= n ; j++)
                    data[i][j] = data[i-1][data[i-1][j]];
            }
        }

        void query(int node, int k){
            int boss = node;
            for(int i=0; i<=20; i++)
                if(k & (1<<i))
                    boss = data[i][boss];
            cout << (boss==0 ? -1 : boss) << nl;
        }
};
inline void solve(){
    int n;
    int q;
    cin >> n >> q;
    vvi G(n+1);
    incr(i,2,n+1){
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }

    ancestors_tree t;
    t.init(G);
    
    while (q--){
        int a, b;
        cin >> a >> b;
        t.query(a,b);
    }
    
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}