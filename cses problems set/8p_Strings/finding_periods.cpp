// https://cses.fi/problemset/task/1733
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
class Z_array
{
    private:
        size_t size_it;
        string inp;
        vector <int> z_array;
    public:
        Z_array(string s){
            init(s);
        }
        Z_array();
        size_t size(){
            return size_it;
        }
        void init(string s){
            inp = s;
            size_it = s.length();
            int n = (int) s.length();
            z_array.resize(n);
            for (int i=1, l=0, r=0; i<n; ++i) {
                if (i <= r)
                    z_array[i] = min (r-i+1, z_array[i-l]);
                while (i+z_array[i] < n && s[z_array[i]] == s[i+z_array[i]])
                    ++z_array[i];
                if (i+z_array[i]-1 > r)
                    l = i,  r = i+z_array[i]-1;
            }
            return;
        }
        int operator[](size_t ind){
            return z_array[ind];
        }
        void print(){
            for(size_t i = 0; i < size_it; i++) {
                cout << z_array[i] << " "; 
            }
            cout << endl;
        }
        void print(string sep){
            for(size_t i = 0; i < size_it; i++) {
                cout << z_array[i] << sep; 
            }
            cout << endl;
        }
};



inline void solve(){
    string a;
    cin >> a;
    Z_array gh(a);
    set <int> ans;
    incr(i,0,a.sz){
        if (i+gh[i]==a.sz) ans.insert(a.sz-gh[i]);
    }
    ans.insert(a.sz);
    fca(a,ans) cout << a << " ";
    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}