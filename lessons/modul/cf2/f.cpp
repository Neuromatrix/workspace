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
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
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
    freopen("substrcmp.in", "r", stdin);
    freopen("substrcmp.out", "w", stdout);
}
// inline void prepare(){
//     freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
//     freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
// }
class hashstring
{
    private:
        string data;
        size_t len;
        const ll p =  31; //911382323
        const ull mod = 18446744073709551557;// ближайшее прстое число к LLMAX;
        vector <ll> p_pow;
        vector <ll> h;
    public:
        void init(string pull){//инициализируем префикс-хэши от строки
            data = pull;
            len = pull.size();
            p_pow.resize(len);
            h.resize(len);
            p_pow[0] = 1;
            for (size_t i = 1; i < len; i++){
                p_pow[i] = (p_pow[i-1]*p)%mod;// запоимнаем в массив степеней
            }
            for (size_t i = 0; i < len; i++){
                h[i] = ((data[i]- 'a' + 1) * p_pow[i])%mod;  //высчитываем хэш
                if (i) h[i] += h[i-1];
            }
        }
        bool compare(size_t i1,size_t j1, size_t i2, size_t j2){//сравнение двух подстрок
            size_t lent = j1-i1;// вычисление длины подстроки 
            ll h1 = h[i1+lent-1];
            if (i1)  h1 -= h[i1-1];// вычисление первого хэша
            ll h2 = h[i2+lent-1];
            if (i2)  h2 -= h[i2-1];// второго
            if (i1 < i2 && h1 * p_pow[i2-i1] == h2 || i1 > i2 && h1 == h2 * p_pow[i1-i2]) return true; //сравнение
            else return false;
        }
        ll allhash(){
            return *(--h.end());// хэш от всей строки
        }
        ll prefix_hash(size_t i, size_t len){
           ll cur_h = h[i+len-1];// хэш от префикса
           if (i)  cur_h -= h[i-1];
           return cur_h;
        }
        void printhashs(){
            for(const auto & aa: h) cout << aa <<" "; cout <<nl;// все хэши
            return;
        }
        ll poww(size_t i){// стпень в позиции
            return p_pow[i];
        }
};
inline void solve(){
    string data;
    cin >> data;
    hashstring hsh;
    hsh.init(data);
    int k;
    cin >> k;
    while(k--){
        int a, b, c ,d ;
        cin >> a >> b >> c >> d;
        if(a==c && b==d){
            cout << "Yes" <<nl;
        }
        else if(c-a!=d-b){
            cout << "No" << nl;
        }
        else if(hsh.compare(a-1,b,c-1,d)){
            cout << "Yes" <<nl;
        } else {
            cout << "No" << nl;
        }
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