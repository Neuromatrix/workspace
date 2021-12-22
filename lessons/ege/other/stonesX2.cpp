#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>
#include <cassert>
#include <cstring>
#include <climits>
using namespace std;

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
                            dp[i][func_2(j)]//,
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
//вот это код короткий
int h1(int x) {return x*2;}
int h2(int x) {return x+1;}
int nmx(int a,int b, int c, int d){
    return -min({a<0 ? -a : 1000,b<0 ? -b : 1000,c<0 ? -c : 1000,d<0 ? -d : 1000});
}
inline void solve(){
    int n,f=13;
    cin >> n;
    vector <vector <int>> dp(n,vector <int>(n,0));
    int i, j;
    for(i = n-1; i >-1;i--)
        for(j = n-1; j>-1;j--){
            if(i+j>=n) {dp[i][j] = 0; continue;}
            if(max({h1(i)+j, h2(i)+j,i+h1(j),i+h2(j)}) >= n) {dp[i][j] = 1; continue;}
            int mx = max({dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]});
            int mn = min({dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]});
            int nm = nmx(dp[h1(i)][j],dp[h2(i)][j],dp[i][h1(j)],dp[i][h2(j)]);
            mn<0 ? dp[i][j] =  -nm+1 : dp[i][j] = -mx;
        }
    for (int i =0; i < n; i++){
		cout<<i<<' '<<dp[f][i]<<endl;
	}
}
signed main(){
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}