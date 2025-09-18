# Complete DFS (Depth First Search) Reference Note

## 🔹 What is DFS?

**Depth First Search (DFS)** is a graph traversal algorithm that:
- Goes **as deep as possible** along each branch before backtracking
- Uses **recursion** or **stack** to explore nodes
- Marks visited nodes to avoid infinite loops
- Time Complexity: **O(V + E)** where V = vertices, E = edges

---

## 🔹 Two Main Implementations

### 1. **Grid/Matrix DFS** (2D Array Traversal)
Used for: Island problems, maze solving, flood-fill, connected regions

```cpp
#include <bits/stdc++.h>
using namespace std;

// Direction arrays: top, bottom, right, left
int dx[] = {-1, 1, 0, 0};  // Row movements
int dy[] = {0, 0, 1, -1};  // Column movements

void dfs(int x, int y, int n, int m, vector<vector<bool>>& isVisited, vector<vector<int>>& grid)
{
    // Step 1: Mark current cell as visited
    isVisited[x][y] = true;
    
    // Step 2: Explore all 4 directions
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];  // New row
        int ny = y + dy[i];  // New column
        
        // Check boundaries and conditions
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && 
            grid[nx][ny] == 1 && !isVisited[nx][ny])
        {
            dfs(nx, ny, n, m, isVisited, grid);
        }
    }
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1}
    };
    
    int n = grid.size();     // Number of rows
    int m = grid[0].size();  // Number of columns
    
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    
    // Start DFS from top-left corner (0,0)
    dfs(0, 0, n, m, isVisited, grid);
    
    return 0;
}
```

### 2. **Graph DFS** (Adjacency List)
Used for: General graph problems, trees, networks

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];  // Adjacency list (max 100 nodes)

void dfs(int u, vector<bool>& isVisited)
{
    // Step 1: Mark current node as visited
    isVisited[u] = true;
    cout << u << " ";  // Print traversal order
    
    // Step 2: Visit all unvisited neighbors
    for (auto v : adj[u])
    {
        if (!isVisited[v])
        {
            dfs(v, isVisited);
        }
    }
}

int main()
{
    int n, m;  // n = nodes, m = edges
    cin >> n >> m;
    
    // Input edges and build adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }
    
    vector<bool> isVisited(n + 1, false);
    
    cout << "DFS Traversal: ";
    dfs(1, isVisited);  // Start from node 1
    
    return 0;
}
```

---

## 🔹 Direction Arrays Explanation

### Grid Movement Patterns:
```cpp
int dx[] = {-1, 1, 0, 0};  // Row changes
int dy[] = {0, 0, 1, -1};  // Column changes

// Movement meanings:
// i=0: dx=-1, dy=0  → Move UP    (row-1, col)
// i=1: dx=1,  dy=0  → Move DOWN  (row+1, col)  
// i=2: dx=0,  dy=1  → Move RIGHT (row, col+1)
// i=3: dx=0,  dy=-1 → Move LEFT  (row, col-1)
```

### Visual Grid Movement:
```
    (x-1, y)  ↑ UP
(x, y-1) ← (x,y) → (x, y+1)
    (x+1, y)  ↓ DOWN
```

---

## 🔹 Real-World Applications

### **1. Grid/Matrix Problems:**
- **Count Islands:** Find number of connected land masses in a map
- **Maze Solving:** Find path from start to end
- **Flood Fill:** Paint bucket tool in graphics software
- **Region Connectivity:** Find connected areas in images

### **2. Graph Problems:**
- **Social Networks:** Find friend groups/communities
- **Network Routing:** Find paths between computers
- **Dependency Resolution:** Solve package dependencies
- **Cycle Detection:** Find circular dependencies

### **3. Tree Algorithms:**
- **Tree Traversal:** Preorder, Inorder, Postorder
- **Path Finding:** Root to leaf paths
- **Subtree Problems:** Calculate subtree sizes

---

## 🔹 Sample Execution

### Grid DFS Example:
```
Input Grid:
1 1 0 1
0 1 0 1
1 1 1 0
1 1 0 1

