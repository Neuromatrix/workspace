// #include <bits\stdc++.h>
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
template <typename T>
class lseg_tree
{
    private:
        vector <T> data;
        vector <T> lazy;
        string type = "min";
        size_t arr_size = 0; 
        vector <T> inp;
        T es = 0;
        void setPush(int cur,T ad){
            if (cur>arr_size || cur+1>arr_size) return;
            else{
                if (cur!=1){
                    lazy[2*cur+1]+=lazy[cur];
                    lazy[2*cur]+=lazy[cur];
                    lazy[cur] = 0;
                } else {
                    lazy[2*cur+1]+=ad;
                    lazy[2*cur]+=ad;
                }
                
                return;
            }
        }
        void mass_update(int cur, int tl, int tr, int l, int r,int ad){
            cout << tl << tr << endl;
            if (l > r)
		        return;
            if(l==tl && r ==tr){
                setPush(cur,ad);
                data[cur]+=(lazy[cur]+ad);
            } else {
                setPush(cur,ad);
                int tm = (tl + tr) / 2;
                mass_update (cur*2, tl, tm, l, min(r,tm), ad);
                mass_update (cur*2+1, tm+1, tr, max(l,tm+1), r, ad);
            }
        } 
        int nulls_res(int i){ // вычисление дополнительных нулей до степени двойки
            int pow = ceil(log2(i));
            return 2<<(pow-1);
        }
        T _min_(T a,T  b){
            return min(a,b);
        }
        T _max_(T a,T  b){
            return max(a,b);
        }
        T _sum_(T a, T b){
            return a + b;
        }
    public:
        void init(vector <T> gh){// инициализация дерева через вектор (численных типов)
            inp = gh;
            int additional_nulls=nulls_res(gh.size())-gh.size();// дополнительные нули
            arr_size = nulls_res(gh.size()); //изменение размера листьев
            data.resize(2*arr_size);// изменение размера дерева
            lazy.assign(2*arr_size,0);
            int i = data.size()-1;// итератор
            if (type == "min"){
                es = INF;
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
                es = -INF;
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
        void one_change(int i, T x){
        }
        void one_add(int i, T x){
        }
        void mass_update(int l, int r,int ad){
            mass_update(1,0,arr_size-1,l,r,ad);
        }
        void print(string sep = " "){// выводим с заданным сепаратором
            for (size_t i = 1; i < data.size(); i++) (data[i]==INF || data[i]==-INF) ? cout << "-" << sep : cout << data[i]<< sep; cout << '\n';
            return;
        }
        void lazy_print(string sep = " "){// выводим с заданным сепаратором
            for (size_t i = 1; i < data.size(); i++) cout << lazy[i] << sep; cout << '\n';
            return;
        }
};


inline void solve(){
    vi data= {1,2,3,4,5};
    lseg_tree <int> doo;
    doo.init(data);
    doo.print();
    doo.mass_update(0,7,1);
    doo.print();
    doo.lazy_print();
}
int main(){
    IOS;
    prepare();
    solve();
    return 0;
}