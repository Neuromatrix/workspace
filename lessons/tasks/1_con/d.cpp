#include <bits/stdc++.h>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\structs\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\structs\\output.txt", "w", stdout);
}
inline void solve()
{
    map<string,map<string,long long int>> peoples;
    string byer,vesh;
    long long  int cou;
    while (cin>>byer){
        cin>> vesh>>cou;
        peoples[byer][vesh]+=cou;
    }
    for (const auto &a: peoples){
        cout << a.first<<':'<<endl;
        for(const auto &b: a.second){
            cout << b.first<<" "<<b.second<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}