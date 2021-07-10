#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
#define fca(a,s) for(const auto & a: s)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)

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


inline int iteral_coins_solve(int sum,vector<int> coins,vector <int> val){
    val[0]=0;
    incr(i,1,sum+1){
        val[i]=INT_MAX;
        fca(c,coins){
            if (i-c>=0)
                val[i]=min(val[i],val[i-c]+1);
        }
    }
    return *(--val.end()); 
}
inline vector <int> build_answer_coins_solve(int sum,vector<int> coins,vector <int> val){
    vector <int> first_coin(sum+1);
    val[0]=0;
    incr(i,1,sum+1){
        val[i]=INT_MAX;
        fca(c,coins){
            if (i-c>=0 && val[i-c]+1<val[i]){
                val[i]=val[i-c]+1;
                first_coin[i]=c;
            }
        }
    }
    return first_coin;
}
inline void solve(){
    size_t coins_size;
    int sum;
    cin >> sum >> coins_size;
	vector <int> coins(coins_size),val;

    val.resize(sum+1);
    incr(i,0,coins_size)
        cin >> coins[i];

    vector <int> x= build_answer_coins_solve(sum,coins,val);
    while(sum > 0){
        cout << x[sum] <<endl;
        sum-=x[sum];
    }
    cout << iteral_coins_solve(sum,coins,val)<<"\n";
    return;
}



int main()
{
    prepare();
    size_t tests;
    cin >> tests;
    for (int i = 0; i< 1;i++){
        solve();
    }
    return 0;
}