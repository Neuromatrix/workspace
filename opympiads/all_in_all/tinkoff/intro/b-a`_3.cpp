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
constexpr char nl = '\n';
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)     
#define int long long

const int INF = 1e18;
const int N = 51; 
const int K = 17; 
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int n, m;
vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1, -1, 0, 0 };
vector<vector<pair<int, int>>> comp; 
vector<bool> used_comps; 
vector<vector<int>> gr; 
map<pair<int, int>, int> cell;
char matr[N][N]; 
bool used[N][N];
int cnt;

bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void dfs(int x, int y) {
    if (used[x][y]) return;
    used[x][y] = 1;
    comp[cnt].push_back({ x, y });
    cell[{x, y}] = cnt;
    for (int i = 0; i < 4; i++) {
        if (check(x + dx[i], y + dy[i]) && matr[x + dx[i]][y + dy[i]] == 'X') {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void bfs(int _x, int _y) { 
    int d[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) d[i][j] = INF;
    }
    d[_x][_y] = 0;
    deque<pair<int, int>> q;
    q.push_back({ _x, _y });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            if (check(x + dx[i], y + dy[i]) && matr[x + dx[i]][y + dy[i]] != '.') {
                int edge = 0;
                if (matr[x + dx[i]][y + dy[i]] == 'S') edge = 1;
                if (d[x][y] + edge < d[x + dx[i]][y + dy[i]]) {
                    d[x + dx[i]][y + dy[i]] = d[x][y] + edge;
                    if (edge) q.push_back({ x + dx[i], y + dy[i] });
                    else q.push_front({ x + dx[i], y + dy[i] });
                }
            }
        }
    }
    int cur_comp = cell[{_x, _y}];
    used_comps[cur_comp] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[i][j] == 'X' && !used_comps[cell[{i, j}]]) {
                int cmp = cell[{i, j}];
                gr[cur_comp][cmp] = d[i][j];
                gr[cmp][cur_comp] = d[i][j];
                used_comps[cur_comp] = 1;
            }
        }
    }
}

int hamilton() {
    int n = gr.size();
    int ut = 1 << n;
    vc <vc <ll>> dp(ut,vc <ll>(n,INF));
    incr(mask,0,ut){
        int count = __builtin_popcount(mask);
        incr(i,0,n){
            if(mask&(1<<i) && count!=0){
                if (count==1){
                    dp[mask][i] = 0;
                } else {
                    dp[mask][i] = INF;
                    int newmask = mask^(1<<i);
                    incr(j,0,n){
                        if(newmask& (1<<j)){
                            if(dp[newmask][j]+gr[i][j]<dp[mask][i]){
                                dp[mask][i] = dp[newmask][j] + gr[i][j];
                            }
                        }
                    }
                }
            } else {
                dp[mask][i] = INF;
            }
        }
    }
    return *min_element(all(dp[ut-1]));
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[i][j] == 'X' && !used[i][j]) {
                comp.push_back({});
                dfs(i, j);
                cnt++;
            }
        }
    }
    gr.resize(comp.size(), vector<int>(comp.size()));
    used_comps.resize(comp.size());

    for (int i = 0; i < comp.size(); i++)
        bfs(comp[i][0].first, comp[i][0].second);

    cout << hamilton() << "\n";
}

signed main() {
    IOS;
    //prepare();
    solve();
    return 0;
}