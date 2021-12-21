#include <bits\stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
inline T pow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template <int target>
class stonesX2
{
private:
    vector <vector <int>> dp;
    int func_1(int x){
        return x<<1;
    }
    int func_2(int x){
        x+1;
    }
    int func_3(int x){
        0; // на всякий случай
    }
public:
    void init(){
        dp.resize(target);
        for(size_t i = 0; i < target; i++){
            dp[i].resize(target);
            for (size_t j = 0; i < target; j++){
                dp[i][j] = 0;
            }
        }
        simulation();
    }
    void simulation(vector <int> starters = {0,0}){
        // в i храниться сумма в первой куче на данный момент
        // в j хранится сумма в второй куче на данный момент
        for(size_t i = target-1; i >= 0; i++){
            for (size_t j = target-1; j >=0 ; j++){
                if(i+j >=target) dp[i][j] = 0; // обозначеает что сумма в кучах првосходит целевую
                else{
                    if(max({func_1(i)+j, func_2(i)+j,i+func_1(j),i+func_2(j)}) >= target) {
                        dp[i][j] = 1;
                    }// сумма двух куч, которую
                        // мы можем получить за этот ход большей целевой
                    else {
                        vector <int> possible_cases_sum = {
                            dp[func_1(i)][j],
                            dp[func_2(i)][j],
                            dp[i][func_1(j)],
                            dp[i][func_2(j)]//,
                            // dp[func_3(i)][j],
                            // dp[i][func_3(j)]
                        }; // все возможные случаи применения действий
                        sort(possible_cases_sum.begin(),possible_cases_sum.end());
                        int maximum = possible_cases_sum.back();// максимум
                        int minimum = possible_cases_sum.front();// минимум
                        int maximum_negative = 0;// максимальный отрцательный
                        for(const auto &it: possible_cases_sum){
                            if(it > 0) maximum_negative = it;
                            else break;
                        }
                        //! пусть сейчас ходит первый, тогда после его хода он станет вторым, а второй первым
                        if(minimum < 0) dp[i][j] = -maximum_negative+1; // если хотя бы когда то выигрывает второй,
                        // то мы можем стать вторым(первый меняется местами со вторым) и поедить
                        else dp[i][j] = -maximum; // всегда побеждает первый, а так как мы станем вторым, 
                        //то мы можем только достойно проиграть
                    }
                }
            }
        }

    }
    int operator()(int x, int y){
        return dp[x][y];
    }
    stonesX2(){
        init();
    }
};
//вот это код короткий
int h1(int x) {return x*2;}
int h2(int x) {return x+1;}
int nmx(int a,int b, int c, int d){
    vector<int> tmp = {a<0 ? -a : 1000,b<0 ? -b : 1000,c<0 ? -c : 1000,d<0 ? -d : 1000};
	return -*min_element(tmp.begin(),tmp.end());
}
inline void solve(){
    int n,f=13;
    cin >> n;
    vector <vector <int>> dp(n,vector <int>(n,0));
    int i, j;
    for(i = n-1; i >-1;i--)
        for(j = n-1; j>-1;j--){
            if(i+j>=n) {dp[i][j] = 0; continue;}
            if(max({h1(i)+j, h2(i)+j,i+h1(j),i+h2(j)}) >= n) {dp[i][j] = 1; continue;}
            int mx = max({dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]});
            int mn = min({dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]});
            int nm = nmx(dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]);
            mn<0 ? dp[i][j] =  -nm+1 : dp[i][j] = -mx;
        }
    for (int i =0; i < n; i++){
		cout<<i<<' '<<dp[f][i]<<endl;
	}
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}