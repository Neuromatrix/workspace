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
vector <int> eratostene_factorize(int N){
    vector <int> sieve;
    sieve.assign(N+1,0);
    for (int i = 2; i <= N; i++){
        if (sieve[i]) continue;
        sieve[i] = i;
        for (int j = i<<1; j <= N; j+=i){
            if (sieve[j]) continue;
            else sieve[j] = i;
        }
    }
    return sieve;
}
inline void solve(){
    /*
        ...
    */
    fca(a, eratostene_factorize(20)) cout << a << " "; cout << nl;
    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}