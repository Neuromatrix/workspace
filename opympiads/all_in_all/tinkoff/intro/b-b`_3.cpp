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
vector <long long> divisors(long long N){
    vector <long long> ans;
    ans.push_back(1);
    if (N == 1) {return ans;}
    for(long long i = 2; i*i <=N; i++){
        if (N%i==0) ans.push_back(i);
    }
    return ans;
}
ll abss(ll x){
    return x < 0 ? -x : x;
}
ll check_manhatt(ll x1, ll y1, ll x2, ll y2){
    return abss(x1-x2)+abss(y1-y2);
}
inline void solve(){
    ll k;
    cin >> k;
    vector <ll> divii = divisors(k);
    ll mins = LLONG_MAX;
    fca(div, divii){
        mins = min(mins,check_manhatt(1,1,div,k/div));
    }
    cout << mins << nl;
    return;
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    while(tests--) solve();
    return 0;
}