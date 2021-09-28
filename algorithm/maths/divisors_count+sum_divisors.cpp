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
long long binPow(long long a, long long pow,long long mod = LLONG_MAX){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a%=mod;
	} else {
		ll part = binPow(a, pow >> 1,mod)%mod;
		if (pow & 1) {
			return (((part * part)%mod) * a)%mod;
		} else {
			return (part * part)%mod;
		}
	}
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
ll sum_of_divisors(ll N){
    map <ll, ll> ans = factoriz_with_map(N);
    ll accum = 1;
    fca(a, ans){
        accum*=(binPow(a.F,a.S+1)-1)/(a.first-1);
    }
    return accum;
}
inline void solve(){
    ll n;
    cin >> n;
    cout << divisors_count(n) << " " << sum_of_divisors(n) << endl;
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}