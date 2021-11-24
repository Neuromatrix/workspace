#include <bits\stdc++.h>
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
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
    int n;
    cin >> n;
    vii data(n);
    vi ans(n);
    incr(i,0,n){
        cin >> data[i].first;
        data[i].second = i;
    }
    deque<pii> mnoj;
    sort(all(data));
    incr(i,0,n){
        int count = 0;
        int j = i;
        while (data[i].first==data[j].first){
            count++;
            if(j+1>=n) break;
            j++;

        }
        if(count==1){
            mnoj.push_back(data[i]);
            continue;
        }
        else{
            if(count%2==0){
                int x = 1;
                while (i<=j){
                    ans[data[i].second] = x;
                    x*=-1;
                    i++;
                } 
            } else {
                int x = 1;
                while (i<j){
                    ans[data[i].second] = x;
                    x*=-1;
                    i++;
                } 
                mnoj.push_back(data[j]);
                i++;
            }
        } 
    }
    if(mnoj.size()%2==0){
        incr(i,0,n){
            if(data[n-i-1].first*data[i].first>0){
                ans[data[i].second] = -data[n-i-1].first;
                ans[data[n-i-1].second] = data[i].first;
            } else {
                ans[data[i].second] = data[n-i-1].first;
                ans[data[n-i-1].second] = data[i].first;
            }
        }
    } else {
        int med = mnoj.size()/2;
        incr(i,0,med-1){
            if(data[n-i-1].first*data[i].first>0){
                ans[data[i].second] = -data[n-i-1].first;
                ans[data[n-i-1].second] = data[i].first;
            } else {
                ans[data[i].second] = data[n-i-1].first;
                ans[data[n-i-1].second] = data[i].first;
            }
        }
        int a = med-1;
        int b = med;
        int c = med+1;
        ans[mnoj[a].second] = mnoj[c].first;
        ans[mnoj[b].second] = mnoj[c].first;
        int mult = -(mnoj[b].first*+mnoj[a].first);
        ans[mnoj[c].second] = mult;
    }
    fca(it,ans){
        cout << it << " ";
    }
    cout << endl;

}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}