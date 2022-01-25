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
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void prepare(){
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);
}
class Z_array
{
    private:
        size_t size_it;
        string inp;
        vector <int> z_array;
    public:
        Z_array(string s){
            init(s);
        }
        Z_array();
        size_t size(){
            return size_it;
        }
        void init(string s){
            inp = s;
            size_it = s.length();
            int n = (int) s.length();
            z_array.resize(n);
            for (int i=1, l=0, r=0; i<n; ++i) {
                if (i <= r)
                    z_array[i] = min (r-i+1, z_array[i-l]);
                while (i+z_array[i] < n && s[z_array[i]] == s[i+z_array[i]])
                    ++z_array[i];
                if (i+z_array[i]-1 > r)
                    l = i,  r = i+z_array[i]-1;
            }
            return;
        }
        int operator[](size_t ind){
            return z_array[ind];
        }
        void print(string sep = " "){
            for(size_t i = 0; i < size_it; i++) {
                cout << z_array[i] << sep; 
            }
            cout << endl;
        }
};

vector <int> find_substring(string data, string pat){
    string zz = pat + "@" + data;
    Z_array arr(zz);
    int m = pat.size();
    vector <int> ans = {};
    for (size_t i = 0; i < arr.size(); i++){
        if(arr[i]==m) ans.push_back(i-m);
    }
    return ans;
    
}
inline void solve(){
    string a, b;
    cin >> a >> b;
    vi ans = find_substring(a,b);
    if(sz(ans)){
        cout << sz(ans) << nl;
        fca(it, ans){
            cout << it << " ";
        } cout << nl;
    } else {
        cout << 0 << nl;
    }
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}