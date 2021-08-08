// https://cses.fi/problemset/task/1624
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
ll counter=0;
vector <vector <int>> possible(8, vector <int> (8));
vector <bool> col= {0,0,0,0,0,0,0,0};
vector <bool> diag1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
vector <bool> diag2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
inline void search(int y){
    if ( y == 8){
        counter++;
        return;
    } else {
        incr(i,0,8){
            if (col[i] || diag1[i+y] || diag2[i-y+8-1] || !possible[y][i]) {continue;}
            col[i] =  diag1[i+y] = diag2[i-y+8-1] = true;
            search(y+1);
            col[i] =  diag1[i+y] = diag2[i-y+8-1] = false;
        
        }
    }
}
inline void solve(){
    string inp;
    incr(i,0,8){
        cin >> inp;
        incr(j,0,8){
            if (inp[j]=='.') possible[i][j]=true;
            else possible[i][j] = false;
        }
    }
    search(0);
    cout << counter << nl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}