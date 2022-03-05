#include <bits\stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <C:\Users\grivi\vscodes\.vscode\bitmap_image.hpp>
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
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second << endl;return out;}
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
bool cmp( const pair<int,int> &a, const pair <int,int> &b)  {
    if(a.first==b.first) return rand()%2;
    return a.first>b.first;
}
class knn
{
private:
    int k;// chosen
    vector <pair<bitset<16384>,int>> points;
    int xorr(bitset<16384> a, bitset<16384> b){
        bitset<16384> h = a^b;
        return h.size()-h.count();
    }
    int len(bitset<16384> a, bitset<16384> b){
        int ssum = 0;
        for(size_t i = 0; i < 16384; i++){
            ssum+=pw(a[i]-b[i]);
        }
        return sqrt(ssum);
    }
    ld cos(bitset<16384> a, bitset<16384> b){
        int ssum = 0;
        for(size_t i = 0; i < 16384; i++){
            ssum+=(a[i]*b[i]);
        }
        int len1 = 0, len2 = 0;
        for(size_t i = 0; i < 16384; i++){
            len1+=a[i]*a[i];
            len2+=b[i]*b[i];
        }

        return ssum/sqrt(len1*len2);
    }
public:
    void add_from_path(string path){
        bitmap_image image(path);
        const unsigned int height = image.height();
        const unsigned int width  = image.width();
        bitset <16384> d;
        int ans = (*prev(path.end(),5)-'0');

        for (std::size_t y = 0; y < height; ++y)
        {
            for (std::size_t x = 0; x < width; ++x)
            {
                rgb_t colour;
                image.get_pixel(x, y, colour);
                if(colour.blue>250 and colour.red>250 and colour.red>250){
                    d[width*y+x] = 1; // __WHITE__
                } else {
                    d[width*y+x] = 0; // __BLACK__
                }
            }
        }
        add(d,ans);
    }

    knn(){
        srand(time(NULL));
        k = 10;
    }
    void add(bitset<16384> image, int ans){
        points.push_back(make_pair(image,ans));
    }
    int check_numb(string pp){
         bitmap_image image(pp);
        const unsigned int height = image.height();
        const unsigned int width  = image.width();
        bitset <16384> d;
        int ans = (*prev(pp.end(),5)-'0');

        for (std::size_t y = 0; y < height; ++y)
        {
            for (std::size_t x = 0; x < width; ++x)
            {
                rgb_t colour;
                image.get_pixel(x, y, colour);
                if(colour.blue>250 and colour.red>250 and colour.red>250){
                    d[width*y+x] = 1; // __WHITE__
                } else {
                    d[width*y+x] = 0; // __BLACK__
                }
            }
        }
        return check_numb(d);
    }
    int check_numb(bitset<16384> ff){
        vector <pair<ld,int>> ans;
        for(size_t i = 0; i < points.size(); i++){
            bitset<16384> cur = points[i].first;
            
            ans.push_back({cos(cur,ff),points[i].second});
        }
        // cnt & number
        sort(ans.rbegin(),ans.rend());
        map <ld,int> gh;
        for(size_t j = 0; j < k; j++){
            gh[ans[j].second]++;
        }
        ld mx = -1, id = 0;
        cout << ans << nl;
        fca(it,gh){
            if(it.second>mx){
                id = it.first;
                mx = it.second;
            }
        }
        return id;
    }
};


inline void solve(){
    knn nn;
    string fp = "C:\\Users\\grivi\\vscodes\\workspace\\lessons\\labs\\Numbers\\";
    incr(i,0,7){
        incr(k,0,10){
            string fold;
            fold.push_back(i+'0');
            fold+="\\";
            fold.push_back(k+'0');
            fold+=".bmp";
            nn.add_from_path(fp+fold);
        }
    }
    cout << nn.check_numb("C:\\Users\\grivi\\vscodes\\workspace\\lessons\\labs\\Numbers\\3\\2.bmp");

}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}