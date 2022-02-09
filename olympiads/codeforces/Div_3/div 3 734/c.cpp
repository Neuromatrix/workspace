#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = INT_MAX-1;
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
#define incr(i,a,b) for (ll i=a; i<b; ++i)
#define decr(i,a,b) for (ll i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(ll i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;i++){ll x; cin>>x; s.insert(x);}
#define fca(a,s) for(const auto & a: s)

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

inline void solve(){
    size_t n;
    cin >> n;
    vector <string> data;
    vector <char> bet = {'a', 'b', 'c', 'd', 'e'};
    incr(i,0,n){
        string tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    vc <ll> ans;
    
    vi annnns(5); 
    int counter = 0;
    incr(k,0,5){
        ll best=0,sum=0,index_r,index_l;
        incr(i,0,n){
            incr(j,0,data[i].sz){
                if (data[i][j]==bet[k]){
                    counter++;
                }
                else counter--;
                
            }
            cout << counter << " ";
            ans.push_back(counter);
            counter = 0;
            
        }
        
        cout << nl <<nl;
        
        incr(i,0,n){
            if (sum+ans[i]<ans[i]){
                index_l=i;
            }
            sum=max(sum+ans[i],ans[i]);
            if (best <= sum){
                index_r=i;
            }
            best=max(best,sum);

	    }
        annnns.pb(index_r-index_l+1);
    }
    cout << *max_element(all(annnns)) <<nl;
    
    return;
}

int main(){
    IOS;
    prepare();
    size_t tests = 1;
    cin >> tests;
    while(tests--) solve();
    return 0;
}