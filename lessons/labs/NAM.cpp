// prefix_comms

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
#include <unordered_map>
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
vector<size_t> Rabin_Karp(string s,string sub){
    hashstring hs;
    hashstring hsub;
    hs.init(s);
    hsub.init(sub);
    size_t len = sub.size();
    vector <size_t> ans;
    for (size_t i = 0;i+len-1 < s.size(); i++){
        if (hsub.allhash()*hs.poww(i)==hs.prefix_hash(i,len)) ans.push_back(i);//сравниванием хэши
    }
    return ans;
}
class NAM
{
    private:
        struct comm
        {
            string alpha,betta;
            bool todo;
        };
        vector <comm> nam;
        size_t n;
        string P;
        string outP;
        string alphabet;
        string empty = "_";
        bool dbg_mod;
        bool iscontinue(size_t i){
            return nam[i].todo;
        }
        bool possible(size_t i){
            if(nam[i].alpha==empty) return true;
            else
                if(Rabin_Karp(outP,nam[i].alpha).size()==0) return false;
                else return true;
        }
        void to_do(size_t j){
            //size_t k = outP.find(nam[j].alpha);
            //fast//
            size_t k = *Rabin_Karp(outP,nam[j].alpha).begin();
            if (nam[j].alpha!=empty)
                for (size_t i = 0; i < nam[j].alpha.length(); i++)
                    outP.erase(outP.begin()+k);
            else k = 0;
            if(nam[j].betta!=empty)
                for (ssize_t i = nam[j].betta.length()-1; i >=0; i--)
                    outP.insert(outP.begin()+k,nam[j].betta[i]);
        }
    public:
        void init(){
            cin >> n;
            nam.resize(n);
            for(size_t i = 0; i < n; i++){
                cin >> nam[i].alpha;
                string c; cin >> c;
                if(c=="->") nam[i].todo = 1;
                else nam[i].todo = 0;
                cin >> nam[i].betta;
            }
            cin >> dbg_mod;
            cin >> P;
            outP = P;
            return;
        }
        void print(){
            cout << outP << endl;
        }
        void simulation(){
            int duration = 1e6;
            bool flag;
            while(duration--){
                flag = false;
                for (size_t i = 0; i < n; i++){
                    if(possible(i)){
                        to_do(i);
                        if(!dbg_mod) print();
                        if(iscontinue(i)) {flag = true;break;}
                        else return;
                    } else continue;
                }
                if(!flag) break;
            }
            print();
        }
        void print_table_dbg(){
            for(const auto & it : nam){
                if(it.todo==0) cout << it.alpha << " |> " << it.betta << endl;
                if(it.todo==1) cout << it.alpha << " -> " << it.betta << endl;
            } 
        }
};


inline void solve(){
    NAM ts;
    ts.init();
    ts.simulation();
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}