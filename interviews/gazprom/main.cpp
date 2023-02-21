#include <iostream>
#include <vector>
#include <queue>
/// @brief check, thath cells is available
/// @param x string number
/// @param y raw number
/// @param n size(strings)
/// @param m size(raws)
/// @param cells matrix of boolean values, where 1 - is visited, 0 - available
/// @return true if avalable
inline bool cell_valid(const int &x, const int &y, const int &n, const int &m, const std::vector <std::vector <bool>> &cells){
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    if(cells[x][y]) return false;
    return true;
}

/// @brief return sum of digits of number
inline int sum_of_digits(int var){
    int digit_sum_of_var = 0;
    while (var > 0){
        digit_sum_of_var += var%10;
        var /= 10;
    }
    return digit_sum_of_var;
}

/// @brief dfs in  a matrix to count the number of vertices available from this
/// @param x string number
/// @param y raw number
/// @param n size(strings)
/// @param m size(raws)
/// @param cells matrix of boolean values, where 1 - is visited, 0 - available
/// @param moves possible coordinate changes
/// @return count available vertexes
inline int bfs(int sx, int sy, const int &n, const int &m, std::vector <std::vector <bool>> &cells, const std::vector <std::pair <int,int>> &moves){
	std::queue<std::pair<int,int>> q;
    int ans = 0;
	q.push({sx,sy});
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(const auto &mv: moves){
			int mvx = mv.first;
			int mvy = mv.second;
			if(cell_valid(cx+mvx, cy+mvy, n, m, cells)){
                cells[cx+mvx][cy+mvy] = 1;
				q.push({cx+mvx, cy+mvy});
                ans++;
			}
		}
	}
    return ans;
}


int main(int argc, char** argv){
    int n = 2001, m = 2001;
    std::vector <std::vector<bool>> cells(n,std::vector<bool>(m,0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cells[i][j] = (sum_of_digits(i)+sum_of_digits(j)) > 25; // out of reach
        }
    }
    std::vector <std::pair <int,int>> moves = {{0,-1},{0,1},{1,0},{-1,0}};
    std::cout << bfs(1000, 1000, n, m, cells,moves) << std::endl;
    return 0;
}
