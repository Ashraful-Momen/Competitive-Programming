# Complete DFS Applications: Flood Fill, Islands & Provinces

## 🔹 Overview

This note covers **three fundamental DFS applications** that demonstrate how the same algorithm concept applies to different problem types:

1. **Flood Fill** - Change connected pixels of same color
2. **Number of Islands** - Count connected land components in grid
3. **Number of Provinces** - Count connected components in graph

**Core Concept:** All three problems use **DFS to explore connected components** but with different representations and goals.

---

## 🔹 Problem 1: Flood Fill (LeetCode 733)

### **Problem Statement**
Given a 2D image (matrix of colors), a starting pixel `(sr, sc)`, and a new color, change the color of the starting pixel and all connected pixels with the same original color to the new color.

### **Algorithm Intuition**
1. Start at `(sr, sc)` and remember its original color
2. Change current pixel to new color  
3. Recursively explore neighbors (up, down, left, right) that have the same original color
4. Continue until all connected pixels are changed

### **Implementation**

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int n, int m, int prevColor, int newColor, vector<vector<int>>& image) {
    // Change current pixel color
    image[x][y] = newColor;
    
    // Direction arrays: up, down, right, left
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Explore 4 neighbors
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Check bounds and same original color
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == prevColor) {
            dfs(nx, ny, n, m, prevColor, newColor, image);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    int prevColor = image[sr][sc];
    
    // Only start DFS if new color is different
    if (prevColor != color) {
        dfs(sr, sc, n, m, prevColor, color, image);
    }
    
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1, sc = 1, color = 2;
    
    cout << "Original image:" << endl;
    for (auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    
    cout << "After flood fill:" << endl;
    for (auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### **Dry Run Example**

**Input:**
```
image = [
  [1,1,1],
  [1,1,0],
  [1,0,1]
]
sr = 1, sc = 1, color = 2
```

**Step-by-step execution:**

Original image:
```
1 1 1
1 1 0
1 0 1
```

1. **Start DFS at (1,1):** prevColor = 1, change to 2
2. **Explore (0,1):** has color 1, change to 2, continue DFS
3. **Explore (0,0):** has color 1, change to 2
4. **Explore (0,2):** has color 1, change to 2
5. **Explore (1,0):** has color 1, change to 2
6. **Explore (2,0):** has color 1, change to 2

Final image:
```
2 2 2
2 2 0
2 0 1
```

### **DFS Tree Visualization**
```
Starting from (1,1):
         (1,1)
        /  |  \  \
   (0,1) (2,1) (1,0) (1,2)
    / \     X     \     X
(0,0)(0,2)       (2,0)
```
*X = boundary or different color (not explored)*

---

## 🔹 Problem 2: Number of Islands (LeetCode 200)

### **Problem Statement**
Given a 2D grid of `'1'` (land) and `'0'` (water), count the number of islands. An island is formed by connecting adjacent lands horizontally or vertically.

### **Algorithm Intuition**
1. Traverse every cell in the grid
2. When we find `'1'` (land), start DFS to explore the entire island
3. Mark visited land as `'#'` (or `'0'`) to avoid revisiting
4. Each DFS call represents one complete island
5. Count = number of DFS launches

### **Implementation**

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
    // Mark current cell as visited (sink the land)
    grid[x][y] = '#';
    
    // Direction arrays: up, down, right, left
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Explore 4 neighbors
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Check bounds and if it's land
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1') {
            dfs(nx, ny, n, m, grid);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;
    
    // Traverse every cell
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (grid[x][y] == '1') {
                islands++;                    // Found new island
                dfs(x, y, n, m, grid);       // Explore & sink entire island
            }
        }
    }
    
    return islands;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    
    cout << "Original grid:" << endl;
    for (auto& row : grid) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;
    
    return 0;
}
```

### **Dry Run Example**

**Input:**
```
grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]
```

**Step-by-step execution:**

1. **Island #1:** Start at (0,0)
   - DFS explores: (0,0) → (0,1) → (1,0) → (1,1)
   - Grid after: 
   ```
   # # 0 0 0
   # # 0 0 0
   0 0 1 0 0
   0 0 0 1 1
   ```

2. **Island #2:** Start at (2,2)
   - DFS explores: (2,2)
   - Grid after:
   ```
   # # 0 0 0
   # # 0 0 0
   0 0 # 0 0
   0 0 0 1 1
   ```

3. **Island #3:** Start at (3,3)
   - DFS explores: (3,3) → (3,4)
   - Final grid:
   ```
   # # 0 0 0
   # # 0 0 0
   0 0 # 0 0
   0 0 0 # #
   ```

**Result: 3 islands**

### **Visual Representation**
```
Original Islands:
■ ■ □ □ □    Island 1: Top-left 2x2 block
■ ■ □ □ □    Island 2: Single cell at (2,2)  
□ □ ■ □ □    Island 3: Bottom-right 1x2 block
□ □ □ ■ ■

