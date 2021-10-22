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

inline void solve(){
    int n;
    cin >> n;
    pair <vi, vi> poss;
    incr(i,0,n){
        char c;
        cin >> c;
        poss.first.push_back(c-'0');
    }
    incr(i,0,n){
        char c;
        cin >> c;
        poss.second.push_back(c-'0');
    }
    
    int ans = 0;
    incr(i,0,n){
        if(poss.second[i]){
            if(i-1>=0){
                if(poss.first[i-1]==1){
                    ans++;
                    poss.first[i-1] = 0;
                    continue;
                }
            }
            if(poss.first[i]==0){
                ans++;
                poss.first[i] = 0;
                continue;
            }
            if(i+1<n){
                if(poss.first[i+1]==1){
                    ans++;
                    poss.first[i+1] = 0;
                    continue;
                }
            }
        }
        
    }
    cout << ans << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}