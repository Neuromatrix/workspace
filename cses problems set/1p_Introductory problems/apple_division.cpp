// https://cses.fi/problemset/task/1623
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
vector <ll> subset_2;
vector <ll> subset;
vector <ll> subset_ind;
vector <ll> base;
ll mins = INT_MAX;
ll abs_(ll a) {return a <= 0 ? -a : a;}
inline void search(int k){
    if (k==base.size()){
        ll diff = 0;
        incr(i,0,base.size()){
            if(find(all(subset_ind),i)!=subset_ind.end()){
                diff+=base[i];
            } else {
                diff-=base[i];
            }
        }
        mins=min(mins,abs_(diff));
        //mins=min(mins,abs_(accumulate(all(subset_2),0)-accumulate(all(subset),0)));
       // cout << mins<<nl;
        return;
    } else {
        subset_ind.push_back(k);
        search(k+1);
        subset_ind.pop_back();
        search(k+1);
    }
}
inline void solve(){
    size_t n;
    cin >> n;
    base.resize(n);
    incr(i,0,n) cin >> base[i];
    search(0);
    cout << mins << nl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}