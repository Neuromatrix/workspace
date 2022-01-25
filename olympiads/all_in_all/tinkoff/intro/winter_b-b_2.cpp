#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.fi << " " << v.se;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
T pow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int  q;
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
    void print(){
        fca(it, pre_sum) cout << it << " "; cout << nl;
    }
};
constexpr int n = 2e5+1;
const int nblocks = 224;
int len = 893;
int b[nblocks][n];

void prep(vc<ll> &data){
    prefix_sum <ll> pr(data);
    ll h[n+1];
    incr(i,0,nblocks){
        int l = len*i, r = min(len*(i+1),(ll)n);
        vi cnt(n,0);
        incr(j,l,r){
            cnt[data[j]]++;
        }
        h[0] = 0;
        h[1] = 0;
        for (size_t j = 1; j < n; j++){
            h[j+1] = h[j] + cnt[j];
        }
        incr(x,1,n){
            b[i][x]=pr.sum(l,r-1);
            for(int m = 0; m < n; m+=x){
                b[i][x] -= m*(h[min((ll)n,m+x)]-h[m]);
            }
        }
    }
}
inline void solve(){
    int iyy;
    cin >> iyy >> q;
    vector<ll> a(n);
    incr(i,0,iyy){
        cin >> a[i];
    }
    prep(a);
    while (q--){
        int l , r, x;
        cin >> l >> r >> x;
        l--; r--;
        ll sum = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
                sum += a[i]%x;
        else {
            for (int i=l, end=(c_l+1)*len; i<end; ++i)
                sum += a[i]%x;
            for (int i=c_l+1; i<c_r; ++i)
                sum += b[i][x];
            for (int i=c_r*len; i<=r; ++i)
                sum += a[i]%x;
        }
        cout << sum << nl; 
    }

    return;

}
void yt(){
    cout << 3000 << " " << 100 << nl;
    incr(i,0,3000){
        cout << 2 << " ";
    }
    cout << nl;
    incr(i,0,100){
        cout << 1 << " " << 2890 << " " << " 2" << nl;
    }
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}