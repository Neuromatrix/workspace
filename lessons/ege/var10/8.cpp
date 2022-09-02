#include <bits\stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
inline void __with__permutation(){
    string s = "uley";
    sort(s.begin(), s.end());
    set<string> cnt;
    do
    {
        if(s[0]!='y' and s.find("eu")==string::npos) cnt.insert(s); // if 
    } while (next_permutation(s.begin(), s.end()));
    cout <<cnt.size()<<nl;
}
inline void __withany__combinate(){
    string s = "abcdef";
    sort(s.begin(), s.end());
    vector <string> cnt;
    for (const auto & e1 : s) {
        for (const auto & e2 : s) {
            for (const auto & e3 : s) {
                for (const auto & e4 : s) {
                    for (const auto & e5 : s) {
                        string tmp = "";
                        tmp+=e1; tmp+=e2; tmp+=e3;tmp+=e4; tmp+=e5;
                        
                        cnt.push_back(tmp); 
                        
                    }
                }
            }
        }
    }
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); i++){
        if(i&1){
            string tmp = cnt[i];
            if (tmp.find("aa")==string::npos and tmp.find("bb")==string::npos 
            and tmp.find("cc")==string::npos and tmp.find("dd")==string::npos and tmp.find("ee")==string::npos
            and tmp.find("ff")==string::npos) cout << 1 << endl;
        }
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    prepare();
    size_t tt = 1;
    // cin >> tt;
    __withany__combinate();
    return 0;
}