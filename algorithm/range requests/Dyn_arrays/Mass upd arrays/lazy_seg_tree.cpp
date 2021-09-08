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
        size_t MAXN = 0;
    void build (vector <T> a, int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
        }
    }
 
    void update (int v, int tl, int tr, int l, int r, T add) {
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
    int sum (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum (v*2, tl, tm, l, min(r,tm))
            + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    }
    int get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
    public:
        lseg_tree(size_t size, vector <T> data){
            MAXN = size;
            t.resize(4*MAXN);
        }
        lseg_tree(vector <T> data){
            MAXN = data.size();
            t.resize(4*MAXN);
        }
        lseg_tree(size_t size){
            MAXN = size;
            t.resize(4*MAXN);
        }
        lseg_tree();
        void init(vector <T> data){
            MAXN = data.size();
            t.resize(4*MAXN);
            build(data,1,0,MAXN-1);
        }
        T get(int pos){
            return get(1,0,MAXN-1,pos);
        }
        T sum_seg(int l,int r){
            return sum(1,0,MAXN-1,l,r);
        }
        void one_update(int pos, T add){
            update(1,0,MAXN-1,pos,pos,add);
        }
        void mass_update(int l,int r, T add){
            update(1,0,MAXN-1,l,r,add);
        }
        void print(string sep = " "){
            for(size_t i = 0; i < MAXN; i++){
                cout << get(i) <<sep;
            }
            cout << endl;
        }
};


inline void solve(){
    
}
int main(){
    IOS;
    prepare();
    solve();
    return 0;
}