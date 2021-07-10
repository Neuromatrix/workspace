#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
#define fca(a,s) for (const auto & a: s)
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



int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}

inline pair<vector <bool>,vector <int>> bfs_distance_from(vector<vector<int>> graph, int cur){
    queue <int> q;
    vector <int> distance(graph.size());
    vector <bool> visited(graph.size());
    distance[cur] = 0;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty()){
        cur = q.front();
        q.pop();
        fca(u,graph[cur]){ // проход по всем вершинам в которые  ведут ребра
            if(visited[u]) continue; // вершина посещена
            visited[u] = true; 
            distance[u] = distance[cur] + 1; // расстояние для вершины в которую ведут ребра cur увеличиваем
            q.push(u); 
        }
    }
    return {visited, distance};
}
inline void solve(){
    //алгоритм работает в натуральной системе отсчета, т.е. вершине 1 
    //сооствесвтует список с индексом 1, а не 0
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
    pair <vector <bool> , vector<int>> x= bfs_distance_from(graph,1);

    fca(a, x.first) cout << a << " ";cout << nl; // посещены ли все деревья
    fca(a, x.second) cout << a << " ";cout << nl; // расстояние от вершины (1) до отсальных вершин
    return;
}
int main(){
    prepare();
    solve();
    return 0;
}














