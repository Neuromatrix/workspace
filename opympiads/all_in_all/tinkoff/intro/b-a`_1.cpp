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
int abss(int x){
    return x < 0 ? -x : x;
}
ll check_manhatt(ll x1, ll y1, ll x2, ll y2){
    return abss(x1-x2)+abss(y1-y2);
}
inline void idiot_solve(){
    int n, m;
    cin >> n >> m;
    vii points(n);
    ll def_dist = 0;
    incr(i,0,n){
        cin >> points[i].first >> points[i].second;
        def_dist+=abss(points[i].first)+abss(points[i].second);
    }
    int c_x = 0, c_y = 0;
    string comms;
    cin >> comms;
    incr(i,0,m){
        cout << i << "--->" << comms[i] <<  "--===";
        def_dist= 0;
        if(comms[i]=='S'){
            c_y++;
            incr(i,0,n){
                def_dist+=check_manhatt(c_x,c_y,points[i].first,points[i].second);
            }
            cout << def_dist << nl;
        } else if(comms[i]=='J'){
            c_y--;
            incr(i,0,n){
                def_dist+=check_manhatt(c_x,c_y,points[i].first,points[i].second);
            }
            cout << def_dist << nl;
        } else if (comms[i]=='I'){
            c_x++;
            incr(i,0,n){
                def_dist+=check_manhatt(c_x,c_y,points[i].first,points[i].second);
            }
            cout << def_dist << nl;
        } else if (comms[i]=='Z'){
            c_x--;
            incr(i,0,n){
                def_dist+=check_manhatt(c_x,c_y,points[i].first,points[i].second);
            }
            cout << def_dist << nl;
        }
    }
    return;
}
inline void solve(){
    int n, m;
    cin >> n >> m;
    multiset <int> prex;
    multiset <int> prey;
    multimap <int,int> x;
    multimap <int,int> y;
    ll def_dist = 0;
    incr(i,0,n){
        int xx, yy;
        cin >> xx >> yy;
        prex.insert(xx);
        prey.insert(yy);
        def_dist+=abss(xx)+abss(yy);
    }
    int i = 0;
    fca(a,prex){
        x.insert({a,i});
        i++;
    }
    i = 0;
    fca(a,prey){
        y.insert({a,i});
        i++;
    }
    int c_x = 0, c_y = 0;
    string comms;
    cin >> comms;
    incr(i,0,m){
        if(comms[i]=='S'){
            if(y.upper_bound(c_y)==y.end()) def_dist+=n;
            else def_dist+=2*(y.upper_bound(c_y)->second)-n;
            c_y++;
            cout << def_dist << nl;
        } else if(comms[i]=='J'){
            if(y.lower_bound(c_y)==y.end()) def_dist-=n;
            else def_dist-=2*(y.lower_bound(c_y)->second)-n;
            c_y--;
            cout << def_dist << nl;
        } else if (comms[i]=='I'){
            if (x.upper_bound(c_x)==x.end()) def_dist+=n;
            else def_dist+=2*(x.upper_bound(c_x)->second)-n;
            c_x++;
            cout << def_dist << nl;
        } else if (comms[i]=='Z'){
            if (x.lower_bound(c_x)==x.end()) def_dist-=n;
            else def_dist-=2*(x.lower_bound(c_x)->second)-n;
            c_x--;
            cout << def_dist << nl;
        }
    }
    return;
}
int main(){
    IOS;
    //prepare();
    solve();
    //cout << " --------------- " <<nl;
    //idiot_solve();
    return 0;
}