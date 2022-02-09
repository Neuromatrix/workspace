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
    size_t size;
    string sco;
    cin >> size;
    cin >> sco;
    int counter=0;
    stack <char> ep;
    for( int i=0;i< sco.size();i++){
        if (sco[i]=='('){
            ep.push('(');
        }
        else{
            if (ep.size()==0)
                counter++;
            else ep.pop();
        }
    }
    cout << (counter+ep.size())/2<<endl;
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