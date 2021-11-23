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
vector <vector <ll>> Floyd_Warshall(vector <vector<int>> &G){
    int n = G.size(); // работает в натуральной нумерации
    vector <vector <ll>> distance(n,vector<ll> (n));
    for (size_t i = 1; i < n; i++){
        for(size_t j = 1; j < n; j++){
            if (i==j) distance[i][j] = 0;// заполняем distance в зависимости от ребер
            else if(!G[i][j]) distance[i][j] = INF;
            else if (G[i][j]) distance[i][j] = G[i][j]; 
        }
        cout << nl;
    }
    for (size_t k = 1; k < n; k++){
        for (size_t i = 1; i < n; i++){
            for(size_t j = 1; j < n; j++){
                if (distance[i][k] < INF && distance[k][j] < INF)
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);// алгоитм флойда
            }
        }
    }
    return distance;
}
inline void solve(){
    /*
        
    */
}
 int main(){
     IOS;
     solve();
     return 0;
 }