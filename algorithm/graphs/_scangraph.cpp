#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = INT_MAX-1;
constexpr char nl = '\n';
#define fca(iterator,object) for (const auto & iteratot: object)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)
#define prints(object,type,begin,end,sep) copy(begin,end,ostream_iterator<type>(cout,sep));
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
        incr(i,1,n){
            incr(j,i,n){
                graph[i][j] = 0;
            }
        }
        incr(i,1,n){
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
        incr(i,1,n){
            incr(j,i,n){
                graph[i][j] = 0;
            }
        }
        incr(i,1,n){
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
    incr(i,1,n){
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
    incr(i,1,n){
        while(cin.peek()!=nl){ 
            cin >> to_h  >> W; // сначала вершина потом веса
            graph[i].push_back({to_h,W}); // записываем в пару
        }
        cin.ignore();
    }
    return graph;
}

inline vector <pair <int, int>> list_of_ribs(){ // да ко их вообще юзает

}

inline void solve(){
    vector <vector <int>> G=adjacency_lists();
    incr (i,1,G.size()) {incr(j,1,G[i].size()) cout << G[i][j] << " "; cout <<nl;}
}
int main(){
    prepare();
    solve();
    return 0;
}














