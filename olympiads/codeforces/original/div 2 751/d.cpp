#include <bits\stdc++.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr ll LINF = LLONG_MAX-1;
constexpr ll MOD = 1000000007;
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
int getSum(int BITree[], int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[], int n, int index, int val)
{
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
void convert(deque <int> arr, int n)
{
    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
    for (int i=0; i<n; i++){    
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}
int getInvCount(deque <int> arr, int n)
{
    int invcount = 0;
    convert(arr, n);
    int BIT[n+1];
    for (int i=1; i<=n; i++)
        BIT[i] = 0;
    for (int i=n-1; i>=0; i--)
    {
        invcount += getSum(BIT, arr[i]-1);
        updateBIT(BIT, n, arr[i], 1);
    }
 
    return invcount;
}
inline void solve(){
    int n, m;
    cin >> n >> m;
    deque<int> a,b;
    seev(a,n);
    seev(b,m);
    sort(all(b));
    deque <int> ans;
    incr(i,0,m+n){
        if(a.empty() && !b.empty()){
            ans.push_back(b.front());
            b.pop_front();
        }
        else if(b.empty() && !a.empty()){
            ans.push_back(a.front());
            a.pop_front();
        } else if(b.empty() && a.empty()){
            break;
        } else { 
            if(a.front()<=b.front()){
                ans.push_back(a.front());
                a.pop_front();
            } else {
                ans.push_back(b.front());
                b.pop_front();
            }
        }
    }
    fca(it, ans) cout << it << " "; cout << endl;
    cout << getInvCount(ans,n+m) << nl;
    
}
int main(){
    IOS;
    prepare();
    size_t tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}