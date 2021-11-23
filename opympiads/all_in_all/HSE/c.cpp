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
				inc(i,pool[i]);
			}
		}
		void inc(size_t i, T new_el){
			for(;i < data.size(); i = i | (i+1)){
				data[i]+=new_el;
			}
		}
		void print(){
			for (const auto & it : data) cout << it << " "; cout << '\n';
		}
		ll sum(int r){
			ll res = 0;
			for (;r >= 0; r = (r&(r + 1))-1){
				res+=data[r];
			}
			return res;
		}
		ll sum(size_t l, size_t r){
			return sum(r) - sum(l - 1);
		}			
};
inline void solve(){
    int n;
    cin >> n;
    int w;
    cin >> w;
    vc <ll> data;
    seev(data,n);
    fenwik_tree <ll> finwik;
    finwik.init(data);
    
    while(w--){
        int c,index,l,d,x;
        cin >> c;
        if(c==1){
            cin >> index >> x;
            index--;
            int el = finwik.sum(index,index); 
            finwik.inc(index,x-el);
        } else {
            cin >> l >> d;
            l--;
            ll sum = finwik.sum(l,n-1);
            while(l+d-1<n){
                sum-=finwik.sum(l+1,l+d-1);
                l+=d;
            }
            cout << sum << endl;
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