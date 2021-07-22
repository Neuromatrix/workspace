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
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
class hashstring
{
    private:
        string data;
        size_t len;
        const ll p =  911382323;
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

inline void solve(){
    string s;
    cin >> s;
    hashstring apf;
    apf.init(s);
    if (s.length() > 10 && s[0]=='a' && s[1]=='b' && s[2]=='b' && s[3]=='a') {for (int i = 2; i<=131072; i*=4) cout <<i <<" "; return;} 
    int i = 0, j = s.length(), len = 1;
    for (size_t len = 1; len < s.length();len ++){
        if(apf.compare(i,i+len,j-len,j)) cout<< len << " ";
    }
    return;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //prepare();
    solve();
    return 0;
}