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
class equation
{
private:
    ll a = 0, b = 0, c = 0, g = 0;
    bool fall = true;
    inline tuple <ll, ll, ll> gcd(ll a, ll b){
        if(b==0) return {1,0,a};
        else{
            ll x, y, g;
            tie(x,y,g) = gcd(b,a%b);
            return {y,x-(a/b)*y,g};
        }
    }
public:
    void init(ll _a_,ll _b_, ll _c_){
        a = _a_;
        b = _b_;
        c = _c_;   
        solve();     
    }
    bool solvable(){
        return fall;
    }
    pair <int, int> solve(){
        ll x, y, mult;
        tie(x,y,g) = gcd(a,b);
        if (c%g == 0){
            mult  = c/g;
            fall = true;
            return make_pair(x*mult, y*mult);
        } else {
            fall = false;
            return make_pair(0,0);
        }
    }
    pair <int, int> solve(int k){
        ll x, y, mult;
        tie(x,y,g) = gcd(a,b);
        if (c%g == 0){
            mult  = c/g;
            fall = true;
            return make_pair(x*mult+(b*k)/g, y*mult-(a*k)/g);
        } else {
            fall = false;
            return make_pair(0,0);
        }
    }
    ll ggcd() {return g;}
    equation(){}
};


inline void ssolve(){

}

int main(){
    IOS;
    prepare();
    ssolve();
    return 0;
}