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
template <typename T>
class lseg_tree
{
    private:
        vector <T> t;
        int size_it = 0;
        
        void build (vector <T> a, int v, int tl, int tr) {
            if (tl == tr)
                t[v] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build (a, v*2, tl, tm);
                build (a, v*2+1, tm+1, tr);
            }
        }
    public:
        void init(vector <T> a){
            t.resize(4*a.size());
            size_it = a.size();
            build(a,1,0,size_it - 1)
        }
        void update (int v = 1, int tl = 0, int tr = size_it -1 , int l = 0, int r = size_it-1, int add = 1) {
            if (l > r)
                return;
            if (l == tl && tr == r)
                t[v] += add;
            else {
                int tm = (tl + tr) / 2;
                update (v*2, tl, tm, l, min(r,tm), add);
                update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            }
        }
 
        T get (int v = 1, int tl = 0, int tr = size_it-1, int pos = 0 ) {
            if (tl == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                return t[v] + get (v*2, tl, tm, pos);
            else
                return t[v] + get (v*2+1, tm+1, tr, pos);
        }
        
};


inline void solve(){
    vi data= {1,2,3,4,5};
    
}
int main(){
    IOS;
    prepare();
    solve();
    return 0;
}