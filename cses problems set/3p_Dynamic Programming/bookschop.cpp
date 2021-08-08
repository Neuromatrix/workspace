// https://cses.fi/problemset/task/1158 
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
int binPow(int a, int pow){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a;
	} else {
		int part = binPow(a, pow >> 1);
		if (pow & 1) {
			return (((part * part)) * a);
		} else {
			return (part * part);
		}
	}
}
int fast_powtw(int k) { return 2 << (k - 1);}


inline void solve(){
   size_t n_books, max_price;
   cin >> n_books >> max_price;
   n_books++;
   max_price++;
   vector <int> books_pages(n_books);
   vector <int> books_prices(n_books);
   incr(i,1,n_books) cin >> books_prices[i];
   incr(i,1,n_books) cin >> books_pages[i];
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
   
   //incr(i,0,n_books){ incr(j,0,max_price) cout << dp[i][j] << " ";cout <<nl;} 
   cout << dp[n_books-1][max_price-1]<<nl;

}

int main(){
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}