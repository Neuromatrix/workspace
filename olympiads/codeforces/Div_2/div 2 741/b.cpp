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
vector <bool> eratostene_is_prime(int N){
    vector <bool> sieve;
    sieve.assign(N<<1,0);
    for (int i = 2; i <= N; i++){
        if (sieve[i]) continue;
        for (int j = i<<1; j <= N; j+=i){
            sieve[j] = true;
        }
    }
    return sieve;
}
inline void solve(){
    vector <bool> sieve = eratostene_is_prime(110);
    int n;
    cin >> n;
    string numb;
    cin >> numb;
    incr(i,0,n){
        if(sieve[numb[i]-'0'] || numb[i] =='1' ) {cout << 1 << nl << numb[i] << nl; return;}
    }
    incr(i,0,n){
        incr(j,i,n){
            if (i==j) continue;
            else{
                if(sieve[(numb[i]-'0')*10+(numb[j]-'0')]) {cout << 2 << nl << numb[i] << numb[j] << nl; return;}
            }
        }
    }
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