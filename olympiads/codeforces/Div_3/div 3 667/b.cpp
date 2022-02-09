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
	ll a, b, x, y, n;
	cin >> a >> b >> x >> y>> n;
	ll result1,result2;
	ll a1=a,b1=b,n1=n;
	if (a-n<x){
		result1=x*(max(y,b-(n-a+x)));
	}
	else{
		result1=(a-n)*b;
	}
	if (b-n<y){
		result2=y*(max(x,a-(n-b+y)));
	}
	else{
		result2=(b-n)*a;
	}
	cout << min(result2,result1)<<endl;
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