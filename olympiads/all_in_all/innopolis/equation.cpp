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
ll abs_(ll x){
    return x<0 ? -x : x;
}
ll divisors_count(ll N){ 
    ll ans = 1;
    for(ll i = 2; i * i <= N; i++){
        ll k = 1;
        while(N%i == 0){
            k++;
            N/=i;
        }
        ans*=k;
    }
    if (N > 1) ans*=2;
    return ans;
}
inline void solve(){
    ll l, r;
    cin >> l >> r;
    set <pii> trie;
    ll ans = 0;
    incr(b,-100000*2,100001*2){
        incr(c,-b+l,r-b+1){
            if(l<=b+c && b+c<=r && b*b>4*c){
                if(sqrt(b*b-4*c)==ceil(sqrt(b*b-4*c))){
                    if((-b-sqrt(b*b-4*c))/2==ceil((-b-sqrt(b*b-4*c))/2) && (-b+sqrt(b*b-4*c))/2==ceil((-b+sqrt(b*b-4*c))/2)){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans<< nl;
}
inline void secnd(){
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    incr(i,l,r+1){
        ans+=divisors_count((i<0 ? -i-1 : i+1));
    }
    cout << ans << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) secnd();
    return 0;
}