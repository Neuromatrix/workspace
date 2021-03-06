// #include <bits\stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
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
vi data;
inline bool is_loc(int i){
    if(i<=0 && i>=data.sz) return false;
    else{
        if(data[i-1] <data[i] && data[i+1] < data[i]) return true;
        else return false;
    }
}
inline void solve(){
    int x;
    cin >> x;
    while (x!=0){
        
        data.pb(x);
        cin >> x;
    }
    vi ans;
    incr(i,0,data.sz-1){
        if(is_loc(i)) ans.pb(i);
    }
    if(ans.sz<=1) cout << 0 << nl;
    else{
        int min_dist = INF;
        incr(i,0,ans.sz-1){
            min_dist = min(min_dist,ans[i+1]- ans[i]);
        }
        cout << min_dist << nl;
    }
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}