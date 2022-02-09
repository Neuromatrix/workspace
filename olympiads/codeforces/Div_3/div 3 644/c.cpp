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
    size_t size;
    cin >> size;
    vector <int> data(size);
    int cnt_1=0,cnt_2=0;
    bool flag = false;

    for (int i = 0 ;i<size;i++){
        cin >> data[i];
        if (data[i]%2==0){
            cnt_2++;
        }
        else cnt_1++;
    }
    if (cnt_1%2!=cnt_2%2)
        cout << "NO"<<endl;
    else{
        if (cnt_2%2==1){
            for (int i =0;i< size;i ++){
                for (int j =0;j<size;j++){
                    if (abs(data[i]-data[j])==1){
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) cout << "YES" <<endl;
            else cout << "NO" <<endl;
        }
        else
            cout << "YES" <<endl;
    }
    
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