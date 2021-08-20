// https://cses.fi/problemset/task/1745
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
    int n,k = 0; cin >> n;
    vector <int> coins;
    seev(coins,n);
    int maxx = accumulate(coins.begin(), coins.end(), 0) + 1;
    vector <int> dp(maxx,0);
    dp[0] = 1;
    incr(i,0,n){
        decr(val,maxx,coins[i]-1){
            dp[val] |= dp[val-coins[i]];
        }
    }
    incr(i,1,maxx){
        if (dp[i]) k++;
    }
    cout << k << nl;
    incr(i,1,maxx){
        if (dp[i]) cout << i << ' ';
    }
    cout << nl;
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}