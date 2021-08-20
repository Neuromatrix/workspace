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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
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
inline void solve(){
    /*
        ...
    */
    return;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    solve();
    return 0;
}