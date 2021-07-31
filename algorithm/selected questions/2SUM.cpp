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
inline pair <int, int> search_index_two_sum(vector <int> data, long long find_sum){
    size_t n = data.size();
    vector <pair <int, int>> base(n);
    for(int i = 0; i < n; i++){
        base[i].first = data[i]; 
        base[i].second=i;
    }
    ll front=0,back=n-1;
    while(front <=n-1 && back >=0){
        if (find_sum==(base[front].first+base[back].first)) break;// сумма найдена

        if (find_sum < (base[front].first + base[back].first)) back--;//сумма больше найденной
        else if (find_sum > (base[front].first + base[back].first)) front ++;// сумма меньше найденной
        
    }
    if ((base[front].first+base[back].first)==find_sum && front!=back) return { base[front].second+1, base[back].second+1};
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