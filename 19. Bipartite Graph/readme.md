Nice — I separated and cleaned up your three algorithms into three complete, self-contained C++ programs (each has its own `main`). I removed shorthand macros (`PB`, `mem`, `optimize`) and used clear, standard C++17 so you can compile with `g++ -std=c++17 file.cpp -O2`. After each code block I added short notes: what it does, how indexing works, complexity, and important edge cases.

---

# 1) Bipartite check — **DFS** (with `main`)

```cpp
// bipartite_dfs.cpp
#include <bits/stdc++.h>
using namespace std;

// DFS helper to color the graph. clr is 1 or 2
void dfs_color(int u, int clr, bool &isBipartite, vector<int> &color, const vector<vector<int>> &adj) {
    color[u] = clr;
    for (int v : adj[u]) {
        if (color[v] == 0) {
            dfs_color(v, (clr == 1) ? 2 : 1, isBipartite, color, adj);
        } else if (color[v] == color[u]) {
            isBipartite = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read graph: n nodes and m edges (1-based nodes). Adjust to 0-based internally if you want.
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1); // 1-based indexing
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, 0); // 0 = uncolored, 1 and 2 are colors
    bool isBipartiteFlag = true;

    // handle disconnected graph: run DFS from every uncolored node
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            dfs_color(i, 1, isBipartiteFlag, color, adj);
        }
    }

    cout << (isBipartiteFlag ? "Graph is Bipartite\n" : "Graph is NOT Bipartite\n");
    return 0;
}
```

Notes for DFS bipartite:

* Indexing: code uses **1-based nodes** (`adj` size is `n+1`). If your input is 0-based, change loops and sizes accordingly.
* Works on disconnected graphs by iterating all nodes in `main`.
* Time complexity: O(n + m). Space: O(n) for `color` and recursion stack (possible O(n) depth).
* Recursion depth: for very large graphs (n up to ~1e5) you may hit recursion limits — switch to iterative DFS or BFS if that is a concern.

---

# 2) Bipartite check — **BFS** (with `main`)

```cpp
// bipartite_bfs.cpp
#include <bits/stdc++.h>
using namespace std;

bool isBipartiteBFS(const vector<vector<int>> &adj, int n) {
    vector<int> color(n + 1, 0); // 1-based
    for (int i = 1; i <= n; ++i) {
        if (color[i] != 0) continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            int nextColor = (color[u] == 1) ? 2 : 1;
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = nextColor;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = isBipartiteBFS(adj, n);
    cout << (ans ? "Graph is Bipartite\n" : "Graph is NOT Bipartite\n");
    return 0;
}
```

Notes for BFS bipartite:

* BFS is iterative and avoids recursion-depth problems.
* Also handles disconnected graphs by starting BFS from every uncolored node.
* Time: O(n + m). Space: O(n) for `color` and queue.
* BFS may be preferable for very deep graphs where recursion would overflow.

---

# 3) Cycle detection & printing one cycle — **Undirected graph** (with `main`)

This version correctly detects a cycle in an undirected graph and prints the cycle nodes in order. I fixed the standard parent/back-edge logic and the cycle reconstruction.

```cpp
// cycle_detection_undirected.cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parentVec;
vector<char> visited; // 0 = unvisited, 1 = visited
int cycleStart = -1, cycleEnd = -1;

void dfs_find_cycle(int u, int p) {
    visited[u] = 1;
    parentVec[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue; // skip the edge to parent in undirected graph
        if (!visited[v]) {
            dfs_find_cycle(v, u);
            if (cycleStart != -1) return; // early stop if cycle found
        } else {
            // visited and v != parent -> found a cycle (back-edge)
            cycleStart = v;
            cycleEnd = u;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parentVec.assign(n + 1, -1);
    visited.assign(n + 1, 0);

    // For disconnected graphs we must try every component
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs_find_cycle(i, -1);
            if (cycleStart != -1) break;
        }
    }

    if (cycleStart == -1) {
        cout << "Cycle does not exist\n";
    } else {
        // Reconstruct cycle path from cycleEnd back to cycleStart using parentVec
        vector<int> cycle;
        int cur = cycleEnd;
        cycle.push_back(cur);
        while (cur != cycleStart) {
            cur = parentVec[cur];
            cycle.push_back(cur);
        }
        // Optional: reverse to print from cycleStart -> ... -> cycleEnd -> cycleStart
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Exists. One cycle (nodes in order):\n";
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
```

Notes for cycle detection:

* This is for **undirected** graphs.
* Indexing: **1-based** nodes. If input is 0-based, change sizes and loops.
* Important fix from your snippet: when an already-visited `v` is found and `v != parent[u]`, set `cycleStart = v` and `cycleEnd = u` and then reconstruct the path from `cycleEnd` to `cycleStart` following `parent`.
* The code tries every node to handle disconnected graphs.
* Time: O(n + m). Space: O(n).
* This finds **one** simple cycle (not all cycles). The printed cycle goes from `cycleStart` → ... → `cycleEnd` (as returned above). If you want to include the `cycleStart` at the end again (to show closure), you can print it once more.

---

## Quick usage tips

* Compile each file separately: `g++ -std=c++17 bipartite_dfs.cpp -O2 -o bip_dfs`
* Input format expected: first line `n m`, then `m` lines with edges `u v` (undirected).
* If your graph nodes are 0-based (0..n-1) change the containers to size `n` and loops to `0..n-1`.
* For very large graphs (n≈1e5) prefer BFS or iterative DFS (stack) to avoid recursion depth problems.

---

If you want, I can:

* Convert these to 0-based indexing versions,
* Provide iterative DFS versions (no recursion),
* Add example inputs + expected outputs,
* Or merge bipartite and cycle-check into a single utility program with a menu.

Which of those would be most helpful next?
