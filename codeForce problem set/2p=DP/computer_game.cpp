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
int n;
bool valid(int i, int j, vc <vi> & possible){
    if(i<0 || i >=2  || j < 0 || j>=n) return false;
    if (possible[i][j]) return false;
    return true;
}
inline void solve(){
    
    cin >> n;
    vii moves = {{0,1},{1,0},{1,1},{-1,0},{-1,1}};
    vc <vi> possible(2,vi(n));
    vc <string> data(2);
    cin >> data[0];
    cin >> data[1];
    incr(i,0,2){
        incr(j,0,n){
            if(data[i][j]=='0') possible[i][j] = 0;
            else possible[i][j] = 1;
        }
    }
    vc <vi> dp(2,vi(n));
    dp[0][0] = 1;
    incr(i,0,n){
        incr(j,0,2){
            if(dp[j][i]==0){
                continue;
            }
            fca(m,moves){
                if(valid(j+m.first,i+m.second,possible)){
                    dp[j+m.first][i+m.second] = 1;
                }
            }
        }
    }
    if(dp[1][n-1]==1)cout <<"YES" << nl;
    else cout << "NO" << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}