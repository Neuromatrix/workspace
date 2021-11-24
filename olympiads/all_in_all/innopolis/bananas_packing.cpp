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

inline void solve(){
    ll n;
    cin >> n;
    vc<ll> data;
    seev(data,n);
    ll pack = 0;
    ll bananas = accumulate(all(data),0);
    incr(i,0,n-6){
        bool is_pack = true;
        while (data[i]!=0 && is_pack)
        {
            incr(j,i,i+7){
                if(data[j]==0){
                    is_pack = false;
                    break;
                }
            }
            if(is_pack){
                incr(j,i,i+7){
                    data[j]--;
                }
                pack++;
            }
        }     
    }
    cout << pack <<" " << accumulate(all(data),0) << nl;
}
void second_solve(){
    ll n;
    cin >> n;
    vc<ll> data;
    seev(data,n);
    ll pack = 0;
    ll bananas = accumulate(all(data),0LL);
    incr(i,0,n-6){
        ll mn = *min_element(data.begin()+i,data.begin()+i+7);
        incr(j,i,i+7){
            data[j]-=mn;
        }
        pack+=mn;
    }
    cout << pack <<" " << accumulate(all(data),0LL) << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) second_solve();
    return 0;
}