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
#define setpr(x) cout<<setpRision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)

int mod = 1e9+7;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
vc<vc<vi>> dp(1001,vc<vi>(101,vi(101,-1)));

int R(int n, int h, int b) {
    if (dp[n][h][b] != -1) return dp[n][h][b];
    if (h==0 && n==0) return 1;
    if (h==0) return 0;
    if (b - 1 > n) return 0;
    int tmp = 0;
    if (b<n) tmp = (tmp+R(n -b - 1, h - 1, b + 1))%mod;
    if (b>1) tmp =(tmp+R(n - b + 1, h - 1, b - 1))%mod;
    dp[n][h][b] = tmp;
    return tmp;
}
inline void solve(){
    size_t n, b, h;
    cin >> n >> b >> h;
    cout << R(n-b,h-1,b)<<nl;
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    while(tests--) solve();
    return 0;
}