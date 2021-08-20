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
class point{
    public:
        ld  x,y;
        void make(ld  x, ld  y){
            this->x = x;
            this->y = y;
        }
        bool operator==(point b){
            if (this->x == b.x && this->y== b.y) return true;
            else return false;
        }
        point(){
            x = 0;
            y = 0;
        }
        point(ld  x, ld  y){
            this->x = x;
            this->y = y;
        }
};
class vecs{
    public:
        ld  x,y;
        ld  len(){
            return sqrt(this->x*this->x+this->y*this->y);
        }
        vecs();
        vecs(point a, point b){
            x = a.x - b.x;
            y = a.y - b.y;
        }
};
inline ld vec_mult(vecs a, vecs b){
    return a.x * b.y - b.x * a.y;
}
long double cos(vecs a, vecs b){
    return vec_mult(a, b)/(a.len() * b.len());
}
long double angle(vecs a, vecs b){
    return acos(vec_mult(a, b)/(a.len() * b.len()))*3.14/180;
}
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
int orientation(point p, point q, point r)
{
    ld val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(point p1, point q1, point p2, point q2)
{
    ld o1 = orientation(p1, q1, p2);
    ld o2 = orientation(p1, q1, q2);
    ld o3 = orientation(p2, q2, p1);
    ld o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}
inline void solve(){
    point a, b, c ,d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if (doIntersect(a,b,c,d)) cout <<"YES" << nl;
    else cout << "NO" << nl;
}
 
int main(){
    IOS;
    //prepare();
    size_t tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}