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
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.fi << " " << v.se;return out;}
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
ll xorSum(vector <ll> arr, int n){
    ll bits = 0;
    // Finding bitwise OR of all elements
    for (int i=0; i < n; ++i)
        bits |= arr[i];
 
    ll ans = (bits * pow(2, n-1,MOD));
    return ans%MOD;
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
        ll min_seg(int l, int r){// поиск минимума на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = es;
            while (l <= r){
                if (l & 1) s=_min_(s,data[l++]);
                if (!(r & 1)) s=_min_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        ll max_seg(int l, int r){// поиск максиума на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = es;
            while (l <= r){
                if (l & 1) s=_max_(s,data[l++]);
                if (!(r & 1)) s=_max_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
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
        ll seg(int l, int r){
            if (type == "sum") return sum_seg(l,r);
            if (type == "min") return min_seg(l,r);
            if (type == "max") return max_seg(l,r);
            if (type == "gcd") return gcd_seg(l,r);
            if (type == "lcm") return lcm_seg(l,r);
            if (type == "or") return or_seg(l,r);
            if (type == "and") return and_seg(l,r);
            if (type == "xor") return xor_seg(l,r);
        }
        void print(){// выводим с пробельным сепаратором
            for (size_t i = 1; i < data.size(); i++) cout << data[i] << " "; cout << '\n';
            return;
        }
        void print(string sep){// выводим с заданным сепаратором
            for (size_t i = 1; i < data.size(); i++) cout << data[i] << sep; cout << '\n';
            return;
        }

};

template <typename T>
class lseg_tree
{
    private:
        vector <T> tree;
        vector <T> mod; 
        int size_it = 0;
        void push(int v, int tl, int tr) {
            if (mod[v] != 0 && v * 2 + 1 < 4*size_it){
                mod[v * 2] = mod[v * 2 + 1] = mod[v];
                mod[v] = 0;
                int tm = (tl + tr) / 2;
                tree[v * 2] = (tm - tl + 1) * mod[v * 2];
                tree[v * 2 + 1] = (tr - tm) * mod[v * 2 + 1];
            }
        }
        void build (const vector <T> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }
        void update (int v, int tl, int tr, int l, int r, int val) {
            if (l <= tl && tr <= r) {
                tree[v] = val * (tr - tl + 1);
                mod[v] = val;
                return;
            }
            if (tr < l || r < tl) {
                return;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, r, val);
            update(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
        T sum (int v, int tl, int tr, int l, int r) {
            if (l <= tl && tr <= r) {
                return tree[v];
            }
            if (tr < l || r < tl) {
                return 0;
            }
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return sum( v * 2, tl, tm, l, r)
                + sum(v * 2 + 1, tm + 1, tr, l, r);
        }
    public:
        void init(vector <T> a){
            tree.resize(4*a.size());
            mod.assign(4*a.size(),0);
            size_it = a.size();
            build(a,1,0,size_it - 1);
        }
        T get(int pos){
            return sum(1,0,size_it-1,pos,pos);
        }
        void update(int l, int r, int add){
            update(1,0,size_it-1,l,r,add);
        }
        T sum(int l, int r){
            return sum(1,0,size_it-1,l,r);
        }
        lseg_tree(vector <T> a){
            init(a);
        }
        lseg_tree(){}
        void print(){
            incr(i,0,tree.size()){
                cout << tree[i] << " ";
            }
            cout << nl;
        }
};
inline void solve(){
    int n,m;
    cin >> n >> m;
    vc <ll> ans(n,0);
    vector <ll> xors;
    vc < tuple<int, int, int> > query;
    int a, b, w;
    while (m--){
        cin >> a >> b >> w;
        query.push_back({w,a,b});
    }
    sort(rall(query));
    lseg_tree <ll> tree(ans);
    fca(it,query){
        tie(w,a,b) = it;
        a--;
        b--;
        tree.update(a,b,w);
    }
    incr(i,0,n){
        xors.pb(tree.get(i));
    }
    cout << xorSum(xors,n) << nl;
}
signed main(){
    IOS;
    // prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}