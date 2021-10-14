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
class easy_matrix
{
private:
    int n;
    int ** data;
public:
    easy_matrix operator* (int skalyar){
        for(size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                data[i][j]*=skalyar;
            }
        }
        return easy_matrix(data);
    }
    easy_matrix operator+ (easy_matrix &x){
        int ** b = x.data;
        for (size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                data[i][j]+=b[i][j];
            }
        }
        return easy_matrix(data);
    }
    easy_matrix operator*(easy_matrix &x){
        int ** b = x.data;
        int** result= new int*[n];
        for (int i = 0; i < n; i++) 
        {
            result[i] = new int[n];
        }
        for(size_t i = 0; i < n; i++){
            for(size_t j = 0; j < n; j++){
                result[i][j] = 0;
            }
        }
        for(size_t i = 0; i < n; i++){
            for(size_t j = 0; j < n; j++){
                for(size_t k = 0; k < n; k++){
                    result[i][j]+=data[i][k]*b[k][j];
                }
            }
        }   
        return easy_matrix(result);
    }
    int track(){
        int result = 0;
        incr(i,0,n){
            result+=data[i][i];
        }
        return result;
    }
    vi column(int j){
        vi ans;
        incr(i,0,n){
            ans.pb(data[i][j]);
        }
        return ans;
    }
    vi str(int j){
        vi ans;
        incr(i,0,n){
            ans.pb(data[j][i]);
        }
        return ans;
    }
    easy_matrix(vc <vi> input){
        n = input.size();
        this->data= new int*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[n];
        }
        for(size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                data[i][j] =  input[i][j];
            }
        }
    }
    easy_matrix(int ** input){
        this-> n = sqrt(sizeof(input)/sizeof(int));
        this->data= new int*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[n];
        }
        for(size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                data[i][j] =  input[i][j];
            }
        }
    }
    easy_matrix(int n){
        this->n = n;
        this->data= new int*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[n];
        }
        for(size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                data[i][j] = (i==j ? 1 : 0);
            }
        }
    }
    
    ~easy_matrix(){
        for (int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    void print(){
        for(size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                cout << this->data[i][j] << " ";
            }
            cout << nl;
        }
    }
};



inline void solve(){
    vc <vi>  f = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    vc <vi>  o = {
        {1,2,3},
        {0,1,0},
        {1,2,3},
    };
    easy_matrix d(f);
    easy_matrix g(o);
    d.print();
    d = d*g;
    d.print();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prepare();
    solve();
    return 0;
}