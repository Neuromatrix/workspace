#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
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
#define rall(x) x.rbegin(),x.rend()
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
class fridge
{
  
    int weight,length,height;
    string color;
    public:
    fridge(string col, int length, int weight, int height) {
        this-> color = col;
        this->weight = weight;
        this-> length = length;
        this->height = height;
    }
    fridge(int size) {
        this->weight = size;
        this-> length = size;
        this->height = size;
    }
    fridge operator++(int){
        this->weight++;
        this-> length++;
        this->height++;
        return *this;
    }
    const fridge & operator++(){
        ++this->weight;
        ++this-> length;
        ++this->height;
        return *this;
    }
    friend ostream& operator<< (ostream& out, const fridge& F);
    fridge operator+ (const fridge & d) {
        this->weight += d.weight;
        this-> length += d.length;
        this->height += d.height;
        return *this;
    }
    friend fridge operator+(const int & a, const fridge & d);
    int& operator [] (const int index) {
        if(index==1) return length;
        if(index==2) return weight;
        return height;
    }
};

ostream& operator<< (ostream& out, const fridge& F){ 
    out << F.weight << " " <<F.length << " " << F.height << " " <<F.color << nl;
    return out; 
}
fridge operator+(const int & a, const fridge & d) {
    fridge ans("e",d.weight+a,
    d.length+a,
    d.height+a);
    return ans;
}

struct X 
{
  X(int a =0) {}
  operator int(){return 0;}
} x;
void f (int i, const char * x ="str") {}
void f (char x, char y) {}


void g (const char * x = "str") {}
void g (int i, int j = 0) {}

void h (const char * y, const char * x ) {}
void h (int i, int j) {}

void q (const char * x, const char * y = "uu") {}
void q (int o, const char * y = "uu") {}

void p (ll i = 0, const char * x = "uu") {}
void p (const char * x) {}
inline void solve(){
    fridge R("blue",7,1,12); //цвет, длина, ширина, высота
    fridge G( 7);//холодильник белого цвета 7х7х7
    fridge Res = R++; /* оператор ++ увеличивает на 1 все размеры
    //  Res – копия R до увеличения размеров*/
    cout<<Res<<R<<G;//вывод информации о холодильниках
    Res =G+R; /*цвет – любой, каждый размер = сумме размеров
    //  холодильников-слагаемых */
    Res=4+G;//та же функция сложения, что и в предыдущем операторе
    cout<<Res<<R<<G;//вывод информации о холодильниках
    Res[1]=Res[2]+10;//длина холодильника = ширина холодильника+10
    cout<<Res<<R<<++G;//вывод информации о холодильниках
    f (1);
    f ('+', '+');
    f (2.3);
    f (3, "str");


    g ();
    g ("abc");
    g (2);
    g ('+', 3);

    h (0, 1);
    h (1, 0);
    h (0, "m");
    h ("n", 0);

    q ("p"); 
    q (x, 0); 
    q (0, 0); 
    q (x, "q"); 
    q (1, "r");

    p (1000000000000);
    p (1);
    p ();
    p (0, 0);
    p ("t");
    p (1, "fu");
}
int main(){
    IOS;
    prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}
