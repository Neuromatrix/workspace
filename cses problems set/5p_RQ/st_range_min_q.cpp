// https://cses.fi/problemset/task/1647
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
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
template <typename T>
class seg_tree
{
    private:
        vector <T> data; //дерево оотрезков в виде массива
        vector <T> inp; //исхлдный массив
        int arr_size; // размер первого уровня листьев
        T es;
        bool initial = false;
        int nulls_res(int i){ // вычисление дополнительных нулей до степени двойки
            int pow = ceil(log2(i));
            return 2<<(pow-1);
        }
        T _min_(T a,T b){
            return min(a,b);
        }
        T _max_(T a,T b){
            return max(a,b);
        }
        T _gcd_(T a, T b){
           if (b==0) return a;
           return _gcd_(b,a%b); 
        }
        T _lcm_ (T a, T b){
            return (a/_gcd_(a,b))*b;
        }
        T _sum_(T a, T b){
            return a + b;
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
        int size(){//размер дерева
            return data.size();
        }
        void init(vector <T> gh){// инициализация дерева через вектор (численных типов)
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
                es = *max_element(gh.begin(), gh.end())+1;
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
                es = *min_element(gh.begin(), gh.end())-1;
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
        ll min_seg(int l, int r){// поиск суммы на отрезке [a, b]
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
        ll max_seg(int l, int r){// поиск суммы на отрезке [a, b]
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
        ll gcd_seg(int l, int r){// поиск суммы на отрезке [a, b]
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
        ll lcm_seg(int l, int r){// поиск суммы на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s=_lcm_(s,data[l++]);
                if (!(r & 1)) s=_lcm_(s,data[r--]);
                l >>= 1; r >>= 1;
            }
            return s;
        }
        void change(int i, T x){
            i+=arr_size;
            data[i] = x;
            for (i >>= 1; i >= 1; i >>=1){
                if (type == "sum") data[i]=_sum_(data[2*i],data[2*i+1]);
                if (type == "min") data[i]=_min_(data[2*i],data[2*i+1]);
                if (type == "max") data[i]=_max_(data[2*i],data[2*i+1]);
                if (type == "gcd") data[i]=_gcd_(data[2*i],data[2*i+1]);
                if (type == "lcm") data[i]=_lcm_(data[2*i],data[2*i+1]);
            }
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

inline void solve(){
    seg_tree <ll> pool("min");
    vector <long long> data;
    int n,m;
    cin >> n >> m;
    seev(data,n);
    pool.init(data);
    incr(i,0,m){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << pool.min_seg(a,b) << nl;
    }
    return;
}

int main (){
    IOS;
    prepare();
    solve();
    return 0;
}