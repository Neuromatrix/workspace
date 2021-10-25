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
int n, m;
vii moves = {{0,1},{1,0},{-1,0},{0,-1}};
bool valid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    return true;
}
inline void solve(){
    
    cin >> n >> m;
    vc<string> data(n);
    incr(i,0,n){
        cin>> data[i];
    }
    incr(i,0,n){
        incr(j,0,m){
            if(data[i][j]=='S')
                fca(m,moves){
                    if(valid(i+m.first,j+m.second)){
                        if(data[i+m.first][j+m.second]=='W'){
                            cout << "No" << nl;
                            return;
                        }
                    }
                }
        }
    }
    cout << "Yes" << nl;
    incr(i,0,n){
        incr(j,0,m){
            if(data[i][j]=='.')
            data[i][j] = 'D';
        }
    }
    fca(a,data){
        fca(it,a){
            cout << it;
        }
        cout << nl;
    }
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}