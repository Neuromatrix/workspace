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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

class hashstring
{
    private:
        string data;
        size_t len;
        const ll p = 31; // 911382323
        const ll mod = 972663749;
        vector <ll> p_pow;
        vector <ll> h;
    public:
        void init(string pull){
            data = pull;
            len = pull.size();
            p_pow.resize(len);
            h.resize(len);
            p_pow[0] = 1;
            for (size_t i = 1; i < len; i++){
                p_pow[i] = (p_pow[i-1]*p)%mod;
            }
            for (size_t i = 0; i < len; i++){
                h[i] = ((data[i]- 'a' + 1) * p_pow[i])%mod; 
                if (i) h[i] += h[i-1];
            }
        }
        bool compare(size_t i1,size_t j1, size_t i2, size_t j2){
            size_t lent = j1-i1;
            ll h1 = h[i1+lent-1];
            if (i1)  h1 -= h[i1-1];
            ll h2 = h[i2+lent-1];
            if (i2)  h2 -= h[i2-1];
            if (i1 < i2 && h1 * p_pow[i2-i1] == h2 || i1 > i2 && h1 == h2 * p_pow[i1-i2]) return true;
            else return false;
        }
};

inline void solve(){
    hashstring aps;
    aps.init("abcdabc");
    cout << aps.compare(1,2,5,6);
    return;
}

int main (){
    prepare();
    solve();
    return 0;
}