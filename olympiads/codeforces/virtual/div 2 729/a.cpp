#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
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
    vector <int> numbers(2*n);
    int chet=0,nechet=0;
    incr (i,0,2*n) cin >> numbers[i];
    fca(a,numbers){
        if(a%2==1) nechet++;
        else chet++;
    }
    if (chet==nechet) cout << "YES"<<nl;
    else cout << "NO" <<nl;
    return;
}



int main()
{
    //prepare();
    size_t tests;
    cin >> tests;
    for (int i = 0; i < tests;i++){
        solve();
    }
    return 0;
}