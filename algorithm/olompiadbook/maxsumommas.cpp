#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define fca(a,s) for(const auto & a: s)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define tint <int>; 
#define tll <ll>;
#define tld <ld>;
#define tchar <char>;
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
	set <int> pool;
	vector <int> data(n);
	for (int i = 1;i<=n;i++){

		pool.insert(i);}
	for (const auto & a : pool) cout << a << " "; cout <<endl;
	for (int i = 0;i<n;i++){
		cin >> data[i];
		if (data[i]!=0)
			pool.erase(data[i]);
	}
	for (const auto & a : pool) cout << a << " "; cout <<endl;
	for (int i = n-1;i>=0;i--){
		if (data[i]!=0)
			continue;
		else {
			if (*pool.begin()==i+1){
				data[i]=*next(pool.begin());
				pool.erase(data[i]);
			} 
			else {
				data[i]=*pool.begin();
				pool.erase(data[i]);
			}
		}
		
	}
	for (const auto & a : data) cout << a << " "; cout <<endl;
	return;
}
inline void test(){
	vector <int> utt = {1,2,3,4,5,6};
	fca(r,utt) cout <<r << " ";cout <<"\n"; 
}

int main()
{
    prepare();
    size_t tests;
    
    for (int i = 0; i< 1;i++){
        test();
    }
    return 0;
}