# Graph can represent by two way : 
-----------------------------------
1. Adjecency Matrix (normal matrix => row , col)
2. Adjececny List (Every node represent it's neighbour nodes, 1 -> 1,2,3 ; 2 -> 1, 4 ; .....)
3. we can use normal 2D array or adjecency list with vector or without vector.

-----------------------------------------------------------------------------------------------



# 1. Adjecency Matrix => Normal matrix input and output of the graph : 
-----------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;   // first read row and col

    int arr[1000][1000]; // static array with safe max size

    // Matrix Input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is:\n";

    // Matrix Output
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


#------------------ same code with the vector for memory efficient ---------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main(){

    int row,col;
    cin >> row >>col;

    vector<vector <int>> arr(row, vector <int>(col));

     // Matrix Input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is:\n";

    // Matrix Output
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }





    return 0;
}



### Input

```
5 6
1 2
1 3
2 4
3 4
4 5
2 5
```

### ✅ Output

```
Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 1 0 
0 1 1 0 1 
0 1 0 1 0 
```

---

⚡ Notes:

* `int adj[1001][1001];` → can store up to `n = 1000`.
* For **bigger graphs (n > 2000)**, adjacency matrix is **too memory heavy** (`O(n²)`), so use **adjacency list** instead.
* For **weighted graphs**, instead of `0/1`, store weight values (e.g., `adj[u][v] = w`).

----------------------------------------------------------------------------------------------------------------


# 2 Adjecency List for graph:
-----------------------------


#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // adjacency matrix initialized with 0
    vector<vector<int>> graph(nodes + 1, vector<int>(nodes + 1, 0));

    //

    // input edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;   // edge from u -> v
        graph[v][u] = 1;   // if undirected graph
    }

    

    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


-------------- same code with different expample : adjececny list -----------------------------


#include <iostream>
#include <vector>        // Required for vector
using namespace std;     // Avoid writing std:: every time

int main() {
    // STEP 1: Declare variables for nodes and edges
    int nodes, edges;
    
    // STEP 2: Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> nodes;  // e.g., if nodes = 4, we'll handle nodes 0,1,2,3,4 (if 1-based)

    // STEP 3: Create adjacency list with nodes+1 empty rows
    // Why nodes+1? → To allow 1-based indexing (node 1 to node N) OR to include node 0 to N
    vector<vector<int>> adj(nodes + 1);  // Creates (nodes+1) empty vector<int>s

    // STEP 4: Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // STEP 5: Input each edge and build the graph
    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;   // Read connected nodes

        // Add edge in both directions (undirected graph)
        adj[u].push_back(v);   // v is neighbor of u
        adj[v].push_back(u);   // u is neighbor of v
    }

    // STEP 6: Output the adjacency list
    cout << "\n--- Adjacency List ---" << endl;
    for (int i = 0; i <= nodes; i++) {        // Loop from node 0 to node 'nodes'
        cout << "Node " << i << " -> ";       // Print node label
        for (int j = 0; j < adj[i].size(); j++) {  // Loop through all neighbors
            cout << adj[i][j];                // Print neighbor
            if (j < adj[i].size() - 1) cout << " "; // Space between, no space at end
        }
        cout << endl;  // New line after each node's list
    }

    return 0;  // End of program
}


### 🖥️ Input:


Input:
```
Enter number of nodes: 4
Enter edges:
1 2
2 3
3 4
```

Output:
```
Node 1 -> 2
Node 2 -> 1 3
Node 3 -> 2 4
Node 4 -> 3
```

✅ Works perfectly! Index 0 remains empty — no problem.

---

# ✅ VISUAL REPRESENTATION

For input:
```
Nodes: 4
Edges: 0-1, 0-2, 1-3, 2-4
```

Graph:
```
    0
   / \
  1   2
  |   |
  3   4
```

Adjacency List:
```
0 → [1, 2]
1 → [0, 3]
2 → [0, 4]
3 → [1]
4 → [2]
```

-------------------------------- same code : adjecency list another expample for ' output code' different just ----------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // speed up IO
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;                   // 1) read number of nodes (n) and edges (m)

    vector<vector<int>> adj(n + 1);  // 2) adjacency list, 1-indexed: adj[1]..adj[n]
                                     // use vector<vector<int>> adj(n); for 0-indexed nodes

    // 3) Read edges (repeat exactly m times because each input line describes one edge)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;               // read the endpoints of the i-th edge
        // optional input validation could be: if(u<1||u>n||v<1||v>n) handle_error();

        adj[u].push_back(v);         // add v to u's neighbor list
        adj[v].push_back(u);         // add u to v's neighbor list (comment out for directed graph)
    }

    // 4) Output adjacency list
    for (int u = 1; u <= n; ++u) {   // iterate nodes 1..n (outer loop dependent on number of nodes)
        cout << u << ":";           // print node label
        for (int v : adj[u]) {      // inner loop iterates over neighbors of u (dependent on degree of u)
            cout << " " << v;       // print each neighbor
        }
        cout << "\n";
    }

    return 0;
}
