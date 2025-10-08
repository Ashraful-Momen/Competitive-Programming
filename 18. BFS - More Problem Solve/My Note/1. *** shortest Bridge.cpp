//Leetcode 934

// in the grid we have 2 component which is locate by 1 (earth). 
// all the node is 0. 
// modify minimum 0 to 1 to make the shortest bridge from one component to another component. 

//solve: _________________________

// mark all the node as 2 with dfs algorithm
// after complete to modify first component all node as 2 then , true the 'done' varibale.  that make sure all the 1st connected component modified with 2. 
// run the multi level bfs from each of nodes 
// max path is ans (n*n) . row x col
// inside the bfs increase the level for per node and mark them as 2 for . cz bfs running without nodes 2. 
// ans always store the minimum path in ans( min(ans,nextLevel))

// minimum how much 0 have to convert 1 to reach next component is => ans or return -1. 




class Solution {
public:

    void dfs( int x, int y, int n, vector<vector<int>>& grid ) {
        grid[x][y] = 2;

        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        for ( int i = 0; i < 4; i++ ) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if ( nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1 ) {
                dfs( nx, ny, n, grid );
            }
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        int n = grid.size();

        bool done = false;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] == 1 ) {
                    dfs ( i, j, n, grid );
                    done = true;
                    break;
                }
            }

            if(done) break;
        }

        queue<vector<int>> q;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] == 2 ) {
                    q.push({i, j, 0});
                }
            }
        }

        int ans = (n * n);
        while (!q.empty()) {
            vector<int> u = q.front();
            q.pop();

            int x = u[0];
            int y = u[1];
            int curLevel = u[2];

            for ( int i = 0; i < 4; i++ ) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if ( nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 2 ) {
                    int nextLevel = curLevel + 1;
                    if ( grid[nx][ny] == 1 ) ans = min ( ans, nextLevel );
                    grid[nx][ny] = 2;
                    q.push({ nx, ny, nextLevel });
                }
            }
        }

        return ans - 1;
    }
};
