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
vii moves = {{0,-1},{0,1},{1,0},{-1,0}};
int n, m;
vc <vc <bool>> possible;

bool valid(int i, int j){
    if(i<0 || i >=n  || j < 0 || j>=m) return false;
    if (possible[i][j]) return false;
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
    cin >> n >> m;
    possible.resize(n);
    int starti, startj,endi,endj;
    incr(i,0,n){
        possible[i].resize(m);
        incr(j,0,m){
            char c; cin >> c;
            if (c=='A'){
                starti = i;
                startj = j;
            } else if (c=='B'){
                endi = i;
                endj = j;
            } else if (c=='#'){
                possible[i][j] = true;
            } else possible[i][j] = false;
        }
    }
    vc <vii> pp = bfs(starti,startj,n,m);
    if(!possible[endi][endj]){
        cout <<"NO" << nl;
        return;
    }
    cout << "YES" << nl;
    vii ans;
    pii end = {endi, endj};
    while(end.first != starti || end.second != startj)
	{
		ans.push_back(pp[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
    reverse(ans.begin(), ans.end());
	cout << ans.size() << nl;
	fca(c,ans)
	{
		if(c.first == 1 and c.second ==0) cout << 'D';
		else if(c.first == -1 and c.second ==0) cout << 'U';
		else if(c.first == 0 and c.second == 1)	cout << 'R';
		else if(c.first == 0 and c.second == -1) cout << 'L';
	}
}
int main(){
    IOS;
    //prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}