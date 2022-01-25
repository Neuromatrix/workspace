#include <bits\stdc++.h>
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

inline void solve(){
    string numb;
    cin >> numb;
    reverse(all(numb));
    int case1 = INF,case2 = INF,case3 = INF, case4 = INF;// 0 0  // 5 2 // 0 5 // 5 7 //
    incr(i,0,numb.sz){
        if (numb[i]=='0'){
            incr(j,i+1,numb.sz){
                if(numb[j]=='0'){
                    case1=j-1;
                    i = numb.sz;
                    break;
                }
            }
        }
    }
    incr(i,0,numb.sz){
        if (numb[i]=='5'){
            incr(j,i+1,numb.sz){
                if(numb[j]=='7'){
                    case2=j-1;
                    i = numb.sz;
                    break;
                }
            }
        }
    }
    incr(i,0,numb.sz){
        if (numb[i]=='5'){
            incr(j,i+1,numb.sz){
                if(numb[j]=='2'){
                    case3=j-1;
                    i = numb.sz;
                    break;
                }
            }
        }
    }
    incr(i,0,numb.sz){
        if (numb[i]=='0'){
            incr(j,i+1,numb.sz){
                if(numb[j]=='5'){
                    case4=j-1;
                    i = numb.sz;
                    break;
                }
            }
        }
    }
    cout << min({case1,case2,case3,case4}) << nl;
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}