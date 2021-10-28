#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
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
template <typename T>
class prefix_sum
{
private:
    vector <T> pre_sum;
    size_t size_it;
public:
    void init(vector <T> pool){
        size_it = pool.size();
        pre_sum.resize(size_it);
        pre_sum[0] = pool[0];
        for (size_t i = 1; i < size_it; i++){
            pre_sum[i] = pre_sum[i-1] + pool[i];
        }
    }
    T sum(ssize_t l, ssize_t r){
        assert(!(l < 0  || r < 0 || l > size_it || r > size_it));
        if (min(l,r) > 0) return pre_sum[max(l,r)]-pre_sum[min(l,r)-1];
        else return pre_sum[max(l,r)];
    }
    size_t size(){
        return size_it;
    }
    prefix_sum(vector <T> pool){
        init(pool);
    }
    prefix_sum(){
        size_it = 0;
    }
};
inline void solve(){
    int b, g, n;
    cin >> b >> g >> n;
    vi boys;
    vi girls;
    incr(i,0,n+1){
        boys.pb(i);
        girls.pb(n-i);
    }
    prefix_sum <int> bboys(boys);
    prefix_sum <int> ggirls(girls);
    int len = INF;
    incr(l,0,n+1){
        incr(r,l+1,n+1){
            int lenx = r-l+1;
            if(bboys.sum(l,r)>= b and ggirls.sum(l,r)>=g){
                len = min(len, lenx);
                cout << l << " " << r << nl;
            }
        }
    }
    cout << len << nl;

}
int main(){
    IOS;
    prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}