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
T pow(T a, T poww,long long mod = LLONG_MAX){
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
struct Point
{
    int x;
    int y;
};
int n;
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
        vec2d operator+(vec2d b){
            return vec2d(x+b.x,y+b.y);
        }
        vec2d(){}
        vec2d(int i, int j){x = i;y = j;}
        vec2d(ld i, ld j){x = i;y = j;}
        vec2d(Point from, Point to){
            x = to.x - from.x;
            y = to.y - from.y;
        }
};
ld cos(vec2d a,vec2d b){
    return a*b/(a.length()*b.length());
}
ld operator^(vec2d a, vec2d b){//angle
    return acos(cos(a,b));
} 
// bool onSegment(Point p, Point q, Point r)
// {
//     if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
//         q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
//        return true;
 
//     return false;
// }
// int orientation(Point p, Point q, Point r){
//     int val = (q.y - p.y) * (r.x - q.x) -
//               (q.x - p.x) * (r.y - q.y);
 
//     if (val == 0) return 0;
 
//     return (val > 0)? 1: 2;
// }
// bool doIntersect(Point p1, Point q1, Point p2, Point q2)
// {
//     int o1 = orientation(p1, q1, p2);
//     int o2 = orientation(p1, q1, q2);
//     int o3 = orientation(p2, q2, p1);
//     int o4 = orientation(p2, q2, q1);
//     if (o1 != o2 && o3 != o4)
//         return true;
//     if (o1 == 0 && onSegment(p1, p2, q1)) return true;
//     if (o2 == 0 && onSegment(p1, q2, q1)) return true;
//     if (o3 == 0 && onSegment(p2, p1, q2)) return true;
//     if (o4 == 0 && onSegment(p2, q1, q2)) return true;
//     return false;
// }
// int n;
// void pretest1(){
//     vc <Point> points; vvi G(n+1);
//     vi ans = {};
//     incr(i,0,n-1){
//         int a, b;
//         cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//     incr(i,0,n){
//         int a, b;
//         cin >> a >> b;
//         Point x;
//         x.x = a, x.y = b;
//         points.push_back(x);
//         ans.push_back(i+1);
//     }
//     vector <pair <Point, Point>> seg;
//     do{
//         incr(i,1,n+1){
//             vi cur = G[i];
//             fca(child, cur){
//                     seg.push_back({points[find(all(ans),i)-ans.begin()],points[find(all(ans),child)-ans.begin()]});
//             }
//         }
//         bool bad = false;
//        vector <pair <Point, Point>>::iterator i = seg.begin(), j = seg.begin();
//         for (; i!=seg.end(); i++)
//         {
//             for (; j!=seg.end(); j++)
//             {
//                 if(i==j) continue;
//                 Point p1, p2, q1, q2;
//                 p1 = i->first;
//                 p2 = i->second;
//                 q1 = j->first;
//                 q2 = j->second;
//                 if(p1.x==q2.x && p1.y==q2.y && q1.x==p2.x && q1.y==p2.y) continue;
//                 if(!doIntersect(p1,p2,q1,q2)) bad = true;
//             }
//         }

//         seg.clear();
//         if(bad) continue;
//         else{
//             cout << ans << nl;
//             return;
//         }
//     } while (next_permutation(all(ans)));
    
// }
void convexHull(vector<Point> points, int n)
{
    if (n < 3) return;
    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    map <int, bool> visited;
    visited[p] = true;
    do
    {
        fca(it, visited) cout << it.first << " "  << it.second << nl; cout <<  nl;
        hull.push_back(points[p]);
        q = (p+1)%n;
        ld mxcos = -INF;
        for (int i = 0; i < n; i++)
        {
            vec2d hg(points[p], points[i]), gh(points[i], points[q]);
           if (cos(gh,hg)>mxcos && visited[q]==false){
               q = i;
               mxcos = cos(gh,hg);
           }
        }
        cout <<q << nl;
        visited[p] = true;
        p = q;
        
 
    } 
    while (visited[p]==false);
    // do
    // {
    //     hull.push_back(points[p]);
    //     q = (p+1)%n;
    //     for (int i = 0; i < n; i++)
    //     {
    //        if (orientation(points[p], points[i], points[q])!=0 && visited[q]==false)
    //            q = i;
    //     }
    //     cout <<q << nl;
    //     visited[p] = true;
    //     p = q;
        
 
    // } while (visited[p]==false);
    // Print Result
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}
void pr2(){
    vc <Point> points; vvi G(n+1);
    vi ans = {};
    // incr(i,0,n-1){
    //     int a, b;
    //     cin >> a >> b;
    //     G[a].push_back(b);
    //     G[b].push_back(a);
    // }
    incr(i,0,n){
        int a, b;
        cin >> a >> b;
        Point x;
        x.x = a, x.y = b;
        points.push_back(x);
        ans.push_back(i+1);
    }
    convexHull(points,n);

}
inline void solve(){
    cin >> n;
    // if(n<=6) {pretest1(); return;}
    pr2();
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}