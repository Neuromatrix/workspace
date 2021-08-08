// https://cses.fi/problemset/task/1084
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

    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
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
int abs_(int a) {return a <= 0 ? -a : a;}

inline void solve(){
    size_t n, m , k;
    cin >> n >> m >> k;
    vector <int> apart(n);
    vector <int> guests(m);
    incr(i, 0, n){
        cin >> apart[i];
    }
    incr(i, 0 , m) cin >> guests[i];
    sort(apart.begin(),apart.end());
    sort(guests.begin(),guests.end());
    //fca(a , guests) cout << a << " "; cout << nl;
    //fca(u, apart) cout << u << " "; cout << nl;
    ll x = 0,y = 0,i = 0,j = 0,ans = 0;
    while (i < n && j < m){
        if (abs_(apart[i]-guests[j])<=k){ //Found a suitable apartment for the applicant
			++i; ++j; //Move to the next one.
			++ans;
		}   
		else{
			if (apart[i]>guests[j]){
				//If the desired apartment size of the applicant is too big
				//Move the "apartment" pointer to the right to find a bigger one
				++j;
			}
			else{
				//If the desired apartment size is too small
				//Skip that applicant and move to the next person
				++i;
			}
		}
        //cout << i << " " << j <<nl;
    }
    cout << ans << nl;  
    return;
}

int main(){
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}