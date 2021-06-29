#include <bits/stdc++.h>
using namespace std;
using  ll=long long int;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\structs\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\structs\\output.txt", "w", stdout);
}
inline void solve()
{
    size_t n,k;
    vector <pair<int,int>> pool;
    cin >> n>>k;
    pool.resize(n+1);
    for( int i=0;i< n;i++){
        cin >> pool[i].first;
        pool[i].second=i;
    }
    sort(pool.begin(),pool.end());
    ll sum=0;
    ll max_sum=INT_MIN;
    size_t ms=k-1;
    for (int i=0;i<pool.size();i++){
        for (int j=i;j<pool.size();j++){
            if (j==i) continue;
            else{
                if (abs(pool[i].second-pool[j].second)>ms){
                    if ((pool[i].first+pool[j].first)>max_sum)
                        max_sum=pool[i].first+pool[j].first;
                }
                else continue;
            }
        }
    }
    cout << max_sum;

}

int main(){
    prepare();
    solve();
    return 0;
}