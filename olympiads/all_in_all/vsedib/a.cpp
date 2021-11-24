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
map <string, int> ingridents;
map <string, map<string, int>> recipe;
void make_drink(string res){
    fca(it, recipe[res]){
        ingridents[it.first]-=it.second;
    }
}
bool is_available(string res){
    fca(it, recipe[res]){
        if(ingridents[it.first]>=it.second) continue;
        else return false;
    }
    return true;
}
int how_many(){
    int ans = 0;
    fca(it, recipe){
        if(is_available(it.first)) ans++;
    }
    return ans;
}
inline void solve(){
    int n,m,klient;
    
    cin >> n;
    incr(i,0,n){
        string tmp;
        int x;
        cin >> tmp >> x;
        ingridents[tmp] = x;
    }
    cin >> m;
    incr(i,0,m){
        string res;
        int k;
        cin >> res >> k;
        incr(i,0,k){
            string tmp;
            int x;
            cin >> tmp >> x;
            recipe[res][tmp] = x;
        }
    }
    cin >> klient;
    incr(i,0,klient){
        cout << how_many() << nl;
        string tmp;
        cin >> tmp;
        make_drink(tmp);
    }
    cout << how_many() << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}