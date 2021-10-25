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

vii moves = {{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
int n, m;
vc <vc <bool>> possible;

bool valid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    if (possible[i][j]) return false;
    return true;
}
bool vvalid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    return true;
}
vc <vii> bfs(int sx, int sy, int nn, int mm)
{
    vc <vii> path(nn,vii(mm));
	queue<pii> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(auto mv: moves)
		{
			int mvx = mv.first;
			int mvy = mv.second;
			if(valid(cx+mvx, cy+mvy))
			{
				q.push({cx+mvx, cy+mvy});
				possible[cx+mvx][cy+mvy] = true;
				path[cx+mvx][cy+mvy] = {mvx,mvy};
			}
		}
	}
    return path;
}
inline void solve(){
    cin >> n;
    m = n;
    possible.resize(n);
    int starti, startj,endi,endj;
    incr(i,0,n){
        possible[i].resize(m);
    }
    int ferz_x, ferz_y;
    cin >> ferz_x >> ferz_y;
    ferz_x--; ferz_y--;
    cin >> starti >> startj;
    starti--;startj--;
    cin >> endi >> endj;
    endi--; endj--;
    incr(i,0,n){
        possible[i][ferz_x] = true;
        possible[ferz_y][i] = true;
    }
    int i=ferz_y, j = ferz_x;
    while (vvalid(i,j)){
        possible[i][j] = true;
        i--;
        j--;
    }
    i=ferz_y, j = ferz_x;
    while (vvalid(i,j)){
        possible[i][j] = true;
        i++;
        j++;
    }
    i=ferz_y, j = ferz_x;
    while (vvalid(i,j)){
        possible[i][j] = true;
        i--;
        j++;
    }
    i=ferz_y, j = ferz_x;
    while (vvalid(i,j)){
        possible[i][j] = true;
        i++;
        j--;
    }
    // fca(it,possible){
    //     fca(a,it){
    //         cout << a << " ";
    //     }
    //     cout << nl;
    // }
    // cout << nl;
    vc <vii> pp = bfs(startj,starti,n,m);
    
    if(!possible[endj][endi]){
        cout <<"NO" << nl;
        return;
    }
    cout << "YES" << nl;
}
int main(){
    IOS;
    // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}