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
template<typename T>
vector<T> constructPrintLIS(vector<T> a, int n)
{
    vector<T> d(n+5,INF);
    d[0] = -INF;
    set <T> in;
    fca(it, a){
        in.insert(it);
    }
    for (int i=0; i<n; i++) {
        int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
        if (d[j-1] < a[i] && a[i] < d[j])   
            d[j] = a[i];
    }
    vector <T> ans;
    for(const auto & it : d){
        if(in.find(it)!=in.end()) ans.push_back(it);
    }
    return ans;
}
inline void solve(){
    int n;
    cin >> n;
    vi a;
    seev(a,n);
    vi pre = constructPrintLIS(a,n);
    cout << pre.size() << nl;
}
int main(){
    IOS;
    // prepare();
    solve();
    return 0;
}