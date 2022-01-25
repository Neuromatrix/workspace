#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#define B 'B'
#define R 'R'
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
class segtree{
    private:
        vector <int> data;
        int arr_size; // размер первого уровня листьев
        bool initial = false;
        int nulls_res(int i){ // вычисление дополнительных нулей до степени двойки
            int pow = ceil(log2(i));
            return 2<<(pow-1);
        }
    public:
        void init(vector <bool> gh){// инициализация дерева через вектор (численных типов)
            int additional_nulls=nulls_res(gh.size())-gh.size();// дополнительные нули
            arr_size = nulls_res(gh.size()); //изменение размера листьев
            data.resize(2*arr_size);// изменение размера дерева
            int i = data.size()-1;// итератор
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
                data[i] = (data[2*i]+data[2*i+1]);
            }
            
        }
        ll sum_seg(int l, int r){// поиск суммы на отрезке [a, b]
            l+=arr_size;
            r+=arr_size;
            ll s = 0;
            while (l <= r){
                if (l & 1) s+=data[l++];
                if (!(r & 1)) s+=data[r--];
                l >>= 1; r >>= 1;
            }
            return s;
        }

};
inline void solve(){
    segtree rh;
    int n;
    ll ans = 0;
    cin >> n;
    vc <int> ff;
    seev(ff,n);
    vc <bool> yy;
    incr(i,0,n){
        if(i%2==0){
            incr(j,0,ff[i]){
                yy.push_back(1);
            }
        }
        else {
            incr(j,0,ff[i]){
                yy.push_back(0);
            }
        }
    }
    rh.init(yy);
    incr(i,0,n){
        incr(j,0,n){
            if (i==j) continue;
            if(rh.sum_seg(i,j)==abs(i-j)) ans++;
        }
    }
    cout << ans << nl;
}
    

int main(){
    IOS;
    //prepare();
    size_t tests = 1;
    //cin >> tests;
    while(tests--) solve();
    return 0;
}