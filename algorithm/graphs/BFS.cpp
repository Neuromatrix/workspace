#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\structs\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\structs\\output.txt", "w", stdout);
}
int binPow(int a, int pow){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a;
	} else {
		int part = binPow(a, pow >> 1);
		if (pow & 1) {
			return (((part * part)) * a);
		} else {
			return (part * part);
		}
	}
}

int stringToInt(string a){
	int max_pow = a.size() - 1;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += (a[i] - '0') * (binPow(10, max_pow));
		max_pow--;
	}
	return res;
}

int BinToInt(vector <bool> a){
	int max_pow = 0;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += a[i] * binPow(2, max_pow);
		max_pow++;
	}
	return res;
}
int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}

inline ll bfs(vector<vector<int>> pool,int target, int start){
    int cur=start;
    queue <int> arr;
    arr.push(start);
    while (arr.size()!=0){
        cout << cur<<endl;
        arr.pop();
        for(int i=0;i<pool[cur].size();i++){
            arr.push(pool[cur][i]);
        }
        cur=arr.front();
        if (cur==target) return 1;
        
    }
    return 0;
}
inline void solve(){
    size_t number_h;
    string base;
    cin >> number_h;
    vector<vector<int>> pool;
    pool.resize(number_h);
    for(int i=0;i< number_h;i++){
        getline(cin,base);
        for (int j=0;j<base.size();j++){
            if (base[j]==' ') continue;
            else if(base[j]=='-') break;
            else pool[i].push_back(base[j]-'0');
        }
    }
    for (int i=0;i<pool.size();i++){
        for (int j=0;j<pool[i].size();j++){
            cout <<i<<"--" <<pool[i][j]<<" ";
        }
        cout << endl;
    }
    cout << bfs(pool,9,1);
}
int main(){
    prepare();
    solve();
    return 0;
}














