class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        //  find the nearest exit from the entrance
        //  return the number of steps : level 
        //  if not enterence exist return 0
        
        // grid so the dx, dy given into the 4 dimention . 

        int dx[] = {1,-1,0,0};
        int dy[]= {0,0,1,-1};

        int n = maze.size();
        int m = maze[0].size();

        maze[entrance[0]][entrance[1]] = '+';

        //source note : enternce => [0,0]
        vector<vector<int>>level (n, vector<int>(m,-1));

        level[entrance[0]][entrance[1]] = 0;

        queue<pair<int,int>> q ; 
        q.push({entrance[0],entrance[1]});

        while(!q.empty()){

            pair<int, int> u = q.front(); q.pop(); 
            int x = u.first; 
            int y = u.second; 

            for (int i =0 ; i < 4 ; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.' && level[nx][ny] == -1 )
                {
                    level[nx][ny] = level[x][y] +1; 
                    
                    //check the boundary | here x = 0, y = 0 is the first boundary and n-1 and m-1 is the last boundary .  

                    if ((nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) && (nx != entrance[0] || ny != entrance[1])) {
                            return level[nx][ny];
                        }

                    q.push({nx,ny});
                }
            
            } 

        }

        return -1; 

        
    }
};
