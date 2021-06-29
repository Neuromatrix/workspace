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

using namespace std;

ll n;
vector <ll> a; 
vector <ll> tree;  


void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];    
    } else {
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int get_sum(int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    if (tr < l || r < tl) {
        return 0;
    }
    int tm = (tl + tr) / 2;
    return get_sum(l, r, v * 2,     tl,     tm)
         + get_sum(l, r, v * 2 + 1, tm + 1, tr);
}


inline void solve(ll pool[],ll n){
    ll l,r;
    cin >> l >> r;
    l--;
    r--;
    ll result=0;
    result= get_sum(l,r,1,0,n-1);
    cout << result<<endl;
} 

int main()
{   
    ll tests;
    string pool;
    cin >> n >> tests;
    cin >> pool;
    a.resize(n);
    ll mas[n];
    for (int i =0 ;i<n;i++){
        a[i]=pool[i]-96;
    }

    tree.resize(4*n+4);
    build_tree(1,0,n-1);
    for (int i = 0; i< tests;i++){
         solve(mas,n);
    }
    return 0;
}
int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}

