#include <bits\stdc++.h>
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
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
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
    T sum(ssize_t l, ssize_t r){ //[l,r]
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
    int n ;
    cin >> n;
    vector <ll> ddata(n);
    for (int i = 0; i < n; i++){
       cin>>ddata[i];
    }   
    vector <ll> data;
    for (int k = 0; k < 3; k++){
        for (int i = 0; i < n; i++){
            data.push_back(ddata[i]);
        }
    }
    prefix_sum <ll> pr(data);
    vector <ll> ans(n,0);
    for(int i = 0; i <= n/2; i++){
        ans[0] += (i)*(data[n+i]+data[n-i]);
    }
    ans[0] -= (n/2)*(data[n/2]);
    for(int i = 1; i < n; i ++){
        ans[i] = ans[i-1]+pr.sum(n+i-n/2,n+i-1)-pr.sum(n+i,i+n+n/2-1);
    }
    cout << min_element(ans.begin(), ans.end()) - ans.begin() << nl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}