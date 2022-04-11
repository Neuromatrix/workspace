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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template<int n> 
class stonesX1
{
private:
    int r1(int x) {return x+1;}
    int r2(int x) {return x*2;}
    vector <int> dp;
public:
    vector<int> game(){
        dp.assign(n,0);
        int j = n-1;
        while (r2(j)>=n or r1(j)>=n){
            dp[j] = 1;
            j--;
        }
        for (int i = j; i >= 0; i--){
            int w1 = dp[r1(i)];
            int w2 = dp[r2(i)];
            if(w1>0 and w2>0) dp[i] = -max(w1,w2)-1; // if we lose => we must lose by the maximal number of moves 
            else if(w1<0 and w2<0) dp[i] = -max(w1,w2)+1;// our victory is garant
            else if(w1>0 and w2<0) dp[i] = -w2+1; // other case 1
            else if(w1<0 and w2>0) dp[i] = -w1+1; // other case 2
        }
        dp.erase(dp.begin());
        return dp;
        
        
    }
    stonesX1(int start = 0){
        if(start){
            vector <int> res = game();
            for (const auto & it : res) {
                cout << it << nl;
            }
        }
    }
};
template <int target>
class stonesX2
{
private:
    vector <vector <int>> dp;
    int func_1(int x){
        return x<<1;
    }
    int func_2(int x){
        x+1;
    }
    int func_3(int x){
        0; // на всякий случай
    }
public:
    void init(){
        dp.resize(target);
        for(size_t i = 0; i < target; i++){
            dp[i].resize(target);
            for (size_t j = 0; i < target; j++){
                dp[i][j] = 0;
            }
        }
        simulation();
    }
    void simulation(vector <int> starters = {0,0}){
        // в i храниться сумма в первой куче на данный момент
        // в j хранится сумма в второй куче на данный момент
        for(size_t i = target-1; i >= 0; i++){
            for (size_t j = target-1; j >=0 ; j++){
                if(i+j >=target) dp[i][j] = 0; // обозначеает что сумма в кучах првосходит целевую
                else{
                    if(max({func_1(i)+j, func_2(i)+j,i+func_1(j),i+func_2(j)}) >= target) {
                        dp[i][j] = 1;
                    }// сумма двух куч, которую
                        // мы можем получить за этот ход большей целевой
                    else {
                        vector <int> possible_cases_sum = {
                            dp[func_1(i)][j],
                            dp[func_2(i)][j],
                            dp[i][func_1(j)],
                            dp[i][func_2(j)]
                            //,
                            // dp[func_3(i)][j],
                            // dp[i][func_3(j)]
                        }; // все возможные случаи применения действий
                        sort(possible_cases_sum.begin(),possible_cases_sum.end());
                        int maximum = possible_cases_sum.back();// максимум
                        int minimum = possible_cases_sum.front();// минимум
                        int maximum_negative = 0;// максимальный отрцательный
                        for(const auto &it: possible_cases_sum){
                            if(it > 0) maximum_negative = it;
                            else break;
                        }
                        //! пусть сейчас ходит первый, тогда после его хода он станет вторым, а второй первым
                        if(minimum < 0) dp[i][j] = -maximum_negative+1; // если хотя бы когда то выигрывает второй,
                        // то мы можем стать вторым(первый меняется местами со вторым) и поедить
                        else dp[i][j] = -maximum; // всегда побеждает первый, а так как мы станем вторым, 
                        //то мы можем только достойно проиграть
                    }
                }
            }
        }

    }
    int operator()(int x, int y){
        return dp[x][y];
    }
    void print(int F = -1){
        if(F==-1){
            for(size_t i = target-1; i >= 0; i++){
                for (size_t j = target-1; j >=0 ; j++)
                    cout << dp[i][j] << ' ';
                cout <<'\n';
            }
        } else 
        for (int i =0; i < target; i++){
		    cout<<i<<' '<<dp[F][i]<<'\n';
	}
    }
    stonesX2(){
        init();
    }
};

inline void solve(){
    stonesX1 <29> g;
    for (const auto & it : g.game()) {
        cout << it << nl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}