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

class hashstring
{
    private:
        string data;
        size_t len;
        const ull p = 31;
        const ull c_p = 911382323;
        const ull mod = 972663749;
        vector <ull> p_pow;
        vector <ull> check_p_pow;
        vector <ull> h;
        vector <ull> check_h;
    public:
        void init(string pull){
            data = pull;
            len = pull.size();
            p_pow.resize(len);
            h.resize(len);
            check_p_pow.resize(len);
            check_h.resize(len);
            p_pow[0] = 1;
            check_p_pow[0] = 1;
            for (size_t i = 1; i < len; i++){
                check_p_pow[i] = (check_p_pow[i-1]*p);
                p_pow[i] = (p_pow[i-1]*p)%mod;

            }
            for (size_t i = 0; i < len; i++){
                h[i] = ((data[i]- 'a' + 1) * p_pow[i])%mod; 
                if (i) h[i] += h[i-1];
                check_h[i] = ((data[i]- 'a' + 1) * check_p_pow[i]); 
                if (i) check_h[i] += check_h[i-1];
            }
        }
        bool compare(size_t i1,size_t j1, size_t i2, size_t j2){
            size_t lent = j1-i1;
            ull h1 = h[i1+lent-1];
            if (i1)  h1 -= h[i1-1];
            ull h2 = h[i2+lent-1];
            if (i2)  h2 -= h[i2-1];
            // check
            ull ch1 = check_h[i1+lent-1];
            if (i1)  ch1 -= check_h[i1-1];
            ull ch2 = check_h[i2+lent-1];
            if (i2)  ch2 -= check_h[i2-1];
            if ((i1 < i2 && h1 * p_pow[i2-i1] == h2 || i1 > i2 && h1 == h2 * p_pow[i1-i2]) && 
            (i1 < i2 && ch1 * check_p_pow[i2-i1] == ch2 || i1 > i2 && ch1 == ch2 * check_p_pow[i1-i2])) return true;
            else return false;
        }
};

int main(){
    return 0;
}