# C++ STL Ultimate ICPC Cheat Sheet 🚀

## Essential Headers & Namespace
```cpp
#include <bits/stdc++.h>  // Everything (ICPC standard)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
```

## 🔥 CONTAINERS - The Big 7

### 1. VECTOR - Dynamic Array
```cpp
vector<int> v = {1,2,3};
v.pb(4); v.pop_back();           // Add/remove back: O(1)
v.insert(v.begin()+2, 99);       // Insert at pos: O(n)
v.erase(v.begin()+1);            // Erase at pos: O(n)
sort(all(v)); reverse(all(v));   // Sort/reverse: O(nlogn)/O(n)
bool found = binary_search(all(v), 3);  // Binary search: O(logn)
```

### 2. STRING - Character Array++
```cpp
string s = "hello";
s += "world"; s.pb('!');         // Concatenation
s.substr(1, 3);                  // Substring from pos 1, len 3
s.find("lo");                    // Find substring (returns pos or npos)
transform(all(s), s.begin(), ::tolower);  // To lowercase
```

### 3. DEQUE - Double-ended Queue
```cpp
deque<int> dq;
dq.push_front(1); dq.push_back(2);   // Both ends: O(1)
dq.pop_front(); dq.pop_back();       // Both ends: O(1)
```

### 4. STACK - LIFO
```cpp
stack<int> st;
st.push(1); st.pop();            // Push/pop: O(1)
int top = st.top();              // Access top: O(1)
bool empty = st.empty();
```

### 5. QUEUE - FIFO
```cpp
queue<int> q;
q.push(1); q.pop();              // Push/pop: O(1)
int front = q.front();           // Access front: O(1)
```

### 6. PRIORITY_QUEUE - Heap
```cpp
priority_queue<int> pq;          // Max heap (default)
priority_queue<int, vector<int>, greater<int>> pq; // Min heap
pq.push(5); pq.pop();            // Push/pop: O(logn)
int top = pq.top();              // Access max/min: O(1)
```

### 7. SET/MULTISET - Balanced BST
```cpp
set<int> s; multiset<int> ms;    // Unique/Allow duplicates
s.insert(5); s.erase(5);         // Insert/erase: O(logn)
auto it = s.find(5);             // Find: O(logn)
auto lb = s.lower_bound(3);      // First >= 3: O(logn)
auto ub = s.upper_bound(7);      // First > 7: O(logn)
```

## 🗺️ ASSOCIATIVE CONTAINERS

### MAP/MULTIMAP - Key-Value BST
```cpp
map<string,int> mp;
mp["key"] = 42;                  // Insert/access: O(logn)
mp.count("key");                 // Check existence: O(logn)
for(auto& p : mp) cout << p.first << " " << p.second;
```

### UNORDERED_MAP/SET - Hash Tables
```cpp
unordered_map<int,int> ump;      // Average O(1), worst O(n)
unordered_set<int> us;
ump[5] = 10;                     // Faster for large datasets
```

## ⚡ ALGORITHMS - The Power Tools

### Sorting & Searching
```cpp
sort(all(v));                    // Quicksort: O(nlogn)
sort(all(v), greater<int>());    // Descending
stable_sort(all(v));             // Preserves equal elements order
nth_element(v.begin(), v.begin()+k, v.end()); // Kth element: O(n)

binary_search(all(v), x);        // Boolean search: O(logn)
lower_bound(all(v), x);          // First >= x: O(logn)  
upper_bound(all(v), x);          // First > x: O(logn)
```

### Permutations & Combinations
```cpp
next_permutation(all(v));        // Next lexicographic: O(n)
prev_permutation(all(v));        // Previous lexicographic: O(n)
```

### Min/Max Operations
```cpp
int minVal = *min_element(all(v));
int maxVal = *max_element(all(v));
auto minmax = minmax_element(all(v));
```

### Numeric Operations
```cpp
int sum = accumulate(all(v), 0);           // Sum: O(n)
int gcd_val = __gcd(a, b);                 // GCD: O(logn)
int lcm_val = (a * b) / __gcd(a, b);       // LCM
```

### Set Operations (on sorted ranges)
```cpp
set_union(all(v1), all(v2), back_inserter(result));
set_intersection(all(v1), all(v2), back_inserter(result));
set_difference(all(v1), all(v2), back_inserter(result));
```

## 🎯 ICPC PROBLEM PATTERNS

### 1. Graph Traversal Setup
```cpp
vector<vector<int>> adj(n);      // Adjacency list
vector<bool> visited(n, false);
```

### 2. BFS Template
```cpp
queue<int> q;
q.push(start);
visited[start] = true;
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
    }
}
```

### 3. DFS Template
```cpp
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}
```

### 4. Union-Find (Disjoint Set)
```cpp
vector<int> parent(n), rank_arr(n, 0);
iota(all(parent), 0);  // parent[i] = i

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    if (rank_arr[px] < rank_arr[py]) swap(px, py);
    parent[py] = px;
    if (rank_arr[px] == rank_arr[py]) rank_arr[px]++;
    return true;
}
```

### 5. Dijkstra's Algorithm
```cpp
vector<ll> dist(n, LLONG_MAX);
priority_queue<pii, vector<pii>, greater<pii>> pq;
dist[start] = 0;
pq.push({0, start});

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

## 🔧 ADVANCED TECHNIQUES

### Custom Comparators
```cpp
// For sorting pairs by second element
sort(all(pairs), [](pii a, pii b) { return a.second < b.second; });

// For priority queue with custom comparison  
auto cmp = [](pii a, pii b) { return a.first > b.first; }; // Min heap by first
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
```

### Bit Manipulation Shortcuts
```cpp
__builtin_popcount(x);           // Count set bits
__builtin_clz(x);                // Count leading zeros
__builtin_ctz(x);                // Count trailing zeros
```

### Iterator Magic
```cpp
auto it = v.begin();
advance(it, 3);                  // Move iterator 3 positions
int dist = distance(v.begin(), it); // Distance between iterators
```

## 💡 COMPLEXITY QUICK REFERENCE

| Container | Access | Search | Insert | Delete |
|-----------|---------|---------|---------|---------|
| **vector** | O(1) | O(n) | O(n) | O(n) |
| **deque** | O(1) | O(n) | O(1) ends | O(1) ends |
| **list** | O(n) | O(n) | O(1) | O(1) |
| **set/map** | - | O(logn) | O(logn) | O(logn) |
| **unordered_set/map** | - | O(1) avg | O(1) avg | O(1) avg |

## 🚀 CONTEST TIPS

### Fast I/O
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

### Useful Constants
```cpp
const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
```

### Common Patterns Recognition
- **Two pointers**: Sorted array problems
- **Sliding window**: Subarray problems
- **Binary search**: "Find minimum X such that..." 
- **Greedy**: Interval/scheduling problems
- **DP**: Optimal substructure + overlapping subproblems
- **Graph**: Connected components, shortest path, cycles

### Memory Tricks
```cpp
// 2D vector initialization
vector<vector<int>> dp(n, vector<int>(m, 0));

// Faster than map for integer keys
unordered_map<int,int> is usually faster than map<int,int>

// Use reserve() for known sizes
v.reserve(1000000);  // Avoids multiple reallocations
```

**🏆 MASTER THESE AND DOMINATE ICPC! 🏆**

*Print this, laminate it, live it, breathe it. This is your STL bible for competitive programming glory!*
