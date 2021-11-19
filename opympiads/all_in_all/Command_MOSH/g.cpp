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

struct stats
{
    ll a = 0, b = 0, c = 0, d = 0;
};

inline void solve(){
    ll n1, n2;
    vc<pair<int,string>> ts;
    map<string, stats> pl;
    map<string, int> plts;
    string tmp;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> tmp;
        ts.push_back({0,tmp});
        plts[tmp] = 0;
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> tmp;
        ts.push_back({1,tmp});
        plts[tmp] = 1;
    }
    sort(ts.begin(), ts.end());
    ll n, r, l, t, prevt;
    string type, name, prevn, prevtp;
    cin >> n;
    prevt = -1;
    for (int i = 0; i <= n; i++)
    {
        cin >> type;
        if (type == "BALL")
        {
            cin >> tmp;
            prevn = name;
            prevt = t;
            name = "";
            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j] == '(')
                {
                    t = tmp[j+1]-'0';
                    break;
                }
                name.push_back(tmp[j]);
            }
            if (t != prevt && prevt != -1 && prevtp == "BALL") pl[name].c++;
            if (prevtp != "BALL" && !r) pl[name].d++;
        }
        else if (type == "FOUL")
        {
            cin >> tmp;
            cin >> tmp;
            prevn = name;
            prevt = t;
            name = "";
            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j] == '(')
                {
                    t = tmp[j+1]-'0';
                    break;
                }
                name.push_back(tmp[j]);
            }
        }
        else if (type == "FREE")
        {
            cin >> r;
            pl[name].a += r;
        }
        else if (type == "RING")
        {
            cin >> l >> r;
            pl[name].a += (l > 675 ? 3 : 2)*r;
            if (plts[prevn] == plts[name] && r) pl[prevn].b++;
        }
        prevtp = type;
    }

    for (int i = 0; i < n1+n2; i++)
    {
        t = ts[i].first;
        name = ts[i].second;
        cout << t << " " << name << " " << pl[name].a << " " << pl[name].b << " " << pl[name].c << " " << pl[name].d << nl;
    }
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}