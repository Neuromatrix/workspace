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
    double n,sum=0;
	cin >> n;
	vector <int> pool(n);
	for (int i =0 ;i< n;i++){
		cin >> pool[i];
		sum+=pool[i];
	}
	ld middle= sum/n;

	if (middle==1) {cout << 0<<endl; return;}
	else if (middle>1) {cout << sum - n<<endl; return;}
	else if (middle<0) cout << 1;
	else cout << 1;
	cout <<endl;
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