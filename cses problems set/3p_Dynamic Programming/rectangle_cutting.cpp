// https://cses.fi/problemset/task/1744
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
int cuts = 0;

inline void solve(){
    int a, b;
    cin >> a >> b; a++; b++;
    vector <vector <int>> dp(a,vector<int> (b));
    incr(i,1,a){
        incr(j,1,b){
            if (i==j){
                dp[i][j] = 0;
            } else if (i == 1){
                dp[i][j] = j - 1;
            } else if (j == 1){ 
                dp[i][j] = i - 1;
            } else {
                dp[i][j] = INF;
            }
        }
    }
    incr(i,1,a){
        incr(j,1,b){
            if(dp[i][j]==INF){
                incr(k,1,i-1){
                    dp[i][j] = min(dp[k][j]+dp[i-k][j]+1,dp[i][j]);
                }
                incr(k,1,j-1){
                    dp[i][j] = min(dp[i][k]+dp[i][j-k]+1,dp[i][j]);
                }
            }
        }
    }
    cout << dp[a-1][b-1] << nl;
    return;
}

int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}