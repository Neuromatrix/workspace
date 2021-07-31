#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    string data, pool;
    cin >> data;
    size_t len=data.sz, pos_a;
    pool = data;
    sort(all(data));
    incr(i,0,len){
        if (i==0){
            if (data[i]!='a'){
                cout << "NO" <<nl;
                return;
            }
        }
        else{
            if (data[i] != data[i-1] + 1){
                cout << "NO" <<nl;
                return;
            }
        }
    }
    incr(i,0,len) {
        if (pool[i] == 'a'){
            pos_a = i;
            break;
        }   
    }
    int lpos = pos_a;
    int rpos = pos_a;
    char letter = 'a';
    incr(i,1,len){
        size_t n_pos = pool.find(letter+1);
        if (n_pos == string::npos || (n_pos != lpos - 1 && n_pos != rpos + 1)){
            cout << "NO" << nl;
            return;
        }
        if (n_pos == lpos-1) {
            lpos--;
            letter++;
        }
        else if (n_pos == rpos+1){
            rpos++;
            letter++;
        }
        else{
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" <<nl;
    return;
}

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}