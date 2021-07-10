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
    size_t n;
    cin >> n;
    ll a,b,ans=0,maxi=INT_MIN;
    vector <pair<int, int>> base;
    
    incr(i,0,n){
        cin >> a >> b;
        base.push_back({a,1});
        base.push_back({b,-1});
    }
    sort(base.begin(),base.end());
    incr(i,0,base.size()){
        if (base[i].second==1) ans++;
        else if (base[i].second==-1) ans--;
        maxi=max(maxi,ans);
    } 
    cout << maxi << nl;
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