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
class turing_machine
{
    private:
        vc <vc <tuple <char,int,int>>> machine;
        string ribbon,input;
        size_t n,m;
        unordered_map <char, int> Z;
        bool dbg = 1,lmd_pr = 0;
        // func
        int binPow(int a, int pow){ // помощь для переовда строкив  число
            if (a == 1 || pow == 0) {
                return 1;
            } else if (pow == 1) {
                return a;
            } else {
                int part = binPow(a, pow >> 1);
                if (pow & 1) {
                    return (((part * part)) * a);
                } else {
                    return (part * part);
                }
            }
        }
        int stringToInt(string a){// перевод стркои в число
            int max_pow = a.size() - 1;
            int res = 0;
            for (int i = 0; i < a.size(); i++){
                res += (a[i] - '0') * (binPow(10, max_pow));
                max_pow--;
            }
            return res;
        }
        int id(char a){// вывод номера буквы в алфавите
            return Z[a];
        }
        tuple <char,int,int> parsing(string ptr){// перевод строки в кортеж из символа, направления движения, и номера режима
            int move,mode;
            char symbol;
            if (ptr[0]==',') {symbol = '&';ptr.erase(ptr.begin());}// на всякий если символ не указан
            else{
                symbol=ptr[0];
                ptr.erase(ptr.begin());
                ptr.erase(ptr.begin());
            }
            if(ptr[0] == 'N') move = 0;
            else if (ptr[0] == 'R') move = 1;
            else move = -1;
            ptr.erase(ptr.begin());
            ptr.erase(ptr.begin());
            mode = stringToInt(ptr);
            return make_tuple(symbol,move,mode);
        }
        int ribbon_prepare(){// подготовка и эмуляция бесконечной ленты
            ribbon.resize(7*input.length());
            int i = 0, ans;
            while(i<3*input.length()){
                ribbon[i]='#';
                i++;
            }
            ans = i;
            int j = 0;
            while(i<4*input.length()){
                ribbon[i] = input[j];
                j++; i++;
            }
            while(i<7*input.length()){
                ribbon[i]='#';
                i++;
            }
            return ans;
        }
        void Z_prepare(string alphabet){// подготовка алфавита
            incr(i,0,alphabet.length()){
                Z[alphabet[i]] = i;
            }
            return;
        }
    public:
        turing_machine(){n=0;m=0;}
        void init(){// запускаяем для инициализации и считывания файла
            string alphabet;
            cin >> alphabet;
            alphabet.pb('=');
            alphabet.pb('#');
            Z_prepare(alphabet);
            m = alphabet.length();
            cin >> n;
            string ptr;
            machine.resize(n);
            incr(i,0,n){
                machine[i].resize(m);
                incr(j,0,m){
                    cin >> ptr;
                    machine[i][j] = parsing(ptr);
                }
            }
            cin >> input;
            cin >> dbg;
        }
        void simulation(){// запуск симуляции
            int it = ribbon_prepare();
            int move, mode;
            char symb;
            tie(symb,move,mode) = machine[0][id(input[0])];
            while(true){
                if(!dbg) print(); 
                if(symb!='&'){
                    ribbon[it] = symb;
                }
                it+=move;
                if(mode==0) break;
                tie(symb,move,mode) = machine[mode-1][id(ribbon[it])];
            }
            print();
        }
        void print(string sep = " "){
            incr(i,0,ribbon.length()){
                if(ribbon[i]=='#' && !lmd_pr) continue;
                else cout << ribbon[i] << sep;
            }
            cout << endl;
        }
        void print_machine_table_dbg(string sep = " "){
            incr(i,0,n){
                incr(j,0,m){
                    int a,b;
                    char w;
                    tie(w,a,b) = machine[i][j];
                    cout << w <<" "<< a << " "<< b << "   ";
                }
                cout << endl;
            }
            cout << endl;
        }
        void status(){
            cout << "q_num:: " << n 
            << nl << "alphabet:: " << m << nl << "mode_dbg:: " << dbg << endl;
        }
};


inline void solve(){
    turing_machine iii;
    iii.init();
    iii.print_machine_table_dbg();
    iii.simulation();
}

int main(){
    IOS;
    prepare();
    solve();
    return 0;
}