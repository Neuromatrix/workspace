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
    int n,k;
	cin >> n >> k;
	string pool,mikni;
	cin >> pool;
	vector <string> u;
	set <string> ans;
	string exper;
	while (n--)
	{
		for (int i =0 ;i<pool.size();i++){
			mikni.push_back(pool[i]);
		}
		u.push_back(mikni);
		mikni.resize(0);
		pool.pop_back();
	}

	for (int i = 0;i<u.size();i++){
		exper=u[i];
		while(true){
			if (exper.size()==k){
				ans.insert(exper);
				exper.resize(0);
				break;
			}
			else if (exper.size()>k){
				int pp = exper.size();
				for (int i =0 ;i < pp-k; i++){
					exper.pop_back();
				}
			}
			else exper=exper+exper;
		}
	}
	cout << *ans.begin();return;
}

int main(){
    size_t tests;
    tests=1;
    for (int i = 0; i< tests;i++){
         solve();
    }
    return 0;
}