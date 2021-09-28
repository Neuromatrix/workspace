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
            else{
                if(outP.find(nam[i].alpha)>=outP.length()) return false;
                else return true;
            }
        }
        void to_do(size_t j){
            size_t k = outP.find(nam[j].alpha);
            if (nam[j].alpha!=empty){
                for (size_t i = 0; i < nam[j].alpha.length(); i++){
                    outP.erase(outP.begin()+k);
                }
            }
            else{
                k = 0;
            }
            if(nam[j].betta!=empty){
                for (ssize_t i = nam[j].betta.length()-1; i >=0; i--){
                    outP.insert(outP.begin()+k,nam[j].betta[i]);
                }
            }
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