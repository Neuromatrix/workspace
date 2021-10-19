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
void rem_lead_nulls(deque <int> &data){
    while (data.front()==0){
        data.pop_front();
        if(data.empty()) break;
    }
    
}
inline void solve(){
    deque <int> data;
    int n;
    cin >> n;
    incr(i,0,n){
        char c;
        cin >> c;
        data.push_back(c-'0');
    }
    while (data.back()%2==0){
        data.pop_back();
        if(data.empty()) break;
    }
    if(data.size()==0){ cout << -1 << nl; return;}
    ll ans = accumulate(all(data),0);
    if (ans%2==0){
        rem_lead_nulls(data);
        fca(it,data){
            cout << it;
        }
        cout << nl;
    } else {
        bool flag = true;
        incr(i,0,data.size()-1){
            if(data[i]%2==1){
                data.erase(data.begin()+i);
                flag = false;
                break;
            }
        }
        if(flag) { cout << -1 << nl; return;}
        if(data.size()==0){ cout << -1 << nl; return;}
        rem_lead_nulls(data);
        fca(it,data){
            cout << it;
        }
        cout << nl;
    }
    
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}