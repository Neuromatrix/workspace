#include <bits/stdc++.h>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\structs\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\structs\\output.txt", "w", stdout);
}
inline void solve()
{
    size_t size;
    string sco;
    cin >> sco;
    int counter=0;
    stack <char> ep;
    for( int i=0;i< sco.size();i++){
        if (sco[i]=='('){
            ep.push('(');
        }
        else{
            if (ep.size()==0)
                counter++;
            else ep.pop();
        }
    }
    cout << counter+ep.size()<<endl;
    return;
}

int main(){
    solve();
    return 0;
}