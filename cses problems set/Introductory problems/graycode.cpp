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
string to_binary(size_t val,int n)
{

  string ret;
  ret.resize(n);
  while( n-- )
  {
    ret[n] = '0'+(val&1);
    val >>= 1;
  }
  return ret;
}
inline string gray(string rep){
    string ans;
    ans.push_back(rep[0]);
    incr(i,1,rep.size()){
        char diff = (abs_(rep[i-1]-rep[i]))+'0';
        ans.push_back(diff);
    }
    return ans;
}
inline void solve(){
    int n;
    cin >> n;
    for (size_t i = 0;i < (2 << n-1);i++){
        cout << gray(to_binary(i,n))<<nl;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    for (int i = 0; i < tests; i++)
        solve();
    return 0;
}