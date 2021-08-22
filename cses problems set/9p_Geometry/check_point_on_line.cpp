// https://cses.fi/problemset/task/2189
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
    return acos(vec_mult(a, b)/(a.len() * b.len()));
}
inline void solve(){
    point s1,s2,p;
    cin >> s1.x >> s1.y >> s2.x >> s2.y >> p.x >> p.y;
    vecs line(s1,s2);
    vecs to(s2,p);
    ld j = vec_mult(line, to);
    if (j<0) cout << "RIGHT" << nl;
    if (j==0) cout << "TOUCH" << nl;
    if (j>0) cout << "LEFT" << nl;
    return;
}
 
int main(){
    IOS;
    //prepare();
    size_t tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}