#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
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



int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}
inline vector <vector <int>> adjacency_matrix(bool weight){
    if(!weight){
        int n, to_h;
        cin >> n;cin.ignore();
        n++;
        vector <vector <int>> graph(n, vector<int>(n));
        for(size_t i = 1; i < n; i++){
            for(size_t j = i; j < n; j++){
                graph[i][j] = 0;
            }
        }
        for(size_t i = 1; i < n; i++){
            while(cin.peek() != nl){
                cin >> to_h;
                graph[i][to_h] = 1;
                graph[to_h][i] = 1;

            }
            cin.ignore();
        }
        return graph;
    }
    else {
        int n, to_h ,W;
        cin >> n;cin.ignore();
        n++;
        vector <vector <int>> graph(n, vector<int>(n));
        for(size_t i = 1; i < n; i++){
            for(size_t j = i; i < n; j++){
                graph[i][j] = 0;
            }
        }
        for(size_t i = 1; i < n; i++){
            while(cin.peek() != nl){
                cin >> to_h >> W;
                graph[i][to_h] = W;
                graph[to_h][i] = W;

            }
            cin.ignore();
        }
        return graph;
    }
}
inline vector <vector <int>> adjacency_lists(){
    int n, to_h;
    cin >> n;cin.ignore();
    n++;
    vector <vector <int>> graph(n); // списки смежности
    for(size_t i = 1; i < n; i++){
        while(cin.peek()!=nl){ 
            cin >> to_h;
            graph[i].push_back(to_h);
        }
        cin.ignore();
    }
    return graph;
}
inline vector <vector <pair <int, int>>> adjacency_lists_with_weight(){
    int n, to_h, W;
    cin >> n;cin.ignore();
    n++;
    vector <vector <pair <int, int>>> graph(n); // списки смежности
    for(size_t i = 1; i < n; i++){
        while(cin.peek()!=nl){ 
            cin >> to_h  >> W; // сначала вершина потом веса
            graph[i].push_back({to_h,W}); // записываем в пару
        }
        cin.ignore();
    }
    return graph;
}

inline vector <tuple <int, int, int>> list_of_ribs(){ // да ко их вообще юзает
    vector <tuple <int, int, int>> graph;
    int n, to_h, W;
    cin >> n;cin.ignore();
    n++;

    for(size_t i = 1; i < n; i++){
        while(cin.peek()!='\n'){ 
            cin >> to_h  >> W; // сначала вершина потом веса
            graph.push_back(make_tuple(i,to_h,W)); // записываем в кортеж
        }
        cin.ignore();
    }
    return graph;
}

inline void solve(){
    
}
int main(){
    prepare();
    solve();
    return 0;
}














