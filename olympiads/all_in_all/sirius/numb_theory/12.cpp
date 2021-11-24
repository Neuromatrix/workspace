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
map <ll,ll> factoriz_with_map(ll N){ 
    map <ll,ll> f;
    for(ll i = 2; i * i <= N; i++){
        while(N%i == 0){
            f[i]++;
            N/=i;
        }
    }
    if (N > 1) f[N]++;
    return f;
}
inline void solve(){
    ll n;
    cin >> n;
    map <ll, ll> pre,res;
    incr(i,2,n+1){
        pre = factoriz_with_map(i);
        fca(it, pre){
            res[it.F]+=it.S;
        }
    }
    ull ans = 1;
    fca(it, res){
        ans*=(it.second+1);
    }
    cout << ans << endl;
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}