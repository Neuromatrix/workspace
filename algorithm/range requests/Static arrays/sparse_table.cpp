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
template <typename T>
class sparse_table
{
private:
    vector <vector <T>> data;
    size_t size_it = 0;
public:
    void resize(size_t new_size){
        size_t t = __lg(new_size)+1;
        data.resize(t);
        for(size_t i = 0; i < t; i++){
            data[i].assign(new_size,INF);
        }
        size_it = new_size;
    }
    
    void init(vector <T> gh){
        resize(gh.size());
        data[0] = gh;
        for (int l = 0; l < __lg(size_it); l++){
            for (int i = 0; i + (2 << l) <= size_it; i++){
                data[l+1][i] = min(data[l][i], data[l][i + (1 << l)]);
            }
        }
    }
    T mins(size_t l, size_t r){ // [l,r)
        int t = __lg(r - l);
        return min(data[t][l], data[t][r - (1 << t)]);
    }
    void print(){
        for (int i = 0; i < data.size();i++){
            for (int j = 0; j < data[i].size();j++){
                if(data[i][j]==INF) cout << "-" <<" ";
                else cout << data[i][j] << " ";
            }
            cout << nl;
        }
    }
    sparse_table(size_t new_size){
        resize(new_size);
    }
    sparse_table(vector <T> gh){
        resize(gh.size());
        init(gh);
    }
    sparse_table(size_t new_size, vector <T> gh){
        resize(new_size);
        init(gh);
    }

};



inline void solve(){
    /*
        ...
    */
    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}