#include <bits/stdc++.h>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
inline void solve()
{
    size_t size;
    cin >> size;
    string tasks;
    set <char> ans;
    cin >> tasks;
    for (int i=0;i<tasks.size();i++){
        if (i!=0){
            if (tasks[i]==tasks[i-1]) continue;
            else{
                if(ans.find(tasks[i])==ans.end()){
                    ans.insert(tasks[i]);
                }
                else {
                    cout << "NO"<<endl;
                    return;
                }
            }
        }
        else{
            if(ans.find(tasks[i])==ans.end()){
                ans.insert(tasks[i]);
            }
            else {
                cout << "NO"<<endl;
                return;
            }
        }
    }
    cout << "YES"<<endl;
    return;
}

int main(){
    prepare();
    size_t test;
    cin >> test;
    for (int i=0;i< test;i++){
        solve();
    }
    
    return 0;
}