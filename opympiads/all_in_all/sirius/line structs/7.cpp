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
inline void print(queue <int> a){
    while(!a.empty()){
        cout << a.front() << " ";
        a.pop();
    }
    cout << endl;
}
inline void solve(){
    queue <int> ff, ss;
    incr(i,0,5){
        int x;
        cin >> x;
        ff.push(x);
    }
    incr(i,0,5){
        int x;
        cin >> x;
        ss.push(x);
    }
    incr(i,1,1e6){
        int f1, s1;
        f1 = ff.front();
        s1 = ss.front();
        ff.pop();
        ss.pop();
        if(f1<s1){
            if(f1 == 0 && s1 == 9){
                ss.push(f1);
                ss.push(s1);
            } else {
                ff.push(f1);
                ff.push(s1);
            }
        } else {
            if(f1 == 9 && s1 == 0){
                ff.push(f1);
                ff.push(s1);
            } else {
                ss.push(f1);
                ss.push(s1);
            }
        }
        if(ff.empty()){
            cout << "first " << i << nl;
            return;
        }
        if(ss.empty()){
            cout << "second " << i << nl;
            return;
        }
    }
    cout << "botva" << nl;
}
int main(){
    IOS;
    //prepare();
    solve();
    return 0;
}