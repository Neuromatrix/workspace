#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
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
int addnulls(int size){
    int first_size=logb(size);
    int diff=size-fast_powtw(first_size);
    if (diff==0) return 0;
    else if (diff>0) return fast_powtw(first_size+1)-size;
}

struct segtree{
    vector <int> segtree;
    ll size;
};

inline segtree makeseg(vector <int> base,int size){
    segtree pool;
    size_t nulls=addnulls(size);
    int cou_nulls=nulls;
    int controll_size= 2*(nulls +  size)-1;
    pool.segtree.resize(controll_size);
    for (int i = controll_size-1;i>=0;i--){
        if (cou_nulls>0) {pool.segtree[i]=0;cou_nulls--;}
        else{
            if (base.size()==0){
                i++;
                pool.segtree[i-1]=pool.segtree[2*(i)-1]+pool.segtree[2*(i)];
                cout << 2*i-1<<" "<<2*i<<endl;
                i--;
            }
            else{
                pool.segtree[i]=base.back();
                base.pop_back();
            }
            
        }
    }
    for ( const auto &a : pool.segtree){
        cout <<a<<" ";
    }


    return pool;
}
inline void solve(){
    int n;
    segtree m;
    cin >> n;
    vector <int> roots;
    roots.resize(n);
    for (int i=0;i< n;i++){
        cin>> roots[i];
    }
    m.segtree= roots;
    m=makeseg(roots,n);
    
    return;
}

int main (){
    prepare();
    solve();
    return 0;
}