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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';

#define fca(iterator,object) for (const auto & iterator: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define all(obj) obj.begin(),obj.end()
#define F first
#define S second

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int abs_(int a) {return a <= 0 ? -a : a;}
inline void solve(){
    size_t max_sum = 0, n, counter = 0;
    cin >> n;
    vector <int> data(n);
    set <int> melodic;
    incr(i,0,n) cin >>data[i];
    incr(i,0,n){
        //cout <<"----" <<  data[i] << "--------"  << nl;
        
        if (melodic.find(data[i])==melodic.end()){
            melodic.insert(data[i]);
        }
        else{
            max_sum = max(max_sum, melodic.size());
            int x = i-melodic.size();
            //cout << x << " +++++++" <<nl;
            incr(j,x,i){
                if (data[j]==data[i]){
                    melodic.erase(data[j]);
                    break;
                }
                else{
                    melodic.erase(data[j]);
                }
            }
            melodic.insert(data[i]);
        }
        //fca(a, melodic) cout << a  << " "; cout << nl;
    }
    cout << max(max_sum,melodic.size()) << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (size_t i = 0; i < tests; i++)
        solve();
    return 0;
}