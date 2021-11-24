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
#define vll vector<ll>
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
    int n, k;
    cin >> n >> k;
    vi data,save;
    set<int> used;
    priority_queue <pii> colors;//f - numb, s - color//f - numb, s - color
    incr(i,0,k){
        colors.push({0,i});
    }
    seev(data,n);
    save = data;
    sort(all(data));
    int counter = 1;
    incr(i, 0, n){
        int j = i;
        while(data[j]==data[j+1] && j+1<n){
            counter++;
            j++;
        }
        for (int i = 0; i < counter;i++){
            pii tmp = colors.top();
            colors.pop();
            colors.push({tmp.F-1,tmp.S});
        }
        i = j;
        counter = 1;
    }  
    vi ans;
    cout << -colors.top().F << " " <<k+1 <<nl;
    ans.assign(n,0);
    int j = 0;
    size_t it = 0;
    incr(i,1,k+1){
        while(j < -colors.top().F && it<n){
            if (used.find(save[it])==used.end()){
                if (ans[it]==0) {
                    ans[it] = i; 
                    j++;
                }
                used.insert(save[it]);
                fca(a, ans) cout << a << " ";
            }
            it++;
        }
        j = 0;
        it = 0;
        used.clear();
    }
    fca(a, ans) cout << a << " ";
    cout <<nl<< "--------------" <<nl;
    return;
}

int main(){
    IOS;
    prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}