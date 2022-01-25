#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
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

void m_vision( vector <vector <int>> GR){
    freopen("C:\\Users\\grivi\\vscodes\\GraphVis\\input.dot","w",stdout);
    cout << "strict graph {\n";
    for (size_t i = 0; i < GR.size(); i++){
        for (size_t j = 0; j < GR[i].size(); j++){
            if(GR[i][j]==GR[j][i]){
                if (GR[i][j]!=1 && GR[i][j]!=0){
                    cout << i <<  "--" << j << "[weight=" <<  GR[i][j] <<']' << '\n';
                } else if(GR[i][j]==1) {
                    cout << i <<  "--" << j << '\n';
                }
            } else {
                if (GR[i][j]!=1 && GR[i][j]!=0){
                    cout << i <<  "->" << j << "[weight=" <<  GR[i][j] <<']' << '\n';
                } else if(GR[i][j]==1) {
                    cout << i <<  "->" << j << '\n';
                }
            }
            
        } 
        
    }
    cout << "}\n";
}
inline void solve(){
    vc <vi> g = {
        {0,16,15,24,22,12,19,18},
        {16,0,0,0,30,0,0,0},
        {15,0,0,0,0,21,0,0},
        {24,0,0,0,37,0,27,0},
        {22,30,0,37,0,0,0,0},
        {12,0,21,0,0,0,0,23},
        {19,0,0,27,0,0,0,0},
        {18,0,0,0,0,23,0,0}
    };
    m_vision(g);
}
signed main(){
    IOS;
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}