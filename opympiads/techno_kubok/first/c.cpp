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
int n, m;
vc<vi> possible;
bool valid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    if (possible[i][j]==1) return true;
    return true;
}
template <typename T>
class prefix_sum
{
private:
    vector <T> pre_sum;
    size_t size_it;
public:
    void init(vector <T> pool){
        size_it = pool.size();
        pre_sum.resize(size_it);
        pre_sum[0] = pool[0];
        for (size_t i = 1; i < size_it; i++){
            pre_sum[i] = pre_sum[i-1] + pool[i];
        }
    }
    T sum(ssize_t l, ssize_t r){
        assert(!(l < 0  || r < 0 || l > size_it || r > size_it));
        if (min(l,r) > 0) return pre_sum[max(l,r)]-pre_sum[min(l,r)-1];
        else return pre_sum[max(l,r)];
    }
    size_t size(){
        return size_it;
    }
    prefix_sum(vector <T> pool){
        init(pool);
    }
    prefix_sum(){
        size_it = 0;
    }
};


inline void solve(){
    int n, m;
    cin >> n>> m;
    vc <string> inp(n);
    possible.resize(n);
    incr(i,0,n){
        possible[i].assign(m,-INF);
        cin >> inp[i];
    }
    
    incr(i,0,n){
        incr(j,0,m){
            if(inp[i][j]=='X') possible[i][j] = 0;
            if(inp[i][j]=='.' && (i==0 || j==0)) possible[i][j] = 1;
        }
    }
    
    incr(i,1,n){
        incr(j,1,m){
            if(possible[i-1][j]==1 || possible[i][j-1]==1 && possible[i][j]!=0) possible[i][j] = 1;
        }
    }
    vc <ll> sums;
    
    incr(i,0,m){
        ll sum = 0;
        incr(j,0,n){
            sum += possible[j][i] ;
        }
        sums.push_back(sum);
    }
    prefix_sum <ll> prtf(sums);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a>> b;
        a--; b--;
        if(prtf.sum(a,b)>=0) cout << "YES" << endl;
        else if(a==b) cout << "YES" << endl; 
        else cout << "NO" << endl;
    }
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}