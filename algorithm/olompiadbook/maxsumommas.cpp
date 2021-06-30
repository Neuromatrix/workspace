#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define fca(a,s) for(const auto & a: s)
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

int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
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