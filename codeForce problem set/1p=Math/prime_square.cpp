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

inline void solve(){
    int n;
    cin >> n;
    if (n & 1){ 
        int mid = n/2;
        incr(i,0,n){
            incr(j,0,n){
                if(i==j) cout << 1 << " ";
                else if (n-i==j+1) cout << 1 << " ";
                else if((i==mid && abs(j-mid)==1) || (j==mid && abs(i-mid)==1))cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << nl;
        }
    } else {
        incr(i,0,n){
            incr(j,0,n){
                if(i==j) cout << 1 << " ";
                else if (n-i==j+1) cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << nl;
        }
    }
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}