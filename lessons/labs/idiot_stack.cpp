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
class idiot_stack
{
    friend void push(int it,idiot_stack &);
    friend void pop(idiot_stack &);
    friend bool empty(idiot_stack &);
    friend bool full(idiot_stack &);
private:
    stack <int> data;
    int sizz = 0;
    int maxx;
public:
    idiot_stack(int maxx = INF){sizz = 0;this->maxx = maxx;}
    ~idiot_stack(){
        while(!data.empty()) data.pop();
    }
};
void push(int it, idiot_stack &x){
    x.data.push(it);
    return;
}
void pop(idiot_stack &x){
    if(!x.data.empty()) x.data.pop();
    return;
}

bool empty(idiot_stack &x){
    if(x.data.empty()) return true;
    else return false;
}
bool full(idiot_stack &x){
    if(x.data.size()>x.maxx) return true;
    else return false;
}
inline void solve(){
    idiot_stack a;
    push(1,a);
    /*
        .....
    */
   return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}