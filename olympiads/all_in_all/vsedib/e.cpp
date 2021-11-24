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
int k, x = 1;
char c;
bool flag;
vii dasha(3);
vii monster = {{-1,-1},{-1,-1},{-1,-1}};
inline void solve(){
	incr(i,0,3) {
        cin >> dasha[i].F >> dasha[i].S;
    }
	cin >> k;
	while (true) {
		flag = true;
		incr(i,0,3){
			{
				if (monster[i].F == 1) {
					dasha[i].F -= x;
					k += x;
				}
				if (monster[i].S == 1) {
					dasha[i].S -= x;
					k += x;
				}
			}
			{
				if ((monster[i].F == -1) && (k > x)) {
					dasha[i].F += x;
					k -= x;
				}
				else if ((monster[i].F == -1)) {
					dasha[i].F += k;
					k = 0;
				}
				if ((monster[i].S == -1) && (k > x)) {
					dasha[i].S += x;
					k -= x;
				}
				else if ((monster[i].S == -1)) {
					dasha[i].S += k;
					k = 0;
				}
			}
		}
		if (k != 0) {
			incr(i,0,3) {
				if ((monster[i].F == -1)) {
					dasha[i].F += k;
					k = 0;
					break;
				}
				else if ((monster[i].S == -1)) {
					dasha[i].S += k;
					k = 0;
					break;
				}
			}
			if (k != 0) {
				dasha[0].F += k;
				k = 0;
			}
        }
		cout<< "!";
		incr(i,0,3) {
			cout << " " << dasha[i].F << " " << dasha[i].S;
		}
		cout << endl;
		incr(i,0,3) {
			cin >> c;
			monster[i].F = c - 61;
			cin >> c;
			monster[i].S = c - 61;
			if ((monster[i].F == -1) || (monster[i].S == -1)) flag = false;
		}
		if (flag) break;
	}
}
int main(){
    IOS;
   // prepare();
    size_t tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}