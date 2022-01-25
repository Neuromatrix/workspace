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
constexpr ll INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

template <typename T> 
class lseg_tree{
private:
    struct node{
        T sum;
        T hye;
        T increment;
        bool colors;
        node() : sum(0),colors(0),increment(0) { }
        void Reset(){
            colors = increment = 0;
        }
    };
    int range;
    vector<node> tree;
    void compose(int par, int child){
        if(tree[par].colors){
            tree[child].colors = 1;
            tree[child].hye = tree[par].hye;
            tree[child].increment = tree[par].increment;
        }
        else tree[child].increment += tree[par].increment;
    }
 
    void push(int node, int l, int r){
        if(tree[node].colors)
            tree[node].sum = (r-l+1)*tree[node].hye;
 
        tree[node].sum += (r-l+1)*tree[node].increment;
 
        if(l != r){
            compose(node, 2*node);
            compose(node, 2*node+1);
        }
 
        tree[node].Reset();
    }
    void build(vector<T>& v, int l, int r, int node_no){
        if(l == r){
            if(l < v.size())
                tree[node_no].sum = v[l];
            else tree[node_no].sum = 0;
            return;
        }
        int mid = (l+r)/2;
        build(v, l, mid, 2*node_no);
        build(v, mid + 1, r, 2*node_no+1);
        tree[node_no].sum = tree[2*node_no].sum + tree[2*node_no+1].sum;
    }
    T sum(int node, int l, int r, int& L, int& R)
    {
        if(r < L || R < l || l >= range)
            return 0;
        push(node, l, r);
        if(L <= l && R >= r)
            return tree[node].sum;
        int mid = (l+r)/2;
        return sum(2*node, l, mid, L, R) + sum(2*node+1, mid+1, r, L, R);
    }
    void add(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].increment += X;
            return;
        }
        push(node,l,r);
        int mid = (l+r)/2;
        add(2*node,l,mid,L,R,X);
        add(2*node+1,mid+1,r,L,R,X);
        push(2*node, l, mid);
        push(2*node+1, mid+1, r);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    void color(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].colors = 1;
            tree[node].hye = X;
            tree[node].increment = 0;
            return;
        }
        push(node,l,r);
        int mid = (l+r)/2;
        color(2*node,l,mid,L,R,X);
        color(2*node+1,mid+1,r,L,R,X);
        push(2*node, l, mid);
        push(2*node+1, mid+1, r);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
public:
    void init(vector<T>& v){
        range = v.size();
        tree.assign(4*range, node());
        build(v, 0, range-1, 1);
    }
    T get(int pos){
        return sum(1,0,range-1,pos,pos);
    }
    void add(int l, int r, int x){
        add(1,0,range-1,l,r,x);
    }
    void color(int l, int r, int x){
        color(1,0,range-1,l,r,x);
    }
    T sum(int l, int r){
        return sum(1,0,range-1,l,r);
    }
    lseg_tree(vector <T> a){
        init(a);
    }
    lseg_tree(){}
    void print(){
        incr(i,0,tree.size()){
            cout << tree[i].sum << " ";
        }
        cout << nl;
    }
};


inline void solve(){
    ll n, m;
    cin >> n >> m;
    vi data;
    seev(data,n);
    lseg_tree <ll> tr(data);
    incr(i,0,m){
        ll t,a,b,x;
        cin >> t;
        if(t==1){
            cin >> a>> b>> x;
            tr.add(a-1,b-1,x);
        } else if(t==2){
            cin >> a>> b>> x;
            tr.color(a-1,b-1,x);
        } else {
            cin >> a>> b;
            cout << tr.sum(a-1,b-1) << nl;
        }
    }
}
int main(){
    IOS;
    // prepare();
    solve();
    return 0;
}