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

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    string data;
    cin >> data;
    size_t n = data.sz, counter = 1, red = 0, green = 0, dif = 0;
    sort(all(data));
    incr(i, 0, n){
        int j = i;
        while(data[j]==data[j+1] && j+1<n){
            counter++;
            j++;
        }
        if (counter == 1){
            if (red<=green) red++;
            else green++;
        }
        else if (counter>=2){
            red++;
            green++;
        }
        i = j;
        counter = 1;
    }
    if (green == red) cout << red <<nl;
    else if (green > red) cout << red << nl;
    else cout << green << nl;
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