// https://cses.fi/problemset/task/1092
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

inline void solve(){
    ll n, sum;
    cin >> n;
    sum=n*(n+1)/2;
    if (sum%2==0){
        sum=sum>>1;
        list <ll> pool;
        vector <ll> ans;
        incr(i,1,n+1) pool.push_back(i);
        while (pool.back()<=sum){
            sum-=pool.back();
            ans.push_back(pool.back());
            pool.pop_back();
        }
        if (sum > 0){
            auto it = find(all(pool),sum);
            if (it!=pool.end()){
                ans.push_back(*it);
                pool.erase(it);
            }
        }
        cout << "YES" <<nl;
        cout << pool.size() <<nl;
        fca(a,pool) cout << a  << " ";cout <<nl;
        cout << ans.size() <<nl;
        fca(a,ans) cout << a  << " ";cout <<nl;
    }
    else cout << "NO"<<nl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}