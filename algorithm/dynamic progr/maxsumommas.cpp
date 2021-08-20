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
   // #define _DEBUG
#ifdef _DEBUG
    #include <C:\\Users\\grivi\\vscodes\\.vscode\\helper.h>
#endif
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';

#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define sortest(obj,all) sort(obj.begin(),obj.end())

inline void solve(){
	size_t n;
	cin >> n;
	vector <int> base(n);
	incr(i,0,n)
		cin >> base[i];
	int best=0,sum=0,index_r,index_l;
	incr(i,0,n){
		if (sum+base[i]<base[i]){
			index_l=i;
		}
		sum=max(sum+base[i],base[i]);
		if (best <= sum){
			index_r=i;
		}
		best=max(best,sum);
	}
	cout << best <<" " <<index_l << " " <<index_r;
	return;
}


int main()
{
    prepare();
    size_t tests;
    cin >> tests;
    for (int i = 0; i< 1;i++){
        solve();
    }
    return 0;
}