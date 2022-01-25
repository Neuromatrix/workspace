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

inline void solve()
{
    size_t n,k;
    ll num,mod;
    cin >> n >> k;
    vector <ll> data;
    set <ll> x_num;
    map <ll,ll> pro;
    for (int i =0 ;i < n;i++){
        cin >> num;
        mod=k-num%k;
        if(num%k==0) continue;
        if (pro[mod]==0){
            pro[mod]++;
            x_num.insert(mod);
        }
        else{
            x_num.insert(k*pro[mod]+mod);
            pro[mod]++;
        }
        
    }
    if (x_num.size()==0) cout << "0" <<endl;
    else{
    cout << *(--x_num.end())+1<<endl;}
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