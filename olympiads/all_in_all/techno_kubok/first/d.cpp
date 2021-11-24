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
#define rofna(i, a, b)  for (int i = (b)-1; i >= (a); --i)
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    ll n;
    cin >> n;
    ll end = n;
    rofna(i, 2, n+1) {
        cout << "? ";
        incr(_,0, n - 1) {
            cout << "1 ";
        }
        cout << i << endl;
        ll k;
        cin >> k;
        if (k!=0) {
            end = n - i+1;
            break;
        }
    }
    vector<ll> ans(n);
    ans[n - 1] = end;
    int pp = end - 1;
    incr(i, 1, n+1) {
        if (i == end || i-end + 1 == 0) continue;
        if (i - end + 1 > 0) {
            cout << "? ";
            incr(_,0, n - 1) {
                cout << "1 ";
                cout.flush();
            }
            cout << i - end + 1 << endl;
            ll k;
            cin >> k;
            ans[k - 1] = i;
        }
        else {
            cout << "? ";
            incr(_,0, n - 1) {
                cout << n << " ";
            }
            cout << n + i - end << endl;
            ll k;
            cin >> k;
            ans[k - 1] = i;
        }
    }
    incr(i,0, n)
        if (!ans[i])
            ans[i] = pp;
 
    cout << "! ";
    fca(it,ans) cout << it << " ";
    cout << endl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}