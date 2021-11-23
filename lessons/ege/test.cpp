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
class prefix_sum
{
private:
    vector <T> pre_sum;
    size_t size_it;
public:
    void init(vector <T> pool){
        size_it = pool.size();
        pre_sum.resize(size_it);
        pre_sum[0] = pool[0];
        for (size_t i = 1; i < size_it; i++){
            pre_sum[i] = pre_sum[i-1] + pool[i];
        }
    }
    T sum(ssize_t l, ssize_t r){
        assert(!(l < 0  || r < 0 || l > size_it || r > size_it));
        if (min(l,r) > 0) return pre_sum[max(l,r)]-pre_sum[min(l,r)-1];
        else return pre_sum[max(l,r)];
    }
    size_t size(){
        return size_it;
    }
    prefix_sum(vector <T> pool){
        init(pool);
    }
    prefix_sum(){
        size_it = 0;
    }
};
inline void solve(){
    int n; cin >> n;
    prefix_sum <ll> prefix;
    vc <ll> data;
    seev(data,n);
    prefix.init(data);
    vector <ll> index;
    incr(i,0,n){
        if (data[i]%43) index.pb(i);
    }
    ll sum = -LLONG_MAX;
    ll min_dist = 1000000000000; 
    fca(a,index){
        fca(b,index){
            if (a==b) continue;
            if(prefix.sum(a+1,b-1)%43==0){
                sum = max(sum,prefix.sum(a+1,b-1));
            }
        }
    }
    cout << sum << nl;
    fca(a,index){
        fca(b,index){
            if (a==b) continue;
            if (sum==prefix.sum(a+1,b-1)) min_dist = min(max(a,b)-min(a,b)-1,min_dist);
        }
    }
    
    cout << min_dist << nl;
}
int main(){
    IOS;
    prepare();
    solve();
    return 0;
}