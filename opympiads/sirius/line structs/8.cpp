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
    stack< pair<int,int> > s1, s2;
    int n;
    cin >> n;
    incr(i,0,n){
        int x;
        cin >> x;
        if(x!=0){
            int minima = s1.empty() ? x : min(x, s1.top().second);
            s1.push (make_pair (x, minima));
        } else{
            int current_minimum;
            if(s1.empty() && s2.empty()) {cout << -1 << nl; continue;}
            if (s1.empty() || s2.empty())
	            current_minimum = s1.empty() ? s2.top().second : s1.top().second;
            else
	            current_minimum = min (s1.top().second, s2.top().second);
            cout << current_minimum << endl;
            if (s2.empty())
                while (!s1.empty()) {
                    int element = s1.top().first;
                    s1.pop();
                    int minima = s2.empty() ? element : min (element, s2.top().second);
                    s2.push (make_pair (element, minima));
                }
            int result = s2.top().first;
            s2.pop();
        }
    }
}
int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}