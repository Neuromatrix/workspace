#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
#define fca(a,s) for(const auto & a: s)
#define incr(i,k,n) for (int i = k; i < n; i++)
#define decr(i,k,n) for (int i = k; i > n; i--)

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

int fast_powtw(int k) { return 2 << (k - 1);}
inline vector <bool> dfs_visited_from(vector <vector <int>> graph, int cur,vector <bool> &visited){
    if (visited[cur]) return visited;
    visited[cur] = true;
    fca(u,graph[cur]){
        dfs_visited_from(graph,u,visited);
    }
    return visited;
}



inline void solve(){
    //алгоритм работает в натуральной системе отсчета, т.е. вершине 1 
    //сооствесвтует список с индексом 1, а не 0
    int n, to_h;
    cin >> n;cin.ignore();
    n++;
    vector <vector <int>> graph(n); // списки смежности
    vector <int> distance(graph.size());
    vector <bool> visited(graph.size());
    incr(i,1,n){
        while(cin.peek()!=nl){
            cin >> to_h;
            graph[i].push_back(to_h);
        }
        cin.ignore();
    }
    fca(a,dfs_visited_from(graph,1,visited)) cout << a << " "; cout <<nl;
    return;
}



int main()
{
    prepare();
    size_t tests;
    //cin >> tests;
    tests=1;
    for (int i = 0; i < tests;i++)
        solve();
    return 0;
}