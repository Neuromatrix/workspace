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
constexpr ll MOD = 1000000007;
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
#define rall(x) x.rbegin(),x.rend()
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
    size_t n_books, max_price = 0, minus;
    cin >> n_books;
    n_books++;
    max_price++;
    vector <int> books_pages(n_books);
    vector <int> books_prices(n_books);
    ll al = 0;
    incr(i,1,n_books){
        int a, b, c;
        cin >> a >> b >> c;
        books_pages[i] = a;
        al+=b*(c/100.0);
        books_prices[i] = b*(c/100.0);
    }
    cin >> minus;
    max_price= al-minus;
    vector <vector <int>> dp(n_books,vector <int>(max_price));
    incr(i,0,max_price) dp[0][i]=0;
    incr(i,0,n_books) dp[i][0]=0;
    incr(i,1,n_books){
        incr(j,1,max_price){
            if (j < books_prices[i]){
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-books_prices[i]]+books_pages[i]);
            }
        }
    }
    set <int> ann;
    int k = max_price-1;
    decr(i,n_books-1,0){
        if(dp[i][k]!=dp[i-1][k]){
            ann.insert(i);
            k-=books_prices[i];
        }
    }
    incr(i,1,n_books){
        if(ann.find(i)==ann.end()) cout<< i << nl;
    }
   //incr(i,0,n_books){ incr(j,0,max_price) cout << dp[i][j] << " ";cout <<nl;} 

}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}