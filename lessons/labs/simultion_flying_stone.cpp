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
inline T bpow(T a, T poww,long long mod = LLONG_MAX){
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
struct Stage{
    
   
        const ld pi = acos(-1);
        ld to_rad(double angle){ return (pi*angle)/180.0;}
        ld ax = 0, ay = 0,  vx = 0, vy = 0, x = 0, y = 0,  t, ang,density,m; 
        double xtarget,ytarget,SZ;
        double C,S, g;
    private:
        inline void step(vector <Stage> &data, ld time,const float &delta){
            if(data.size()>1000) return;
            Stage back = data.back();
            if (abs(back.x-xtarget)<=SZ and abs(back.y-ytarget)<=SZ and false){
                //?__END_SIMULATION//
                return;
            } else if(/*back.x>xtarget+SZ || back.y<=0 || back.y<ytarget-SZ*/ false){
                //?__END_SIMULATION//
                //! FAIL
                return;
            } else {
                Stage new_stage(back.x, back.y,
                back.vx, back.vy,
                back.xtarget, back.ytarget,
                delta, back.m, back.density, 
                back.C, back.S, back.g);
                data.push_back(new_stage);
                step(data,time+delta,delta);
            }
        }
    public:
        vector <Stage> start(const float &delta){
            vector <Stage> data;
            data.push_back(*this);
            step(data,0,delta);
            return data;
        }
        Stage(double x1,double y1,double Vx1,double Vy1, 
            double xtarget, double ytarget,
           double delta_t, const double m, 
           const double density, 
           const double C, const double S, ld angle,
           const double g=9.81){ 
               //TODO: __FULL_ACC//
            ax = (-density * Vx1 * abs(Vx1) * C * S)/(2 * m);
            ay = (-density * Vy1 * abs(Vy1) * C * S)/(2 * m) - g;
            vx = Vx1 + ax*delta_t;
            vy = Vy1 + ay*delta_t;
            x = x1 + Vx1 * delta_t + (ax * delta_t * delta_t)/2;
            y = y1 + Vy1 * delta_t + (ay * delta_t * delta_t)/2;
            this->C = C;
            this->g = g;
            this->m = m;
            this->S = S;
            this->xtarget = xtarget;
            this->ytarget = ytarget;
            this->ang = to_rad(angle);
        }
};
inline void solve(){
    float m = 1;
    float density = 1.2;
    float C = 0.4;
    float S = 0.1;
    double g = 9.81;
    float dt = 0.001;
    double tx = 500;
    double ty = 100;
    double V0 = 100;
    Stage x = Stage(
        Stage(0, 0, V0 * cos(3.14*45/180), 
        V0 * sin(3.14*45/180), tx, ty, 
        dt, m, density, 
        C, S, 45)
    );
    vector <Stage> h = x.start(dt);
    incr(i,0,1001){
        cout << h[i].vy << nl;
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