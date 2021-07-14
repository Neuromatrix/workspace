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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)

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