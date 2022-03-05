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
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
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
inline T bpow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
const ld pi = acos(-1);
class point2d{
    public:
        ld x = 0, y = 0;
        point2d operator+(point2d b){
            return point2d(x+b.x,y+b.y);
        }
        point2d operator+(ld i){
            return point2d(x+i,y+i);
        }
        point2d operator+(int i){
            return point2d(x+i,y+i);
        }
        void operator+=(point2d a){
            x+=a.x;
            y+=a.y;
            return;
        }
        void operator+=(ld i){
            x+=i;y+=i;
        }
        void operator+=(int i){
            x+=i;y+=i;
        }
        ld dist(point2d b){
            return sqrt(pw(x-b.x)+pw(y-b.y));
        }
        ld dist(){
            return dist(point2d(0,0));
        }
        friend ostream& operator<<(ostream &out, point2d a);
        point2d(){}
        point2d(int i, int j){x = i;y = j;}
        point2d(ld i, ld j){x = i;y = j;}
        
};
ostream& operator<< (ostream& out, point2d F){ 
    out << F.x<< " " <<F.y;
    return out; 
}

class vec2d{
    public:
        ld x, y;
        ld vec_product(vec2d b){ // нужно чтобы опрделить располложение двух                      
            return x*b.y-b.x*y;  // векторов относительно друг друга
        }
        ld length(){
            return sqrt(pw(x)+pw(y));
        }
        ld operator*(vec2d b){
            return x*b.x+b.y*y; 
        }
        void operator+=(ld i){
            x+=i;y+=i;
        }
        void operator+=(int i){
            x+=i;y+=i;
        }
        void operator+=(vec2d a){
            x+=a.x;
            y+=a.y;
            return;
        }
        ld distpoint(point2d n){

        }
        vec2d operator+(vec2d b){
            return vec2d(x+b.x,y+b.y);
        }
        vec2d(){}
        vec2d(int i, int j){x = i;y = j;}
        vec2d(ld i, ld j){x = i;y = j;}
        vec2d(point2d from, point2d to){
            x = to.x - from.x;
            y = to.y - from.y;
        }
};
ostream& operator<< (ostream& out, vec2d F){ 
    out << F.x<< " " <<F.y;
    return out; 
}
ld cos(vec2d a,vec2d b){
    if(a*b/(a.length()*b.length())>1){
        return 1;
    } else if (a*b/(a.length()*b.length())<-1){
        return -1;
    } else return a*b/(a.length()*b.length());
}
ld operator^(vec2d a, vec2d b){//angle
    return acos(cos(a,b));
}
ld ang(ld rad){
    return (rad*180.0)/pi;
}
class line2d{
    public:
    ld a = 0, b = 0, c = 0;
    ld dist(point2d f){
        return abs(a*f.x+b*f.y+c)/sqrt(a*a+b*b);
    }
    void print(){
        cout << a << " " << b << " " << c << nl;
    }
    line2d(point2d n, point2d m){
        a = n.y - m.y;
        b = m.x - n.x;
        c = n.x*m.y - n.y*m.x;
    }
    line2d(){}

};

inline void solve(){
    point2d a, b, c, d;
    cin >> a.x >> a.y >> 
    b.x >> b.y >>
    c.x >> c.y >>
    d.x >> d.y;
    line2d cd(c,d);
    setpr(6);
    //!1
    cout <<a.dist(c) << nl;
    //2
    
    //3
    //!4
    cout << cd.dist(a) << nl;
    //5
    //6
    //7
    //8
    //9
    //10
    //!11
    cout << 0.0 << nl;
    //!12
    cout << 0.0 << nl;
    //13
    //14
    //!15
    cout << 0.0 << nl;
    //!16
    cout << 0.0 << nl;

}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}