Starting from (0,0):
Step 1: Visit (0,0) → value=1 ✓
Step 2: Visit (0,1) → value=1 ✓  
Step 3: Visit (1,1) → value=1 ✓
Step 4: Visit (2,1) → value=1 ✓
Step 5: Visit (2,2) → value=1 ✓
Step 6: Visit (2,0) → value=1 ✓
Step 7: Visit (3,0) → value=1 ✓
Step 8: Visit (3,1) → value=1 ✓

Result: All connected 1s starting from (0,0) are visited
```

### Graph DFS Example:
```
Input:
6 5
1 2
1 3  
2 4
2 5
3 6

Graph Structure:
     1
   /   \
  2     3
 / \     \
4   5     6

DFS Traversal from node 1: 1 → 2 → 4 → 5 → 3 → 6
```

---

## 🔹 Key Concepts

### **Boundary Checking (Grid DFS):**
```cpp
if (nx >= 0 && ny >= 0 && nx < n && ny < m)
```
- `nx >= 0, ny >= 0`: Prevent negative indices
- `nx < n, ny < m`: Stay within grid bounds

### **Visited Array:**
```cpp
vector<vector<bool>> isVisited(n, vector<bool>(m, false));  // For grid
vector<bool> isVisited(n + 1, false);                      // For graph
```
- Prevents infinite loops
- Tracks explored nodes/cells

### **Recursive Nature:**
- Each DFS call explores one node/cell
- Recursion handles the "depth-first" exploration
- Backtracking happens automatically when recursion returns

---

## 🔹 Common Variations

### **1. Count Connected Components:**
```cpp
int countComponents(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, n, m, visited, grid);
                components++;
            }
        }
    }
    return components;
}
```

### **2. Path Exists Check:**
```cpp
bool pathExists(int start, int end, vector<bool>& visited) {
    if (start == end) return true;
    
    visited[start] = true;
    for (auto neighbor : adj[start]) {
        if (!visited[neighbor]) {
            if (pathExists(neighbor, end, visited)) {
                return true;
            }
        }
    }
    return false;
}
```

### **3. Find All Paths:**
```cpp
void findAllPaths(int current, int target, vector<int>& path, vector<vector<int>>& allPaths, vector<bool>& visited) {
    path.push_back(current);
    visited[current] = true;
    
    if (current == target) {
        allPaths.push_back(path);
    } else {
        for (auto neighbor : adj[current]) {
            if (!visited[neighbor]) {
                findAllPaths(neighbor, target, path, allPaths, visited);
            }
        }
    }
    
    // Backtrack
    path.pop_back();
    visited[current] = false;
}
```

---

## 🔹 Time & Space Complexity

### **Grid DFS:**
- **Time:** O(n × m) - visit each cell once
- **Space:** O(n × m) - for visited array + recursion stack

### **Graph DFS:**
- **Time:** O(V + E) - visit each vertex and edge once
- **Space:** O(V) - for visited array + recursion stack

---

## 🔹 Common Mistakes & Tips

### **❌ Common Mistakes:**
1. **Index out of bounds:** Always check `nx >= 0 && nx < n`
2. **Infinite loops:** Forget to mark nodes as visited
3. **Wrong direction arrays:** Mix up dx/dy values
4. **Global visited array:** Reuse without resetting

### **✅ Pro Tips:**
1. **Use references:** `vector<bool>& visited` to avoid copying
2. **Early termination:** Return when target found
3. **Memory optimization:** Use bitset for large grids
4. **Iterative DFS:** Use explicit stack for deep recursion

---

## 🔹 Practice Problems

### **Beginner:**
- Number of Islands (LeetCode 200)
- Flood Fill (LeetCode 733)
- Connected Components (various platforms)

### **Intermediate:**
- Word Search (LeetCode 79)
- Course Schedule (LeetCode 207)
- Clone Graph (LeetCode 133)

### **Advanced:**
- Largest Island (LeetCode 827)
- Critical Connections (LeetCode 1192)
- Word Ladder (LeetCode 127)

---

## 🔹 Summary

DFS is a fundamental algorithm with two main forms:
1. **Grid DFS:** Perfect for 2D matrix problems
2. **Graph DFS:** Essential for general graph traversal

**Key takeaway:** Master both implementations as they form the foundation for countless algorithmic problems in competitive programming and real-world applications.
