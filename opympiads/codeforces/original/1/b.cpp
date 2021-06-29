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
    ll n,m;
	pair <ll,ll> coord;
	set <pair <ll,ll>> jj;
	pair <ll, ll> x;
	cin >> n >> m >> coord.first>> coord.second;
	coord.first--;coord.second--;
	vector <ll> setka;
	pair <ll,ll> first_pair,pair1,pair2,pair3,pair4;
	pair1.first=0;pair1.second=0;
	pair2.first=0;pair2.second=m;
	pair3.first=n;pair3.second=m;
	pair4.first=n;pair4.second=0;
	x.first=abs(pair1.first-coord.first)+abs(pair1.second-coord.second);
	x.second=1;
	jj.insert(x);
	x.first=abs(pair2.first-coord.first)+abs(pair2.second-coord.second);
	x.second=2;
	jj.insert(x);
	x.first=abs(pair3.first-coord.first)+abs(pair3.second-coord.second);
	x.second=3;
	jj.insert(x);
	x.first=abs(pair4.first-coord.first)+abs(pair4.second-coord.second);
	x.second=4;
	jj.insert(x);
	
	int y=(*next(next(next(jj.begin())))).second;
	if (y==1){
		cout << pair1.first<< " " << pair1.second<<" "<< pair3.first<< " "<<pair3.second<<endl;
	}
	else if (y==2){
		cout << pair2.first<< " " << pair2.second<<" "<< pair4.first<< " "<<pair4.second<<endl;
	}
	else if (y==3){
		cout << pair3.first<< " "<<pair3.second<<" "<<pair1.first<< " " << pair1.second<<endl;
	}
	else if (y==4){
		cout << pair4.first<< " "<<pair4.second<<" " << pair2.first<< " " << pair2.second<<endl;
	}
	
}

int main(){
    size_t tests;
    cin >> tests;
    for (int i = 0; i< tests;i++){
         solve();
    }
    return 0;
}