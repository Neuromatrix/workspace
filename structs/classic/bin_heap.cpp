#include <bits\stdc++.h>
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
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(x) (int)x.size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
template <typename T> inline T gcd(T a, T b){
    if (b==0) return a; 
    else return gcd(b,a%b);
}
template <typename T> inline T bin_cof(T n, T k, ull mod = LLONG_MAX){
    if (k==n || k==0) return 1LL; 
    else return bin_cof(n-1,k-1,mod)%mod+bin_cof(n-1,k,mod)%mod;
} 
template <typename T> inline T factorial(T n){
    if(n==1) return 1LL; 
    else return n*factorial(n-1);
}
template <typename T> 
T pow(T a, T poww,long long mod = LLONG_MAX){
	if (a == 1 || poww == 0) return 1LL;
    else if (poww == 1) return a%=mod; 
    else {
		T  part = pow(a, poww >> 1,mod)%mod;
		if (poww & 1) return (((part * part)%mod) * a)%mod; 
        else  return (part * part)%mod;
	}
}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template <typename T>
class bin_heap
{
    struct Node
    {
        T data, degree;
        Node *child, *sibling, *parent;
    };
    list<Node*> data;
    Node* newNode(T key)
    {
        Node *temp = new Node;
        temp->data = key;
        temp->degree = 0;
        temp->child = temp->parent = temp->sibling = NULL;
        return temp;
    }
    Node* mergeBinomialTrees(Node *b1, Node *b2)
    {
        if (b1->data > b2->data)
            swap(b1, b2);
    
        b2->parent = b1;
        b2->sibling = b1->child;
        b1->child = b2;
        b1->degree++;
    
        return b1;
    }
    list<Node*> unionBionomialHeap(list<Node*> l1,
                                list<Node*> l2){
        list<Node*> _new;
        auto it = l1.begin();
        auto ot = l2.begin();
        while (it!=l1.end() && ot!=l2.end())
        {
            if((*it)->degree <= (*ot)->degree)
            {
                _new.push_back(*it);
                it++;
            }
            else
            {
                _new.push_back(*ot);
                ot++;
            }
        }
        while (it != l1.end())
        {
            _new.push_back(*it);
            it++;
        }
        while (ot!=l2.end())
        {
            _new.push_back(*ot);
            ot++;
        }
        return _new;
    }
    list<Node*> adjust(list<Node*> _heap)
    {
        if (_heap.size() <= 1)
            return _heap;
        list<Node*> new_heap;
        auto it1  = _heap.begin() ,it2  = _heap.begin(),it3  = _heap.begin();
    
        if (_heap.size() == 2)
        {
            it2 = it1;
            it2++;
            it3 = _heap.end();
        }
        else
        {
            it2++;
            it3=it2;
            it3++;
        }
        while (it1 != _heap.end())
        {
            if (it2 == _heap.end())
                it1++;
            else if ((*it1)->degree < (*it2)->degree)
            {
                it1++;
                it2++;
                if(it3!=_heap.end())
                    it3++;
            }
            else if (it3!=_heap.end() &&
                    (*it1)->degree == (*it2)->degree &&
                    (*it1)->degree == (*it3)->degree)
            {
                it1++;
                it2++;
                it3++;
            }
            else if ((*it1)->degree == (*it2)->degree)
            {
                Node *temp;
                *it1 = mergeBinomialTrees(*it1,*it2);
                it2 = _heap.erase(it2);
                if(it3 != _heap.end())
                    it3++;
            }
        }
        return _heap;
    }

    list<Node*> insertATreeInHeap(list<Node*> _heap, Node *tree){
        list<Node*> temp;
        temp.push_back(tree);
        temp = unionBionomialHeap(_heap,temp);
    
        return adjust(temp);
    }
    list<Node*> removeMinFromTreeReturnBHeap(Node *tree)
    {
        list<Node*> heap;
        Node *temp = tree->child;
        Node *lo;
        while (temp)
        {
            lo = temp;
            temp = temp->sibling;
            lo->sibling = NULL;
            heap.push_front(lo);
        }
        return heap;
    }

    list<Node*> insert(list<Node*> _head, T key)
    {
        Node *temp = newNode(key);
        return insertATreeInHeap(_head,temp);
    }
    Node* getMin(bin_heap<T> h)
    {
        list<Node*> _heap = h.data;
        auto it = _heap.begin();
        Node *temp = *it;
        while (it != _heap.end())
        {
            if ((*it)->data < temp->data)
                temp = *it;
            it++;
        }
        return temp;
    }
    
    list<Node*> extractMin(bin_heap<T> h)
    {
        list<Node*> _heap = h.data;
        list<Node*> new_heap,lo;
        Node *temp;
        temp = getMin(h);
        auto it= _heap.begin();
        
        while (it != _heap.end()){
            if (*it != temp){
                new_heap.push_back(*it);
            }
            it++;
        }
        lo = removeMinFromTreeReturnBHeap(temp);
        new_heap = unionBionomialHeap(new_heap,lo);
        new_heap = adjust(new_heap);    
        return new_heap;
    }
    void printTree(Node *h)
    {
        while (h) {
            cout << h->data << " ";
            printTree(h->child);
            h = h->sibling;
        }
    }
    void printHeap(bin_heap<T> h)
    {
        list<Node*> _heap = h.data;
        auto it = _heap.begin();
        
        while (it != _heap.end())
        {
            printTree(*it);
            it++;
        }
    }
public:
    void print(){
        printHeap(*this);
    }
    T minimum(){
        return getMin(*this)->data;
    }
    void extractMin(){
        this->data = extractMin(*this);
    }
    void insert(T key){
        this->data = insert(this->data,key);
    }
    bin_heap operator+(bin_heap b){
        bin_heap <T> tmp;
        tmp.data = mergeBinomialHeap(this->data,b->data);
        return tmp;
    }
};

inline void solve(){
    int ch,key;
    bin_heap <int> h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.print();
    h.extractMin();
    h.print();
    
}
signed main(){
    IOS;
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}