#include <bits/stdc++.h>
using namespace std;

// top, buttom , right , left. x => row , y => comlumn as like the graph x axis and y axis. 

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


// x = row , y = col , n = node , m = edage , & isVisited recevice the graph  isVisited (another graph , if node visited then assign with 1) ,  & grid = recevice the graph by address
void dfs(int x, int y, int n, int m, vector<vector<bool>>& isVisited, vector<vector<int>>& grid)
{


    // step 1 : assign the node 1 as visited  
    isVisited[x][y] = 1;

    //top, bottom , right , left : that why loop working => 4
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];  // x = 0, nx = 0     // if x+ => goto bottom row , x- then goto upper row
        int ny = y + dy[i];  // y = 0, ny = 1     // if y+ => goto right column , y- then goto left col


        // we can't visit -x or -y cause in the matrix -x(row) or -y(col) is not exit , so nx and ny >= 0. 
        // nx and ny value must be lower then node (n) and  edage(m) 
        // if isVisited[nx][ny] is not visited mean isVisited[nx][ny] != 1 then goto recursive call for depth. 
      
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !isVisited[nx][ny])
        {

            // if upper conditions is full-filled then call recursively depth to depth 
            dfs(nx, ny, n, m, isVisited, grid);
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 0, 1}};

    int n = grid.size(); // grid.size => row value => 4
    int m = grid[0].size(); // grid[0] first row => gird[0].size => column size.

    vector<vector<bool>> isVisited(n, vector<bool>(m, 0));

    dfs(0, 0, n, m, isVisited, grid);

    return 0;
}


//-----------------------------------------------
// vector<int> adj[100];

// void dfs(int u, vector<bool>& isVisited)
// {
//     isVisited[u] = true;

//     for (auto v : adj[u])  
//     {
//         if (!isVisited[v])
//         {
//             dfs(v, isVisited);
//         }
//     }
// }