■ = land ('1'), □ = water ('0')
```

---

## 🔹 Problem 3: Number of Provinces (LeetCode 547)

### **Problem Statement**
Given an adjacency matrix `isConnected` where `isConnected[i][j] = 1` means city i and city j are directly connected, find the number of provinces (connected components).

### **Algorithm Intuition**
1. Treat cities as graph nodes
2. Use adjacency matrix to find neighbors
3. For each unvisited city, start DFS to explore entire province
4. Mark all cities in the same province as visited
5. Count = number of DFS launches

### **Implementation**

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& isVisited, int n, vector<vector<int>>& isConnected) {
    // Mark current city as visited
    isVisited[u] = true;
    
    // Explore all connected cities
    for (int v = 0; v < n; v++) {
        if (isConnected[u][v] == 1 && !isVisited[v]) {
            dfs(v, isVisited, n, isConnected);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> isVisited(n, false);
    int provinces = 0;
    
    // Check every city
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            provinces++;                           // Found new province
            dfs(i, isVisited, n, isConnected);    // Explore entire province
        }
    }
    
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    cout << "Adjacency matrix:" << endl;
    for (auto& row : isConnected) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    int result = findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;
    
    return 0;
}
```

### **Dry Run Example**

**Input:**
```
isConnected = [
  [1,1,0],
  [1,1,0],
  [0,0,1]
]
```

**Graph visualization:**
```
City 0 ←→ City 1    City 2
   ↖_____↗           (isolated)
```

**Step-by-step execution:**

1. **Province #1:** Start with City 0 (unvisited)
   - DFS(0): visits City 0 → finds City 1 connected → DFS(1)
   - DFS(1): visits City 1 (no new unvisited connections)
   - Visited: [true, true, false]

2. **City 1:** Already visited, skip

3. **Province #2:** Start with City 2 (unvisited)
   - DFS(2): visits City 2 (no connections to other cities)
   - Visited: [true, true, true]

**Result: 2 provinces**

### **DFS Tree for Each Province**
```
Province 1:          Province 2:
   City 0                City 2
     |                     |
   City 1               (isolated)
```

---

## 🔹 Problem Comparison

| **Aspect** | **Flood Fill** 🎨 | **Number of Islands** 🏝️ | **Number of Provinces** 🏙️ |
|------------|-------------------|---------------------------|----------------------------|
| **Graph Type** | Grid (implicit) | Grid (implicit) | Graph (explicit) |
| **Nodes** | Pixels (x,y) | Cells (x,y) | Cities 0..n-1 |
| **Edges** | 4-directional neighbors | 4-directional neighbors | Adjacency matrix |
| **Goal** | Change connected colors | Count islands | Count provinces |
| **Marking** | Change to new color | Mark as '#' or '0' | visited[i] = true |
| **Output** | Modified image | Count of components | Count of components |
| **Complexity** | O(N×M) | O(N×M) | O(N²) |

---

## 🔹 Common Patterns

### **1. Grid DFS Template (Flood Fill & Islands)**
```cpp
void dfs(int x, int y, int n, int m, vector<vector<type>>& grid) {
    // Mark current cell (change color/mark visited)
    grid[x][y] = newValue;
    
    // Explore 4 directions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && condition) {
            dfs(nx, ny, n, m, grid);
        }
    }
}
```

### **2. Graph DFS Template (Provinces)**
```cpp
void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;
    
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, visited, adj);
        }
    }
}
```

### **3. Connected Components Counter Template**
```cpp
int countComponents() {
    int count = 0;
    // visited initialization
    
    for (each unvisited node/cell) {
        if (not visited) {
            count++;
            dfs(start_position);  // Explore entire component
        }
    }
    
    return count;
}
```

---

## 🔹 Real-World Applications

### **Flood Fill Applications:**
- **Image editing:** Paint bucket tool in Photoshop/GIMP
- **Game development:** Territory filling, area highlighting
- **Medical imaging:** Region growing in MRI/CT scans
- **Computer graphics:** Texture mapping, region selection

### **Islands Applications:**
- **Geographic analysis:** Counting actual islands in satellite imagery
- **Computer vision:** Object detection, blob analysis
- **Network analysis:** Isolated clusters detection
- **Game development:** Procedural map generation

### **Provinces Applications:**
- **Social networks:** Friend groups, community detection
- **Transportation:** Connected city networks
- **Computer networks:** Subnet analysis
- **Biology:** Gene interaction networks

---

## 🔹 Complexity Analysis

### **Time Complexity:**
- **Grid problems:** O(N×M) - each cell visited once
- **Graph problems:** O(N²) for adjacency matrix, O(N+E) for adjacency list

### **Space Complexity:**
- **Recursion stack:** O(N×M) for grid, O(N) for graph
- **Additional space:** O(1) if modifying input, O(N×M) or O(N) for separate visited array

---

## 🔹 Key Takeaways

✅ **Core Concept:** All three problems use **DFS to find connected components**

✅ **Different Representations:**
- **Grid:** Implicit graph with 4-directional connections
- **Adjacency Matrix:** Explicit graph with given connections

✅ **Same Algorithm Pattern:**
1. Start DFS from unvisited node/cell
2. Explore all reachable nodes/cells
3. Mark as visited/processed
4. Count number of DFS launches

✅ **Problem Variations:**
- **Flood Fill:** Modify connected region
- **Islands/Provinces:** Count connected components

This foundation prepares you for countless similar problems involving connected components, graph traversal, and region analysis!
