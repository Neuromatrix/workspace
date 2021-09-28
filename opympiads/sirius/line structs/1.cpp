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
constexpr ll LINF = LLONG_MAX-1;
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

inline void solve(){
    string comm;
    queue <int> a;
    while (cin >> comm)
    {
        if(comm=="exit"){
            cout << "bye" << nl;
            break;
        } else if(comm == "size"){
            cout << a.sz << nl;
        } else if (comm == "clear"){
            while (!a.empty()){
                a.pop();
            }
            cout << "ok" << nl;
        } else if (comm == "push"){
            int n;
            cin >> n;
            a.push(n);
            cout << "ok" << nl;
        } else if (comm == "front"){
            if(a.empty()) cout << "error" << nl;
            else cout << a.front() << nl;
        } else if (comm == "pop"){
            if(a.empty()) cout << "error" << nl;
            else {cout << a.front() << nl;a.pop();}
        }
        
    }
    
}
int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}