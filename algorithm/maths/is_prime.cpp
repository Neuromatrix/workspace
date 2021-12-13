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
template <typename t>
bool easy_prime(t N){
    if (N < 2) return false;
    for(t i = 2; i*i <=N; i++){
        if (N%i==0) return false;
    } 
    return true;
}
long long mul(long long a, long long b, long long m = LLONG_MAX){
	if(b==1)
		return a;
	if(b%2==0){
		long long t = mul(a, b/2, m);
		return (2 * t) % m;
	}
	return (mul(a, b-1, m) + a) % m;
}
//! Ferma`s test
long long pows(long long a, long long b, long long m = LLONG_MAX){
	if(b==0)
		return 1;
	if(b%2==0){
		long long t = pows(a, b/2, m);
		return mul(t , t, m) % m;
	}
	return ( mul(pows(a, b-1, m) , a, m)) % m;
}
inline ll e_gcd(ll a, ll b){
    if (b==0) return a;
    else return e_gcd(b,a%b); 
}
bool fast_prime(long long x){
    if(x == 2)
		return true;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		long long a = (rand() % (x - 2)) + 2;
		if (e_gcd(a, x) != 1)
			return false;			
		if( pows(a, x-1, x) != 1)		
			return false;			
	}
	return true;
}
inline void solve(){
    ll n;
    cin >> n;
    if(fast_prime(n)) cout << "YES" << nl;
    else cout << "NO" << nl;
    return;
}

int main(){
    IOS;
    // prepare();
    solve();
    return 0;
}