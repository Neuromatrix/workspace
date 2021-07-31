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
inline pair <int, int> search_borders(vector <int> data, long long f_x){
    bool flag = false;
    vector <long long>  prefix_sum(data.size()); prefix_sum[0] = data[0];
    for(int i = 1; i < data.size(); i++){
        prefix_sum[i] = prefix_sum[i-1] + data[i];
    }
    long long l = 0, r = data.size()-1, cur_sum = 0;
    while(l<=data.size() && r>=0){
        if (l == 0 || r==0){
            cur_sum = prefix_sum[max(l,r)];
        } else {
            cur_sum = prefix_sum[max(r,l)] - prefix_sum[min(l-1,r-1)];
        }
        if (cur_sum ==  f_x) {flag = true;break;}
        else if (cur_sum > f_x){
            while(cur_sum > f_x && r>=0){
                r--;
                if (l == 0 || r==0){
                    cur_sum = prefix_sum[max(l,r)];
                } else {
                    cur_sum = prefix_sum[max(r,l)] - prefix_sum[min(l-1,r-1)];
                }
            }
        }
        if (cur_sum ==  f_x) {flag = true;break;}
        l++;
    }
    if (flag) return {min(l,r), max(l,r)};
    else return {-1,-1};
}
inline void solve(){
    /*
        ...
    */
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    solve();
    return 0;
}