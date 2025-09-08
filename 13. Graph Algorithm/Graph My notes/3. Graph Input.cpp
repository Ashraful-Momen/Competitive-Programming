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
