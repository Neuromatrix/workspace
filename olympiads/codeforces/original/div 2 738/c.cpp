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
    bool flag = true;
    int n; cin >> n; // бех последнего города
    vi city(n+1);// нат унмерация
    incr(i,1,n+1){
        cin >> city[i];
    }
    if(city[n]==0){
        incr(i,1,n+2){
            cout << i << " ";
        }
        cout << nl;
        return;
    }   
    else if(city[1]==1){
        cout << n+1 << " ";
        incr(i,1,n+1){
            cout << i << " ";
        }
    }
    else{
        incr(i,1,n+1){
            if (city[i]==0 && city[i+1]==1 && flag){
                cout << i << " " << n+1 << " " <<i+1 << " "; i++;
                flag = false;
            } else {
                cout << i << " ";
            }
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