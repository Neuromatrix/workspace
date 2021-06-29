#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\structs\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\structs\\output.txt", "w", stdout);
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

int stringToInt(string a){
	int max_pow = a.size() - 1;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += (a[i] - '0') * (binPow(10, max_pow));
		max_pow--;
	}
	return res;
}

int BinToInt(vector <bool> a){
	int max_pow = 0;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += a[i] * binPow(2, max_pow);
		max_pow++;
	}
	return res;
}
int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}

inline int maps(map <string, string> pool){
    int ans=0;
    map < string, vector <string>> base;
    for (const auto & a: pool){
        base[a.second].push_back(a.first);
    }
    for (const auto & a: base){
        if (a.second.size()>1) ans ++ ;
    }
    cout<< ans;
    return ans;
}

ll ans=0;
void f(int n){
    if (n<=2) return;
    ll i = n-1, j=n/2;
    ans+=2;
    f(i);
    f(j);
    return ;
}
int main (){
    prepare();
    f(1000);
    cout << ans;

    return 0;
}