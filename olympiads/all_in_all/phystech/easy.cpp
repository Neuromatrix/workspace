#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
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
ll BinToInt(deque <bool> a){
	ll max_pow = a.sz-1;
    ll ans = 0;
    incr(i,0,a.sz){
        ans+=a[i]*binPow(10,max_pow);
        max_pow--;
    }
    return ans;
}
ll binary(ll x){
    ll ans = 0;
    deque <bool> pre_ans;
    while(x>1){
        pre_ans.push_front(x%2);
        x/=2;
    }
    pre_ans.push_front(1);
    ans = BinToInt(pre_ans);
    return ans;
}
inline void solve(){
    ll ans = 0;
    for(ll i = 2021; i <= 1000000; i++){
        if(binary(i)==i) ans++;
    }
    cout << ans << nl;
    return;
}

int main(){
    IOS;
    prepare();
    size_t tests = 1;
    //cin >> tests;
    while(tests--) solve();
    return 0;
}