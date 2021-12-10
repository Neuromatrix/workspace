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
vector <complex <double>> fft(vector <complex <double>> polinom, int d = 1){
    double pi = acos(-1);
    int n = polinom.size();
    vector <complex <double>> r(n);
    for(size_t i = 0; i < n; i++){
        int b = 0;
        for(size_t j = 1; j < n; j <<= 1){
            b <<= 1;
            if (i & j) b++;
        }
        r[b] = polinom[i];
    }
    for(size_t m = 2; m <=n; m <<=1){
        complex <double> wm = exp(complex <double> {0,d*2*pi/m});
        for (size_t k = 0; k < n; k+=m){
            complex <double> w = 1;
            for(size_t j = 0; j < m/2; j++){
                complex <double> u = r[k+j];
                complex <double> t = w*r[k + j + m/2];
                r[k+j] = u+t;
                r[k + j + m/2] = u - t;
                w = w*wm;
            }
        }
    }
    if (d==-1) for(size_t i = 0; i < n; i++) r[i] /= n;
    return r;
}
inline void solve(){
    vector <complex <double>> f = {5,1,3,4,2,1,2,0}; //! NEED POW of 2
    vector <complex <double>> g = {2,3,1,0,0,0,0,0};
    int n = f.size();
    for (size_t i = 0; i < n; i++){
        g.push_back(0);
        f.push_back(0);
    }
    n = f.size();
    auto tf = fft(f);
    auto tg = fft(g);
    
    vector <complex <double>> tp(n);
    incr(i,0,n) {tp[i] = tf[i]*tg[i];}
    fca(gg, fft(tp,-1)) cout << gg.real() << " ---- " <<gg.imag() <<nl;
    return;
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}