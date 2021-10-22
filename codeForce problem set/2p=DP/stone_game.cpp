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
    unsigned int n;
    cin >> n;
    deque<int> data;
    seev(data,n);
    int ans = 0;
    unsigned int max_i = 0, min_i = 0;
    int maxx = -INF, minn = INF;
    incr(i,0,n){
        if(data[i]>maxx){
            maxx=data[i];
            max_i = i;
        }
        if(data[i]<minn){
            minn=data[i];
            min_i = i;
        }
    }
    int max_side = min(n-max_i-1, max_i);
    int min_side = min(n-min_i-1,min_i);
    if(min_side < max_side){
        if(n-min_i-1<min_i){
            incr(i,0,min_side+1){
                data.pop_back();
            }
        } else {
            incr(i,0,min_side+1){
                data.pop_front();
            }
        }
        ans+=min_side+1;
        maxx = -INF;
        incr(i,0,data.size()){
            if(data[i]>maxx){
                maxx=data[i];
                max_i = i;
            }
        }
        ans+=min(data.size()-max_i-1, max_i)+1;
    } else {
        if(n-max_i-1<max_i){
            incr(i,0,max_side+1){
                data.pop_back();
            }
        } else {
            incr(i,0,max_side+1){
                data.pop_front();
            }
        }
        ans+=max_side+1;
        minn = INF;
        incr(i,0,data.size()){
            if(data[i]<minn){
                minn=data[i];
                min_i = i;
            }
        }
        ans+=min(data.size()-min_i-1, min_i)+1;
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