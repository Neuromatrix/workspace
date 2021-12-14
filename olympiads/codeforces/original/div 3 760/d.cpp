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
T pow(T a, T poww,long long mod = LLONG_MAX){
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
class seg_tree // на стрингах не работает
{
    private:
        vector <ll> data; //дерево оотрезков в виде массива
        vector <ll> inp; //исхлдный массив
        int arr_size; // размер первого уровня листьев
        ll es;
        bool initial = false;
        int nulls_res(int i){ // вычисление дополнительных нулей до степени двойки
            int pow = ceil(log2(i));
            return 2<<(pow-1);
        }
        ll _min_(ll a,ll  b){
            return min(a,b);
        }
        ll _max_(ll a,ll  b){
            return max(a,b);
        }
        ll _gcd_(ll a, ll b){
           if (b==0) return a;
           return _gcd_(b,a%b); 
        }
        ll _lcm_ (ll a, ll b){
            return (a/_gcd_(a,b))*b;
        }
        ll _sum_(ll a, ll b){
            return a + b;
        }
        ll _xor_(ll a, ll b){
            return a^b;
        }
        ll _or_(ll a, ll b){
            return a|b;
        }
        ll _and_(ll a, ll b){
            return a&b;
        }
    public:
        string type = "sum"; // какого типа будет дерево
        seg_tree(size_t i){// конструктор размера дерева
            data.resize(2*nulls_res(i));
        }
        seg_tree(){//изначальный конструктор
            data.resize(0);
        }
        seg_tree(size_t i,string new_type){// конструктор размера дерева
            data.resize(2*nulls_res(i));
            type = new_type;
        }
        seg_tree(string new_type){// конструктор размера дерева
            type = new_type;
        }
        void t_sum(){
            type = "sum";
            if (initial){
                init(inp);
            }
        }
        void t_gcd(){
            type = "gcd";
            if (initial){
                init(inp);
            }
        }
        void t_lcm(){
            type = "lcm";
            if (initial){
                init(inp);
            }
        }
        void t_min(){
            type = "min";
            if (initial){
                init(inp);
            }
        }
        void t_max(){
            type = "max";
            if (initial){
                init(inp);
            }
        }
        void t_or(){
            type = "or";
            if (initial){
                init(inp);
            }
        }
        void t_and(){
            type = "and";
            if (initial){
                init(inp);
            }
        }
        void t_xor(){
            type = "xor";
            if (initial){
                init(inp);
            }
        }
        int size(){//размер дерева
            return data.size();
        }
        void init(vector <ll> gh){// инициализация дерева через вектор (численных типов)
            inp = gh;
            initial = true;
            int additional_nulls=nulls_res(gh.size())-gh.size();// дополнительные нули
            arr_size = nulls_res(gh.size()); //изменение размера листьев
            data.resize(2*arr_size);// изменение размера дерева
            int i = data.size()-1;// итератор
            if (type=="lcm"){
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 1;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _lcm_(data[2*i], data[2*i+1]);
                }
            }
            else if (type=="gcd"){
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 0;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _gcd_(data[2*i], data[2*i+1]);
                }
            }
            else if (type == "min"){
                es = LLONG_MAX;
                while(additional_nulls--){ // завполняем нулями
                    data[i] = es;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _min_(data[2*i], data[2*i+1]);
                }
            }
            else if (type == "max"){
                es = LLONG_MIN;
                while(additional_nulls--){ // завполняем нулями
                    data[i] = es;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _max_(data[2*i], data[2*i+1]);
                }
            }
            else if (type =="sum"){
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 0;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _sum_(data[2*i], data[2*i+1]);
                }
            }
            else if (type =="xor"){
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 0;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _xor_(data[2*i], data[2*i+1]);
                }
            }
            else if (type =="or"){
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 0;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _or_(data[2*i], data[2*i+1]);
                }
            }
            else if (type =="and"){
                
                while(additional_nulls--){ // завполняем нулями
                    data[i] = 0;
                    i--;
                }
                int yy = gh.size(), j = gh.size()-1; 
                while(yy--){ // заполняем листья
                    data[i] = gh[j];
                    i--;j--;
                }
                for (; i > 0; i--){//заполняем остальные уровни
                    data[i] = _and_(data[2*i], data[2*i+1]);
                }
            }
        }
        ll sum_seg(int l, int r){// поиск суммы на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s=_sum_(s,data[l++]);
                if (!(r & 1)) s=_sum_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        pair<ll,ll> min_seg(int l, int r){// поиск минимума на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = es;
            while (l <= r){
                if (l & 1) s=_min_(s,data[l++]);
                if (!(r & 1)) s=_min_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return {s,l};
        }
        pair<ll,ll> max_seg(int l, int r){// поиск максиума на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = es;
            while (l <= r){
                if (l & 1) s=_max_(s,data[l++]);
                if (!(r & 1)) s=_max_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return {s,l};
        }
        ll gcd_seg(int l, int r){// поиск НОДа на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s=_gcd_(s,data[l++]);
                if (!(r & 1)) s=_gcd_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        ll lcm_seg(int l, int r){// поиск НОКа на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 1;
            while (l <= r){
                if (l & 1) s=_lcm_(s,data[l++]);
                if (!(r & 1)) s=_lcm_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        ll and_seg(int l, int r){// поиск И на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = LLONG_MIN;
            while (l <= r){
                if (l & 1) s=_and_(s,data[l++]);
                if (!(r & 1)) s=_and_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        ll or_seg(int l, int r){// поиск ИЛИ на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s=_or_(s,data[l++]);
                if (!(r & 1)) s==_or_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        ll xor_seg(int l, int r){// поиск XOR на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s=_xor_(s,data[l++]);
                if (!(r & 1)) s=_xor_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        void change(int i, ll x){
            i+=arr_size;
            data[i] = x;
            for (i >>= 1; i >= 1; i >>=1){
                if (type == "sum") data[i]=_sum_(data[2*i],data[2*i+1]);
                if (type == "min") data[i]=_min_(data[2*i],data[2*i+1]);
                if (type == "max") data[i]=_max_(data[2*i],data[2*i+1]);
                if (type == "gcd") data[i]=_gcd_(data[2*i],data[2*i+1]);
                if (type == "lcm") data[i]=_lcm_(data[2*i],data[2*i+1]);
                if (type == "xor") data[i]=_xor_(data[2*i],data[2*i+1]);
                if (type == "or") data[i]=_or_(data[2*i],data[2*i+1]);
                if (type == "and") data[i]=_and_(data[2*i],data[2*i+1]);
            }
        }
        void add(int i, ll x){
            i+=arr_size;
            data[i] += x;
            for (i >>= 1; i >= 1; i >>=1){
                if (type == "sum") data[i]=_sum_(data[2*i],data[2*i+1]);
                if (type == "min") data[i]=_min_(data[2*i],data[2*i+1]);
                if (type == "max") data[i]=_max_(data[2*i],data[2*i+1]);
                if (type == "gcd") data[i]=_gcd_(data[2*i],data[2*i+1]);
                if (type == "lcm") data[i]=_lcm_(data[2*i],data[2*i+1]);
                if (type == "xor") data[i]=_xor_(data[2*i],data[2*i+1]);
                if (type == "or") data[i]=_or_(data[2*i],data[2*i+1]);
                if (type == "and") data[i]=_and_(data[2*i],data[2*i+1]);
            }
        }
        // ll seg(int l, int r){
        //     if (type == "sum") return sum_seg(l,r);
        //     if (type == "min") return min_seg(l,r);
        //     if (type == "max") return max_seg(l,r);
        //     if (type == "gcd") return gcd_seg(l,r);
        //     if (type == "lcm") return lcm_seg(l,r);
        //     if (type == "or") return xor_seg(l,r);
        //     if (type == "and") return or_seg(l,r);
        //     if (type == "xor") return and_seg(l,r);
        // }
        void print(){// выводим с пробельным сепаратором
            for (size_t i = 1; i < data.size(); i++) cout << data[i] << " "; cout << '\n';
            return;
        }
        void print(string sep){// выводим с заданным сепаратором
            for (size_t i = 1; i < data.size(); i++) cout << data[i] << sep; cout << '\n';
            return;
        }

};
inline void solve(){
    int n, k;
    cin >> n >> k;
    vc <ll> data;
    seev(data,n);
    ll count = 0;
    int j = 1;
    sort(all(data));
    incr(i,n-2*k,n-k){
        if(data[i]==data[n-j] && i == n-j-1){
            if(i>0 && i+2<n && data[i-1]!= data[i] && data[i+1]!=data[i+2]){
                continue;
            } else {
                count++;
            } 
        } else {
            count+=data[i]/data[n-j];
        }
        j++;
    }
    incr(i,0,n-2*k){
        count+=data[i];
    }
    cout << count<< nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}