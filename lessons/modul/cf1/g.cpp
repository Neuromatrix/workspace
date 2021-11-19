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
    vi peop;
    vi ans;
    seev(peop,n);
    incr(i,0,n){
        incr(j,0,n){
            if(i==j) continue;
            vi tmp;
            incr(k,0,n){
                if(k==i || k==j) continue;
                tmp.push_back(peop[k]);
            }
            sort(rall(tmp));
            int sum1 = peop[i], sum2 = peop[j];
            incr(k,0,tmp.sz){
                if(k%2==0){
                    sum1+=tmp[k];
                } else {
                    sum2+=tmp[k];
                }
            }
            ans.pb(abs(sum1-sum2));
        }
    }
    cout << *min_element(all(ans)) << nl;
}
int main(){
    IOS;
   // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}