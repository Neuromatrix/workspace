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

inline void solve(){
    int n,m;
    cin >> n >> m;
    int forest[n][n];
    vector <vector <int>> pre_f(n,vector<int>(n));
    incr(i,0,n){
        string ff;
        cin >> ff;
        incr(j,0,n){
            if (ff[j]=='.'){
                pre_f[i][j] = 0; 
            } else {
                pre_f[i][j] = 1;
            }
        }
    }
    incr(i,0,n){
        incr(j,0,n){
            forest[i][j] = 0;
        }
    }
    incr(i,0,n){
        incr(j,0,n){
            if (i==0 && j==0){
                forest[0][0] = pre_f[0][0]; 
            }
            else if (j==0 && i!=0){
                forest[i][j] = forest[i-1][j]+pre_f[i][j];
            }
            else if (i==0 && j!=0){
                forest[i][j] = forest[i][j-1]+pre_f[i][j];
            }
            else{
                forest[i][j] = forest[i][j-1] + forest[i-1][j] - forest[i-1][j-1] + pre_f[i][j];
            }
        }
    }
    incr(i,0,m){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        ll ans = forest[x2][y2];
        if (x1-1>=0 && y2>=0) ans-= forest[x1-1][y2];
        if (x2>=0 && y1-1>=0) ans-= forest[x2][y1-1];
        if (x1-1>=0 && y1-1>=0) ans+= forest[x1-1][y1-1];
        cout << ans << nl;
        //cout << forest[x2][y2] - forest[x1-1][y2] - forest[x2][y1-1] + forest[x1-1][y1-1] << nl;
    }
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}