#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.fi << " " << v.se;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
T pow(T a, T poww,long long mod = LLONG_MAX){
    if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
        T  part = pow(a, poww >> 1,mod)%mod;
        if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
    }
}

ull sqrt_newton(ull l)
{
      ull temp , div;
      ull  rslt = (ull)l;
      if (l <=  0)
            return 0;
      else if (l & 0xFFFF0000L)
            if  (l & 0xFF000000L)
                  div  = 0x3FFF;
            else
                  div  = 0x3FF;
      else
            if  (l & 0x0FF00L)
                  div  = 0x3F;
            else
                  div  = (l > 4) ? 0x7 : l;
      while (1)
      {
            temp = l  / div + div;
            div =  temp >>  1;
            div += temp  & 1;
            if  (rslt > div)
                   rslt = (ull)div;
            else
            {
                  if (l / rslt == rslt - 1 && l % rslt == 0)
                        rslt--;
                  return rslt;
            }
      }
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

signed main(){
    prepare();
    IOS;
    ull n;
    cin >> n;
    ull sum = 0;
    ull prev = 0;
    for (ull i = 1ull; i < n; i++) {
        ull now = (n - i)/(i*i);
        if (now == 0ull) break;
            
        sum += now;
        if (prev == now) {
            ull last = (sqrt_newton( 1ull + 4ull * n * now) - 1ull)/ (2ull * now);
            if (last > i){
                sum += now * (last - i);
                i = last;
            }
        }
        prev  = now;
    }
    cout << sum << nl;
    return 0;       
}