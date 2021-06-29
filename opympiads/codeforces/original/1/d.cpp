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
	int n,numbers;
	bool flag=false;
    cin >> n;
	
	list <int> base;

	for (int i =0; i< n;i++){
		cin >> numbers;
		base.push_back(numbers);
	}
	auto it=base.begin();
	while (base.size()!=0)
	{
		while(it != base.end()){
			if (*base.begin()!=*it){
				base.erase(it);
				base.pop_front();
				flag=true;
				break;
			}
			else flag=false;
			++it;
		}
		it=base.begin();
		if (flag==false) break;
		
	}
	cout << base.size()<<endl;
	
	
}

int main(){
    size_t tests;
    cin >> tests;
    for (int i = 0; i< tests;i++){
         solve();
    }
    return 0;
}