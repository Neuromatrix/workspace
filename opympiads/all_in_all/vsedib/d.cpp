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
const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
struct node {
    node* next[26];
    bool leaf = 0;
    node(){
        incr(i,0,26) {
            next[i] = NULL;
        }
    }
};

node* root = new node();
vc <string> data;
map<string, int> ans;
int n, m;

void add(string s) {
    node* cur_v = root;

    incr(i,0,s.sz) {
        char c = s[i];

        if (cur_v->next[c - 'a'] == NULL) {
            cur_v->next[c - 'a'] = new node();
        }

        cur_v = cur_v->next[c - 'a'];
    }

    cur_v->leaf = 1;
}

void count(int i, int j, vii path, string curstr, node* cur) {
    if (!cur) return;
    if (cur->leaf) {
        ans[curstr]++;
    }
    path.push_back({ i, j });
    incr(f,0,4) {
        int x = i + dx[f];
        int y = j + dy[f];
        if (x > -1 && x < n && y > -1 && y < m && 
        find(all(path), make_pair(x, y)) == path.end() && 
        cur->next[data[x][y] - 'a']) {
            count(x, y, path, curstr + string(1, data[x][y]), cur->next[data[x][y] - 'a']);
        }
    }
}

void solve() {
    cin >> n >> m;
    data.resize(n);
    incr(i,0,n) cin >> data[i];
    int woe;
    cin >> woe;
    while (woe--) {
        string temp;
        cin >> temp;
        add(temp);
    }
    incr(i,0,n) {
        incr(j,0,m) {
            count(i, j, {}, string(1, data[i][j]), root->next[data[i][j] - 'a']);
        }
    }
    
    cout << ans.sz << nl;
    fca(it,ans) cout << it.first << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}