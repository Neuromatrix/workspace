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
    int n, k;
    cin >> n >> k;
    vector <int> factor;
    int max_del=INT_MAX;
    for (int i =1;i*i <=n;i++){
        if (!(n%i)){
            if (i <= k) {
                    max_del = min(max_del, n / i);
            }

            if (n / i <= k) {
                max_del= min(max_del, i);
            }
        }
    }
    cout <<max_del<<endl;
    return;
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