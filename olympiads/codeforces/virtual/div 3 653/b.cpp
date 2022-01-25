#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    ll x;
    cin >> x;
    pair <ll,ll> factors = {0,0};
    while (x % 2 == 0) {
        factors.first++;
        x /= 2;
    }
    while (x % 3 == 0) {
        factors.second++;
        x /= 3;
    }
    if (x==1 && factors.first<=factors.second){
        cout << (factors.second-factors.first) +factors.second<<endl;
        return;
    }
    else{
        cout << -1 <<endl;
        return;
    }

}
int main()
{  
    size_t tests;
    cin >> tests;
    for (int i = 0; i< tests;i++){
         solve();
    }
    return 0;
}