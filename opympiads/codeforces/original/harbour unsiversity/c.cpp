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

inline void solve(){
    string penal;
    cin >> penal;
    int n = penal.length();
    int first_com = 0, second_com = 0;
    pair <vc <bool>, vc<bool>> goals;
    incr(i,0,n){
        if (i%2==0){
            if (penal[i]=='?'){
                goals.first.pb(1);
            }
            else {
                if(penal[i]=='1') goals.first.pb(1);
                else goals.first.pb(0);
            }
        }
        if (i%2==1){
            if (penal[i]=='?')
                goals.second.pb(0);
            else {
                if(penal[i]=='1') goals.second.pb(1);
                else goals.second.pb(0);
            }
        }
    }
    int r1_goals = 0;
    int counter = 0, ans1 = 10;
    incr(i,0,5){
        r1_goals+=goals.first[i];
        counter++;
        if (r1_goals > 5-i){
            //cout << "r1 " << r1_goals << "--->" << counter<<nl;
            ans1 = counter;
            counter = 0;
            break;
        }
        r1_goals-=goals.second[i];
        counter++;
        if (r1_goals > 5-i){
            //cout << "r1 " << r1_goals << "--->" << counter<<nl;
            ans1 = counter;
            counter = 0;
            break;
        }
    }
    goals.first.clear();
    goals.second.clear();
    incr(i,0,n){
        if (i%2==0){
            if (penal[i]=='?'){
                goals.first.pb(0);
            }
            else {
                if(penal[i]=='1') goals.first.pb(1);
                else goals.first.pb(0);
            }
        }
        if (i%2==1){
            if (penal[i]=='?')
                goals.second.pb(1);
            else {
                if(penal[i]=='1') goals.second.pb(1);
                else goals.second.pb(0);
            }
        }
    }
    int r2_goals = 0;
    counter = 0;int  ans2 = 10;
    incr(i,0,5){
        r2_goals-=goals.first[i];
        counter++;
        if (r2_goals > 4-i){
            //cout << "r2 " << r2_goals << "--->" << counter <<nl;
            ans2 = counter;
            counter = 0;
            break;
        }
        r2_goals+=goals.second[i];
        counter++;
        if (r2_goals > 4-i){
            //cout << "r2 " << r2_goals << "--->" << counter <<nl;
            ans2 = counter;
            counter = 0;
            break;
        }
    }
    cout << min(ans1,ans2) << nl;
    
    
}

int main(){
    IOS;
    //prepare();
    size_t tt;
    cin >> tt;
    incr(i, 0 , tt){
        solve();
    }
    
    return 0;
}