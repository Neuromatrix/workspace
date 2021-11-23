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
inline vector <tuple <int, int, int>> list_of_ribs(){//сканирование в список ребер
    vector <tuple <int, int, int>> graph;
    int n, to_h, W;
    cin >> n;cin.ignore();// размер графа
    n++;
    for(size_t i = 1; i < n; i++){
        while(cin.peek()!='\n'){ 
            cin >> to_h  >> W; // сначала вершина потом веса
            graph.push_back(make_tuple(i,to_h,W)); // записываем в кортеж
        }
        cin.ignore();
    }
    return graph;
}
vector <ll> Bellman_Ford(vector <tuple <int, int, int>> &edges, int start, int gsize){
    start--;// 0_N нумерация
    int a, b, w;
    int ex;
    vector <ll> distance(gsize);// колво вершин
    for (size_t i = 0; i < distance.size(); i++){
        distance[i] = INF;// заполняем бесконечностями
    }
    distance[start] = 0;
    for (size_t i = 0; i < distance.size()-1; i++){ //асимптотика O(nm), на каждой итерации перебираем все ребра
        ex = 0;
        for(const auto & e : edges){
            tie(a, b, w) = e;
            a--;// 0_N нумерация
            b--;
            if (distance[a] < INF)
                distance[b] = min(distance[b],distance[a]+w);
        }
    }
    return distance;
}


inline void solve(){
    /*
        .....
    */
   return;
}

int main(){
    IOS;
    solve();
    return 0;
}