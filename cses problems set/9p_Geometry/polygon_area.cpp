// https://cses.fi/problemset/task/2191
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

inline void solve(){
    int n;
    cin >> n;
    vector <point> data(n); 
    incr (i,0,n){
        cin >> data[i].x >> data[i].y;
    }
    ld ans_sum = 0; 
    incr(i,0,n){
        int j = i + 1;
        if (j >= n) j = 0;
        ans_sum += (data[i].x * data[j].y) - (data[j].x * data[i].y);
    }
    ans_sum = ans_sum < 0 ? -ans_sum : ans_sum;
    cout << ans_sum << nl;
}
 
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    //cin >> tt;
    while (tt--) solve();
    return 0;
}