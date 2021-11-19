#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
ll abs_(ll x){
    return x < 0 ? -x : x;
}
#define white 1
#define black 0
inline void solve(){
    ll x, y, endx, endy;
    cin >> x >> y >> endx >> endy;
    if(x==endx && y==endy){
        cout << 0 << nl;
        return;
    }
    bool colorstart,colorend;
    if((x+y)%2==0){
        colorstart = white;
    } else colorstart =  black;
    if((endx+endy)%2==0){
        colorend = white;
    } else colorend =  black;
    if(colorstart==black && colorend==white){
        cout << -1 << nl;
        return;
    } else if (colorstart==white && colorend==white){
        if(endx==x && endy==y){
            cout << 0 << nl;
            return;
        } else {
            cout << -1 << nl;
            return;
        }
    } else if (colorstart==black && colorend==black){
        if(((x+ y) % 2 == (endx + endy)%2)){
            if((x+y==endx+endy) || (x-y==endx-endy)) {cout << 1 << nl << endx << " " << endy << nl; return;}
            else{
                cout <<  2 << nl;
                ll x2 = max(endx,x);
                ll x1 = min(endx,x);
                ll y1 = min(endy,y);
                ll y2 = max(endy,y);
                y2 = y2-(x2-x1);
                ll ans_y = (y1+y2)/2;
                ll ans_x = x1-(y2-ans_y);
                cout << ans_x << " " << ans_y << nl;
                cout << endx << " " << endy << nl;
                return; 
            }
        }
    } else {
        if((abs_(x-endx)==1 && abs_(y-endy)==2) || (abs_(x-endx)==2 && abs_(y-endy)==1)){
            cout << 1 << nl;
            cout << endx << " " << endy << nl;
            return;
        } else {
            vi mins;
            x++;y+=2;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }else{
                mins.pb(0);
            }
            x--;y-=2;
            //! 1
            x+=2,y++;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x-=2,y--;
            //! 2
            x+=2,y--;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x-=2;y++;
            //! 3
            x++;y-=2;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x--;y+=2;
            //! 4       
            x--,y-=2;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x++,y+=2;
            //! 5
            x-=2,y--;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x+=2,y++;
            //! 6
            x-=2,y++;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x+=2,y--;
            //! 7 
            x--, y+=2;
            if(((x + y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) mins.push_back(1);
                else{
                    mins.pb(2);
                }
            }
            x++, y-=2;
            //! 8
            ll mm = *min_element(all(mins));
            if(mm==mins[0]){
                x++;y+=2;
            } else if (mm==mins[1]){
                x+=2,y++;
            } else if (mm==mins[2]){
                x+=2,y--;
            } else if (mm==mins[3]){
                x++;y-=2;
            } else if (mm==mins[4]){
                x--,y-=2;
            } else if (mm==mins[5]){
                x-=2,y--;
            } else if (mm==mins[6]){
                x-=2,y++;
            } else if (mm==mins[7]){
                x--, y+=2;
            }
            cout << mm + 1 << nl;
            cout << x  << " " << y << nl;
            if(((x+ y) % 2 == (endx + endy)%2)){
                if((x+y==endx+endy) || (x-y==endx-endy)) {cout << endx << " " << endy << nl; return;}
                else{
                    ll x2 = max(endx,x);
                    ll x1 = min(endx,x);
                    ll y1 = min(endy,y);
                    ll y2 = max(endy,y);
                    y2 = y2-(x2-x1);
                    ll ans_y = (y1+y2)/2;
                    ll ans_x = x1-(y2-ans_y);
                    cout << ans_x << " " << ans_y << nl;
                    cout << endx << " " << endy << nl;
                    return;
                }
        }
        }
    }
    
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}