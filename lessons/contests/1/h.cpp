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
vector <bool> eratostene_is_prime(int N){
    vector <bool> sieve;
    sieve.assign(N<<1,0);
    for (int i = 2; i <= N; i++){
        if (sieve[i]) continue;
        for (int j = i<<1; j <= N; j+=i){
            sieve[j] = true;
        }
    }
    return sieve;
}
inline void solve(){
    int n, m;
    bool flag = true;
    cin >> n >> m;
    vc <bool> seive =  eratostene_is_prime(2*m);
    vi primes;
    incr(i,0,seive.sz){
        if (!seive[i]) primes.pb(i);
    }
    //fca(a,primes) cout <<a << nl;
    if(primes.sz==0) cout << 0 << nl;
    else {
        incr(i,0,primes.sz){
            if(primes[i]<n || primes[i]>m || primes[i]==2) continue;
            if(i!=0 && i+1!=primes.sz){
                if((primes[i+1]+primes[i-1])/2.0 == primes[i]) {cout << primes[i] << " "; flag = false;}
            } 
        }
    }
    if (flag) cout << 0 << nl;
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}