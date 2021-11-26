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
constexpr int INF = INT_MAX-1;
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
template <class T>
class fenwik_tree
{
	private:
		vector <T> data;
	public:
		void init(size_t n){
			data.assign(n,0);
		}
		void init(vector <T> pool){
			init(pool.size());
			for (int i = 0; i < pool.size(); i++){
				add(i,pool[i]);
			}
		}
		void add(size_t i, T new_el){
			for(;i < data.size(); i = i | (i+1)){
				data[i]+=new_el;
			}
		}
		void print(){
			for (const auto & it : data) cout << it << " "; cout << '\n';
		}
		T sum(int r){
			ll res = 0;
			for (;r >= 0; r = (r&(r + 1))-1){
				res+=data[r];
			}
			return res;
		}
		T sum(size_t l, size_t r){
			return sum(r) - sum(l - 1);
		}	
		T get(int index){
			return sum(index,index);
		}		
};
class sum_of_subtree
{
private:
    int n;
    vector <ll> ksum;
    vector <int> counter;
    map <int, int> index;
    vector <vector <int>> G;
    vector <int> id;
    fenwik_tree <ll> io;
    inline void dfs(int cur, int prev){
        id.push_back(cur);
        counter[cur] = 1;
        for(const auto & nex: G[cur]){
            if(nex==prev) continue;
            dfs(nex,cur);
            counter[cur]+=counter[nex];
    }
}
public:
    void init(vector <vector <int>> &gr,vector <ll> &ssum){
        G = gr;
        n = G.size();
        counter.resize(n);
        id.push_back(0);
        ksum.resize(n);
        dfs(1,0);
        for (size_t i = 1; i < n; i++){
            index[id[i]] = i;
        }
        for (size_t i = 1; i < n; i++){ 
            ksum[index[i]] = ssum[i];
        }
        io.init(ksum);
    }
    ll query(int s){
        return io.sum(index[s],index[s]+counter[s]-1);
    }
    void change(int s, int x){
        io.add(index[s],x-io.get(index[s]));
    }
    sum_of_subtree(/* args */){}
};


inline void solve(){
    int n, q;
    cin >> n >> q;
    vector <ll> sum(n+1);
    for (size_t i = 1; i <= n; i++){
        cin >> sum[i];
    }
    vvi G(n+1);
    incr(i,0,n-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    } 
    sum_of_subtree h;
    h.init(G,sum);
    while (q--){
        int comm;
        cin >> comm;
        if(comm==2){
            int s;
            cin >> s;
            cout << h.query(s) << nl;
        } else {
            int s, x;
            cin >> s >> x;
            h.change(s,x);
        }
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