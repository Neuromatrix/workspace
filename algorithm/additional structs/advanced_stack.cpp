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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
template <class T>
class advanced_stack
{
    private:
        vector <pair <T, pair<T, T>>> data; //стек состоит из значения, знаечния макисмума и минимума на стеке
        
    public:
        void push(T val){
            if (data.empty()){
                data.push_back({val, {val, val}});
            }
            else{
                data.push_back({val,{min(val,min_el()),max(val,max_el())}});
            }
            return;
        }
        void pop(){
            data.pop_back();
            return;
        }
        T top_el(){
            return data.back().first;
        }
        T min_el(){
            return data.back().second.first;
        }
        T max_el(){
            return data.back().second.second;
        }
        ull size(){
            return data.size();
        }
        bool empty(){
            return data.empty();
        }
        void print(bool min_pl_max){
            if(min_pl_max){
                for (int i = 0; i < data.size();i++) cout << data[i].first << 
                " minimum-- " <<data[i].second.first << " maximum-- " << data[i].second.second << nl; 
            }
            else{
                for (int i = 0; i < data.size();i++) cout << data[i].first << nl; 
            }
            return;
        }
};

inline void solve(){
    advanced_stack <int> base;
    /*
        .....
    */
   return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}