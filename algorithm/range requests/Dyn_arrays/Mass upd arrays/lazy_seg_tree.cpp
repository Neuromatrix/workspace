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
        vector <T> tree;
        vector <T> mod; 
        int size_it = 0;
        void push(int v, int tl, int tr) {
            if (mod[v] != 0 && v * 2 + 1 < 4*size_it){
                mod[v * 2] = mod[v * 2 + 1] = mod[v];
                mod[v] = 0;
                int tm = (tl + tr) / 2;
                tree[v * 2] += (tm - tl + 1) * mod[v * 2];
                tree[v * 2 + 1] += (tr - tm) * mod[v * 2 + 1];
            }
        }
        void build (const vector <T> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }
        void update (int v, int tl, int tr, int l, int r, int val) {
            if (l <= tl && tr <= r) {
                tree[v] += val * (tr - tl + 1);
                mod[v] = val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
        T sum (int v, int tl, int tr, int l, int r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return 0;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return sum( v * 2, tl, tm, l, r)
                + sum(v * 2 + 1, tm + 1, tr, l, r);
        }
    public:
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
        T get(int pos){
            return sum(1,0,size_it-1,pos,pos);
        }
        void update(int l, int r, int add){
            update(1,0,size_it-1,l,r,add);
        }
        T sum(int l, int r){
            return sum(1,0,size_it-1,l,r);
        }
        lseg_tree(vector <T> a){
            init(a);
        }
        lseg_tree(){}
        void print(){
            incr(i,0,tree.sz){
                cout << tree[i] << " ";
            }
            cout << nl;
        }
};


inline void solve(){
    vi data= {1,1,1,1,1,1,1,1};
    lseg_tree <int> tree(data);
    cout << tree.sum(0,7) << nl;
    tree.update(0,3,2);
    tree.print();
    cout << tree.sum(0,1) << nl;
}
int main(){
    IOS;
    prepare();
    solve();
    return 0;
}