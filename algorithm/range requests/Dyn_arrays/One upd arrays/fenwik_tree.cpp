// #include <bits\stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (int i=a; i<b; ++i)
#define decr(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template <class T>
class fenwik_tree
{
	private:
		vector <T> data;
	public:
		void init(size_t n){
			data.assign(n,0);
		}
		void init(vector <T> pool){
			init(pool.size());
			for (int i = 0; i < pool.size(); i++){
				inc(i,pool[i]);
			}
		}
		void inc(size_t i, T new_el){
			for(;i < data.size(); i = i | (i+1)){
				data[i]+=new_el;
			}
		}
		void print(){
			for (const auto & it : data) cout << it << " "; cout << '\n';
		}
		ll sum(int r){
			ll res = 0;
			for (;r >= 0; r = (r&(r + 1))-1){
				res+=data[r];
			}
			return res;
		}
		ll sum(size_t l, size_t r){
			return sum(r) - sum(l - 1);
		}			
};



inline void solve(){
	vector <int> pool = {1,2,3,4,5,6};
	fenwik_tree <int> fen_tr;
	fen_tr.init(pool);
	cout << fen_tr.sum(1,3);
	cout << fen_tr.sum(2,5);
	fen_tr.inc(5,7);

}

int main(){
    solve();
    return 0;
}


