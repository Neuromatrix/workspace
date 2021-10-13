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
int n, m;
// inline int check1(int x, int y,vc <string> & data, char t){
//     if(x<0 || x>=n || y<0 || y>=m)
//     return check(x+1,y,data,'M')+check(x-1,y,data,'M')+check(x,y-1,data,'M')+check(x+1,y,data,'M')
// }
inline ll check (int x, int y, vc <string> & data)
{
    ll count = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == j || i == -j) continue;
            if (x+i < 0 || x+i >= n || y+j < 0 || y+j >= m) continue;
            if (data[x+i][y+j] == 'C')
            {
                for (int p = -1; p < 2; p++)
                {
                    for (int q = -1; q < 2; q++)
                    {
                        if (p == q || p == -q) continue;
                        if (x+i+p < 0 || x+i+p >= n || y+j+q < 0 || y+j+q >= m) continue;
                        if (data[x+i+p][y+j+q] == 'M') count++;
                    }
                }
            }
        }
    }
    return count;
}
inline void solve(){
    cin >> n >> m;
    vc <string> data(n);
    ll ans = 0;
    incr(i,0,n){
        cin>> data[i];
    }
    incr(i,0,n){
        incr(j,0,m){
            if(data[i][j]=='A') ans+=check(i,j,data);
        }
    }
    cout << ans << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}