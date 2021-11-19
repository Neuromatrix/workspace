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
    freopen("palindrome.in", "r", stdin);
    freopen("palindrome.out", "w", stdout);
}
int len_longest_palindrome(string s){
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    return max(2*(*max_element(d1.begin(),d1.end()))-1,2*(*max_element(d2.begin(),d2.end())));
}
vector <pair <int, int>> pair_palindrome_index(string s){
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    vector <pair <int, int>> ans = {};
    for (size_t i = 0; i < n; i++){
        for(size_t l = 1; l < d1[i]; l++){
            ans.push_back({i-l,i+l});
        }
    }
    for (size_t i = 0; i < n; i++){
        for(size_t l = 0; l < d2[i]; l++){
            ans.push_back({i-l,i+l-1});
        }
    }
    return anss;
}
ll count_pair_palindrome_index(string s){
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    ll anss = 0;
    for (size_t i = 0; i < n; i++){
        for(size_t l = 1; l < d1[i]; l++){
            anss++;
        }
    }
    for (size_t i = 0; i < n; i++){
        for(size_t l = 0; l < d2[i]; l++){
            anss++;
        }
    }
    return anss;
}
string longest_palindrome(string s){
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    string ann;
    int lens = max(2*(*max_element(d1.begin(),d1.end()))-1,2*(*max_element(d2.begin(),d2.end())));
    if(lens == 2*(*max_element(d1.begin(),d1.end()))-1){
        int ind = max_element(d1.begin(),d1.end()) - d1.begin();
        for (size_t i = ind-d1[ind]+1; i < lens+1; i++){
            ann.push_back(a[i]);
        }
        
    } else {
        int ind = max_element(d2.begin(),d2.end()) - d2.begin();
        for (size_t i = ind-d2[ind]+1; i < lens+1; i++){
            ann.push_back(a[i]);
        }
    }
    return ann;
}
inline void solve(){
    
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}