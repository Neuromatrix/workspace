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
    size_t n,find_sum;
    cin >> n >> find_sum;
    vector <pair <int, int>> base(n);
    incr(i, 0 ,n) {cin >> base[i].first; base[i].second=i;}
    sortest(base,all);
    ll front=0,back=n-1;
    while(front <=n-1 && back >=0){
        if (find_sum==(base[front].first+base[back].first)) break;
        if (find_sum < (base[front].first + base[back].first)) back--;
        else if (find_sum > (base[front].first + base[back].first)) front ++;
        
    }
    if ((base[front].first+base[back].first)==find_sum && front!=back) cout << base[front].second+1 << " " << base[back].second+1<<nl;
    else cout << "IMPOSSIBLE" <<nl;
    return;
}

int main(){
    #ifdef _DEBUG
        freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
        freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);

    #endif
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}
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