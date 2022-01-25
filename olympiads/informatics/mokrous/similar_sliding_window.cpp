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
template <typename T>
class sparse_table
{
private:
    vector <vector <T>> data;
    size_t size_it = 0;
public:
    void resize(size_t new_size){
        size_t t = __lg(new_size)+1;
        data.resize(t);
        for(size_t i = 0; i < t; i++){
            data[i].assign(new_size,INF);
        }
        size_it = new_size;
    }
    
    void init(vector <T> gh){
        resize(gh.size());
        data[0] = gh;
        for (int l = 0; l < __lg(size_it); l++){
            for (int i = 0; i + (2 << l) <= size_it; i++){
                data[l+1][i] = min(data[l][i], data[l][i + (1 << l)]);
            }
        }
    }
    T mins(size_t l, size_t r){ // [l,r)
        int t = __lg(r - l);
        return min(data[t][l], data[t][r - (1 << t)]);
    }
    void print(){
        for (int i = 0; i < data.size();i++){
            for (int j = 0; j < data[i].size();j++){
                if(data[i][j]==INF) cout << "-" <<" ";
                else cout << data[i][j] << " ";
            }
            cout << nl;
        }
    }
    sparse_table(size_t new_size){
        resize(new_size);
    }
    sparse_table(vector <T> gh){
        resize(gh.size());
        init(gh);
    }
    sparse_table(size_t new_size, vector <T> gh){
        resize(new_size);
        init(gh);
    }

};
inline void solve(){
    int n, k;
    cin >> n >> k;
    vi data;
    seev(data,n);
    sparse_table <int> tt(data);
    incr(i,0,n-k+1){
        cout << tt.mins(i,i+k) << " ";
    }
    cout << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}