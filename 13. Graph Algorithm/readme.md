# Complete Graph Representations Guide

## 🔹 Overview

Graphs can be represented in **two main ways**:

1. **Adjacency Matrix** → 2D array/matrix (row, col)
2. **Adjacency List** → Each node stores its neighbor nodes

**Key Decision:** Choose based on graph density and operations needed.

---

## 🔹 1. Adjacency Matrix

### **Concept:**
- **2D array** where `matrix[i][j] = 1` means edge exists between node i and node j
- **Symmetric matrix** for undirected graphs
- **Fixed size:** Always `n × n` regardless of edge count

### **Implementation 1: Static Array**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Static array - fixed maximum size
    int adj[1001][1001] = {0};  // Initialize all to 0

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;   // Edge from u to v
        adj[v][u] = 1;   // Edge from v to u (undirected)
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### **Implementation 2: Dynamic Vector (Memory Efficient)**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Dynamic 2D vector - allocates only needed memory
    vector<vector<int>> adj(nodes + 1, vector<int>(nodes + 1, 0));

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;   // Edge from u to v
        adj[v][u] = 1;   // Edge from v to u (undirected)
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### **Example Input/Output:**

**Input:**
```
5 6
1 2
1 3
2 4
3 4
4 5
2 5
```

**Output:**
```
Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 1 0 
0 1 1 0 1 
0 1 0 1 0 
```

**Visual Representation:**
```
Graph:     1 ---- 2 ---- 5
           |      |     /
           |      |    /
           3 ---- 4 ---
```

---

## 🔹 2. Adjacency List

### **Concept:**
- **Array of lists** where `adj[i]` contains all neighbors of node i
- **Variable size:** Only stores existing edges
- **Memory efficient** for sparse graphs

### **Implementation 1: Basic Adjacency List**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Create adjacency list with nodes+1 empty vectors
    vector<vector<int>> adj(nodes + 1);

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // Add v to u's neighbor list
        adj[v].push_back(u);   // Add u to v's neighbor list (undirected)
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= nodes; i++) {
        cout << "Node " << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if (j < adj[i].size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### **Implementation 2: Detailed Version with User-Friendly Input**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodes, edges;
    
    cout << "Enter number of nodes: ";
    cin >> nodes;

    // Create adjacency list with nodes+1 empty rows
    // Why nodes+1? → To allow 1-based indexing (node 1 to node N)
    vector<vector<int>> adj(nodes + 1);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;   // Read connected nodes

        // Add edge in both directions (undirected graph)
        adj[u].push_back(v);   // v is neighbor of u
        adj[v].push_back(u);   // u is neighbor of v
    }

    cout << "\n--- Adjacency List ---" << endl;
    for (int i = 1; i <= nodes; i++) {        // Loop from node 1 to node 'nodes'
        cout << "Node " << i << " -> ";       
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if (j < adj[i].size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### **Implementation 3: Optimized I/O Version**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // Speed up I/O
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n = nodes, m = edges

    vector<vector<int>> adj(n + 1);  // 1-indexed adjacency list

    // Read exactly m edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Add v to u's neighbors
        adj[v].push_back(u);  // Add u to v's neighbors (undirected)
    }

    // Output adjacency list
    for (int u = 1; u <= n; ++u) {
        cout << u << ":";
        for (int v : adj[u]) {  // Range-based for loop
            cout << " " << v;
        }
        cout << "\n";
    }

    return 0;
}
```

### **Example Input/Output:**

**Input:**
```
4 3
1 2
2 3
3 4
```

**Output:**
```
1: 2
2: 1 3
3: 2 4
4: 3
```

**Visual Representation:**
```
Graph:  1 ---- 2 ---- 3 ---- 4

Adjacency List:
1 → [2]
2 → [1, 3]
3 → [2, 4]  
4 → [3]
```

---

## 🔹 Comparison: Matrix vs List

| **Aspect** | **Adjacency Matrix** | **Adjacency List** |
|------------|---------------------|-------------------|
| **Space Complexity** | O(V²) | O(V + E) |
| **Check if edge exists** | O(1) | O(degree) |
| **Add edge** | O(1) | O(1) |
| **Remove edge** | O(1) | O(degree) |
| **Get all neighbors** | O(V) | O(degree) |
| **Best for** | Dense graphs | Sparse graphs |
| **Memory usage** | High (always V²) | Low (only existing edges) |

---

## 🔹 When to Use Which?

### **Use Adjacency Matrix when:**
- **Dense graphs** (many edges, E ≈ V²)
- **Frequent edge existence queries** (is there edge between u and v?)
- **Small graphs** (V ≤ 1000)
- **Need fast edge lookup** O(1)

### **Use Adjacency List when:**
- **Sparse graphs** (few edges, E << V²)
- **Large graphs** (V > 2000)
- **Memory is limited**
- **Need to iterate through neighbors frequently**
- **Most competitive programming problems**

---

## 🔹 Directed vs Undirected Graphs

### **Undirected Graph (Bidirectional):**
```cpp
// Add edge in both directions
adj[u].push_back(v);
adj[v].push_back(u);

// Matrix: both adj[u][v] = 1 and adj[v][u] = 1
```

### **Directed Graph (One Direction):**
```cpp
// Add edge only from u to v
adj[u].push_back(v);

// Matrix: only adj[u][v] = 1
```

---

## 🔹 Weighted Graphs

### **Adjacency Matrix (Weighted):**
```cpp
vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
adj[u][v] = weight;  // Store weight instead of 1
```

### **Adjacency List (Weighted):**
```cpp
vector<vector<pair<int, int>>> adj(n + 1);  // {neighbor, weight}
adj[u].push_back({v, weight});
```

---

## 🔹 Common Operations

### **1. Check if Edge Exists:**
```cpp
// Matrix
bool hasEdge = (adj[u][v] == 1);

// List
bool hasEdge = find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
```

### **2. Get All Neighbors:**
```cpp
// Matrix
for (int v = 1; v <= n; v++) {
    if (adj[u][v] == 1) {
        cout << v << " ";  // v is neighbor of u
    }
}

// List
for (int v : adj[u]) {
    cout << v << " ";  // v is neighbor of u
}
```

### **3. Count Degree of Node:**
```cpp
// Matrix
int degree = 0;
for (int v = 1; v <= n; v++) {
    if (adj[u][v] == 1) degree++;
}

// List
int degree = adj[u].size();
```

---

## 🔹 Memory Analysis

### **Example: Graph with 1000 nodes, 5000 edges**

**Adjacency Matrix:**
- Memory: 1000 × 1000 × 4 bytes = **4 MB**
- Actual edges stored: 5000
- Wasted space: 995,000 zeros

**Adjacency List:**
- Memory: 5000 × 2 × 4 bytes = **40 KB**
- Only actual edges stored
- 100× more memory efficient!

---

## 🔹 Template Code for Competitive Programming

### **Quick Adjacency List Setup:**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Remove for directed graph
    }
    
    // Your graph algorithms here...
    
    return 0;
}
```

---

## 🔹 Summary

**Bottom Line:**
- **Adjacency List** is preferred for most problems (90% of cases)
- **Adjacency Matrix** for dense graphs or frequent edge queries
- **Vector implementation** is more flexible than static arrays
- **1-based indexing** is common in competitive programming

**Memory Rule of Thumb:**
- If E > V²/2, consider adjacency matrix
- If E < V²/4, definitely use adjacency list
- When in doubt, use adjacency list

This foundation will serve you well for all graph algorithms including DFS, BFS, shortest paths, and more!
