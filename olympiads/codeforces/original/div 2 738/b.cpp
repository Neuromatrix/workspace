#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#define B 'B'
#define R 'R'
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    int n; 
    cin >> n;
    string v;
    
    cin >> v;
    int f_i = n;
    vector <char> ans(n);
    incr(i,0,n){
        if(v[i]==B || v[i]==R){
            f_i = i;
            ans[i] = v[i];
            break;
        }
    }
    if (f_i==n){
        incr(i,0,n){
            if(i&1) cout << B;
            else cout << R;
        }
    }
    else{
        if (f_i & 1){
            incr(i,0,f_i){
                if (i & 1){
                    cout << ans[f_i];
                } else {
                    if (ans[f_i]==B) cout << R;
                    else cout << B;
                }
            }
        }
        else{
            incr(i,0,f_i){
                if (!(i & 1)){
                    cout << ans[f_i];
                } else {
                    if (ans[f_i]==B) cout << R;
                    else cout << B;
                }
            }
        }
    }
    incr(i,f_i,n){
        if (v[i]=='?'){
            if (ans[i-1]==B) {ans[i] = R; cout << R;}
            else {ans[i] = B; cout << B;}
        }else {
            ans[i] = v[i];
            cout << ans[i];
        }
        
    }
    cout << nl;
    return;
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}