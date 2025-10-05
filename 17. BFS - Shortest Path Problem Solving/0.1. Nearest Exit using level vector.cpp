class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int n = maze.size();
        int m = maze[0].size();

        // Fix 1: level grid must be n x m (not n x n)
        vector<vector<int>> level(n, vector<int>(m, -1));

        level[entrance[0]][entrance[1]] = 0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        while (!q.empty()) {
            pair<int, int> u = q.front(); 
            q.pop(); 
            int x = u.first; 
            int y = u.second; 

            // Fix 2: initialize i to 0
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.' && level[nx][ny] == -1) {
                    level[nx][ny] = level[x][y] + 1; 
                    
                    // Fix 3: correct boundary check (any edge) and exclude entrance
                    if ((nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) 
                        && (nx != entrance[0] || ny != entrance[1])) {
                        return level[nx][ny];  // Fix 4: return the step count
                    }

                    q.push({nx, ny});
                }
            } 
        }

        return -1; 
    }
};
