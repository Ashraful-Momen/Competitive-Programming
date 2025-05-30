# Complete Space Complexity Guide for Competitive Programming & Interviews

## Table of Contents
1. [Fundamentals](#fundamentals)
2. [Space Complexity Basics](#space-complexity-basics)
3. [Memory Types & Analysis](#memory-types--analysis)
4. [Common Space Complexities](#common-space-complexities)
5. [Mathematical Analysis](#mathematical-analysis)
6. [Code Analysis Techniques](#code-analysis-techniques)
7. [Advanced Space Optimization Tricks](#advanced-space-optimization-tricks)
8. [Data Structure Space Complexities](#data-structure-space-complexities)
9. [Algorithm Pattern Space Analysis](#algorithm-pattern-space-analysis)
10. [Interview Tricks & Tips](#interview-tricks--tips)
11. [Memory Constraints in Competitive Programming](#memory-constraints-in-competitive-programming)

---

## Fundamentals

### What is Space Complexity?
Space complexity measures how much additional memory an algorithm uses as the input size grows. It includes both auxiliary space and input space.

### Types of Space Usage
1. **Input Space**: Memory used to store input data
2. **Auxiliary Space**: Extra memory used by algorithm (excluding input)
3. **Total Space**: Input space + Auxiliary space

### Why Space Complexity Matters
- **Memory Limits**: Competitive programming has strict memory constraints (usually 256MB-512MB)
- **System Performance**: Excessive memory usage causes cache misses and slower execution
- **Scalability**: Real systems must handle large datasets efficiently
- **Interview Assessment**: Tests understanding of memory management and optimization

---

## Space Complexity Basics

### Definition
Space complexity describes how much additional memory an algorithm needs relative to input size, expressed in Big O notation.

### Key Principles
1. **Count Extra Variables**: Only auxiliary space matters for space complexity
2. **Recursion Stack**: Function calls consume stack space
3. **Data Structures**: Arrays, hash tables, trees consume memory
4. **Input Modification**: In-place algorithms use O(1) extra space

### Common Space Complexities (Auxiliary Space)
```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ)
```

---

## Memory Types & Analysis

### Stack Memory
```cpp
// Recursion uses stack space
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // O(n) stack space
}
// Each recursive call adds a frame to call stack
// Maximum depth = n, so space = O(n)
```

### Heap Memory
```cpp
// Dynamic allocation
vector<int> createArray(int n) {
    vector<int> arr(n);  // O(n) heap space
    return arr;
}

// Hash table
unordered_map<int, int> freq;  // O(number of unique elements)
```

### Static Memory
```cpp
// Global arrays - not counted in space complexity analysis
int globalArray[1000000];  // Static allocation

void function(int n) {
    int localVar = 5;      // O(1) - single variable
    int tempArray[100];    // O(1) - fixed size array
}
```

---

## Common Space Complexities

### O(1) - Constant Space
```cpp
// In-place array reversal
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);  // Only using 2 variables
        left++;
        right--;
    }
}
// Space Analysis: Only using left, right variables = O(1)
```

```cpp
// Finding maximum without extra space
int findMax(vector<int>& arr) {
    int maxVal = arr[0];  // 1 variable
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
// Space Analysis: Only maxVal and i variables = O(1)
```

### O(log n) - Logarithmic Space
```cpp
// Binary search (iterative) - O(1) space
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Binary search (recursive) - O(log n) space
int binarySearchRecursive(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, right, target);
    else 
        return binarySearchRecursive(arr, left, mid - 1, target);
}
// Space Analysis: Maximum recursion depth = log n
// Each call uses O(1) space, total = O(log n)
```

### O(n) - Linear Space
```cpp
// Creating a copy of array
vector<int> copyArray(vector<int>& original) {
    vector<int> copy(original.size());  // O(n) space
    for (int i = 0; i < original.size(); i++) {
        copy[i] = original[i];
    }
    return copy;
}

// Hash table for frequency counting
unordered_map<int, int> countFrequency(vector<int>& arr) {
    unordered_map<int, int> freq;  // O(n) space in worst case
    for (int num : arr) {
        freq[num]++;
    }
    return freq;  // At most n unique elements
}

// Linear recursion
void printNumbers(int n) {
    if (n <= 0) return;
    cout << n << " ";
    printNumbers(n - 1);  // O(n) stack space
}
```

### O(n²) - Quadratic Space
```cpp
// 2D array creation
vector<vector<int>> create2DArray(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    return matrix;  // O(n²) space
}

// Dynamic programming - 2D table
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  // O(m*n) space
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```

### O(2ⁿ) - Exponential Space
```cpp
// Generating all subsets
void generateSubsets(vector<int>& nums, int index, vector<int>& current, 
                    vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);  // Each subset stored
        return;
    }
    
    // Include current element
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    current.pop_back();
    
    // Exclude current element
    generateSubsets(nums, index + 1, current, result);
}
// Space Analysis: 2^n subsets, each of average size n/2 = O(n * 2^n)
// Call stack depth = n, so total space = O(n * 2^n)
```

---

## Mathematical Analysis

### Recurrence Relations for Space

#### Basic Recursion Space Analysis
```cpp
// Fibonacci - naive approach
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
// Space Analysis: S(n) = max(S(n-1), S(n-2)) + O(1) = O(n)
// Maximum depth of recursion tree = n
```

#### Divide and Conquer Space Analysis
```cpp
// Merge sort space analysis
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);      // Space reused
        mergeSort(arr, mid + 1, right); // Space reused
        merge(arr, left, mid, right);   // O(n) temporary array
    }
}
// Space Analysis: S(n) = S(n/2) + O(n) = O(n)
// Only one branch executes at a time, but merge needs O(n) space
```

### Space-Time Tradeoff Mathematics

#### Trading Space for Time
```cpp
// Without memoization: Time O(2^n), Space O(n)
int fibonacciSlow(int n) {
    if (n <= 1) return n;
    return fibonacciSlow(n-1) + fibonacciSlow(n-2);
}

// With memoization: Time O(n), Space O(n)
unordered_map<int, int> memo;
int fibonacciFast(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    memo[n] = fibonacciFast(n-1) + fibonacciFast(n-2);
    return memo[n];
}
```

---

## Code Analysis Techniques

### Variable Counting
```cpp
void example(int n) {
    int a = 5;           // O(1)
    int b = 10;          // O(1)
    vector<int> arr(n);  // O(n)
    
    for (int i = 0; i < n; i++) {  // i doesn't add to space complexity
        int temp = arr[i] * 2;     // temp is reused, O(1)
    }
}
// Total auxiliary space: O(1) + O(n) = O(n)
```

### Recursion Stack Analysis
```cpp
// Tree recursion
void processTree(TreeNode* root) {
    if (!root) return;
    
    processTree(root->left);   // Stack frame 1
    processTree(root->right);  // Stack frame 2 (after frame 1 returns)
}
// Space: O(height of tree) = O(log n) for balanced tree, O(n) for skewed
```

### Data Structure Memory Calculation
```cpp
// Memory usage calculation
class SpaceAnalysis {
public:
    void analyzeStructures(int n) {
        // Array
        vector<int> arr(n);                    // 4n bytes (assuming 4-byte int)
        
        // Hash table
        unordered_map<int, int> map;           // ~8n bytes per entry (key+value+overhead)
        
        // Set
        unordered_set<int> set;                // ~4n bytes per element + overhead
        
        // 2D array
        vector<vector<int>> matrix(n, vector<int>(n));  // 4n² bytes
    }
};
```

---

## Advanced Space Optimization Tricks

### 1. **In-Place Algorithm Optimization**
```cpp
// Space-inefficient approach: O(n) extra space
vector<int> removeDuplicatesSlow(vector<int>& nums) {
    set<int> seen;
    vector<int> result;
    for (int num : nums) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

// Space-efficient approach: O(1) extra space
int removeDuplicatesFast(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int writeIndex = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {  // Assumes sorted array
            nums[writeIndex++] = nums[i];
        }
    }
    return writeIndex;
}
```

### 2. **Rolling Array Technique**
```cpp
// DP with O(n²) space
int longestCommonSubsequenceNaive(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  // O(m*n) space
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// DP with O(n) space using rolling array
int longestCommonSubsequenceOptimized(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<int> prev(n + 1, 0);  // Previous row
    vector<int> curr(n + 1, 0);  // Current row
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                curr[j] = prev[j-1] + 1;
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;  // Roll the arrays
    }
    return curr[n];
}
```

### 3. **Bit Manipulation for Space Optimization**
```cpp
// Instead of boolean array: O(n) space
vector<bool> isPrime(int n) {
    vector<bool> prime(n + 1, true);  // n+1 booleans
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Using bitset: O(n/8) space (8 times less memory)
void sieveOfEratosthenes(int n) {
    bitset<1000001> prime;  // Each bit represents a number
    prime.set();  // Set all bits to 1
    prime[0] = prime[1] = 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
}
```

### 4. **Iterator-Based Space Optimization**
```cpp
// Memory-inefficient: Store all results
vector<vector<int>> generateAllSubsets(vector<int>& nums) {
    vector<vector<int>> result;  // Stores all 2^n subsets
    // ... generation logic
    return result;  // O(n * 2^n) space
}

// Memory-efficient: Process on-demand
class SubsetGenerator {
    vector<int> nums;
    int currentSubset;
    int totalSubsets;
    
public:
    SubsetGenerator(vector<int>& nums) : nums(nums) {
        currentSubset = 0;
        totalSubsets = 1 << nums.size();  // 2^n
    }
    
    vector<int> getNextSubset() {  // O(n) space per call
        if (currentSubset >= totalSubsets) return {};
        
        vector<int> subset;
        for (int i = 0; i < nums.size(); i++) {
            if (currentSubset & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        currentSubset++;
        return subset;
    }
};
```

### 5. **Stack Simulation to Avoid Recursion**
```cpp
// Recursive DFS: O(height) stack space
void dfsRecursive(TreeNode* root) {
    if (!root) return;
    
    // Process root
    cout << root->val << " ";
    
    dfsRecursive(root->left);
    dfsRecursive(root->right);
}

// Iterative DFS: O(height) explicit stack space, but controllable
void dfsIterative(TreeNode* root) {
    if (!root) return;
    
    stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        
        cout << node->val << " ";
        
        // Push right first, then left (for same order as recursive)
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}
```

### 6. **Memory Pool and Object Reuse**
```cpp
// Memory-inefficient: Frequent allocations
class BadApproach {
public:
    vector<int> processData(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            vector<int> temp(1000);  // New allocation each iteration!
            // Process temp
        }
        return {};
    }
};

// Memory-efficient: Reuse temporary space
class GoodApproach {
    vector<int> reusableBuffer;  // Reused across function calls
    
public:
    GoodApproach() : reusableBuffer(1000) {}
    
    vector<int> processData(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            // Reuse the same buffer
            fill(reusableBuffer.begin(), reusableBuffer.end(), 0);
            // Process reusableBuffer
        }
        return {};
    }
};
```

---

## Data Structure Space Complexities

### Linear Data Structures
| Data Structure | Space Complexity | Notes |
|----------------|------------------|-------|
| Array | O(n) | Fixed size at creation |
| Dynamic Array | O(n) | May have unused capacity |
| Linked List | O(n) | Extra pointer overhead |
| Stack | O(n) | Depends on number of elements |
| Queue | O(n) | Circular buffer most efficient |
| Deque | O(n) | Block-based implementation |

### Hash-Based Structures
| Data Structure | Average Space | Worst Case | Load Factor Impact |
|----------------|---------------|------------|-------------------|
| Hash Table | O(n) | O(n) | Lower load factor → more memory |
| Hash Set | O(n) | O(n) | Typically 75% load factor |
| Hash Map | O(n) | O(n) | Key + Value + overhead |

### Tree Structures
| Data Structure | Space Complexity | Additional Notes |
|----------------|------------------|------------------|
| Binary Search Tree | O(n) | 2 pointers per node |
| AVL Tree | O(n) | Extra balance factor |
| Red-Black Tree | O(n) | Extra color bit |
| B-Tree | O(n) | Multiple keys per node |
| Trie | O(ALPHABET_SIZE * n * L) | L = average string length |
| Segment Tree | O(4n) | Always 4n nodes |
| Fenwick Tree | O(n) | More space-efficient than segment tree |

### Graph Structures
| Representation | Space Complexity | Best Use Case |
|----------------|------------------|---------------|
| Adjacency Matrix | O(V²) | Dense graphs |
| Adjacency List | O(V + E) | Sparse graphs |
| Edge List | O(E) | Simple graph storage |

---

## Algorithm Pattern Space Analysis

### Sorting Algorithms Space Usage
| Algorithm | Space Complexity | Type | Notes |
|-----------|------------------|------|-------|
| Bubble Sort | O(1) | In-place | Only swap variables |
| Selection Sort | O(1) | In-place | Only temp variables |
| Insertion Sort | O(1) | In-place | Shifts elements |
| Merge Sort | O(n) | Not in-place | Temporary merge arrays |
| Quick Sort | O(log n) | In-place | Recursion stack |
| Heap Sort | O(1) | In-place | Uses input array as heap |
| Counting Sort | O(k) | Not in-place | k = range of input |
| Radix Sort | O(n + k) | Not in-place | Temporary buckets |

### Dynamic Programming Space Patterns
```cpp
// Pattern 1: Full DP table - O(n²) space
int editDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    // ... fill dp table
    return dp[m][n];
}

// Pattern 2: Rolling array - O(n) space
int editDistanceOptimized(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<int> prev(n + 1), curr(n + 1);
    // ... use only two rows
    return curr[n];
}

// Pattern 3: Two variables - O(1) space (when possible)
int fibonacci(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

### Graph Algorithm Space Usage
| Algorithm | Space Complexity | Components |
|-----------|------------------|------------|
| DFS (Recursive) | O(V) | Call stack |
| DFS (Iterative) | O(V) | Explicit stack |
| BFS | O(V) | Queue + visited array |
| Dijkstra | O(V) | Priority queue + distances |
| Floyd-Warshall | O(V²) | Distance matrix |
| Kruskal's MST | O(E) | Edge sorting |
| Prim's MST | O(V) | Priority queue |

---

## Interview Tricks & Tips

### 1. **Space Complexity Analysis Framework**
```cpp
// Step-by-step analysis approach
void analyzeSpaceComplexity(/* parameters */) {
    // 1. Identify auxiliary data structures
    vector<int> temp(n);           // O(n)
    unordered_map<int, int> map;   // O(unique elements)
    
    // 2. Analyze recursion depth
    // recursiveFunction(n-1) would be O(n) stack space
    
    // 3. Consider temporary variables
    int a, b, c;  // O(1) - constants don't matter
    
    // 4. Sum up all components
    // Total: O(n) + O(unique elements) + O(1) = O(n)
}
```

### 2. **Common Space Optimization Questions**
- "Can I solve this in O(1) extra space?"
- "Do I really need to store all intermediate results?"
- "Can I reuse the input array for storage?"
- "Can I use bit manipulation to reduce space?"
- "Is there a rolling array optimization possible?"

### 3. **Space-Time Tradeoff Decision Matrix**

| Scenario | Optimize For | Technique | Example |
|----------|-------------|-----------|---------|
| Limited Memory | Space | In-place algorithms | Quick sort vs Merge sort |
| Fast Queries | Time | Precomputation | Prefix sums, lookup tables |
| Balanced | Both | Cache-efficient algorithms | Block-based processing |
| Real-time | Time | Space sacrifice acceptable | Hash tables for O(1) lookup |

### 4. **Interview Communication Tips**
```cpp
// Always explain your space analysis
int twoSum(vector<int>& nums, int target) {
    // Approach 1: Brute force - O(1) space, O(n²) time
    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         if (nums[i] + nums[j] == target) return {i, j};
    //     }
    // }
    
    // Approach 2: Hash table - O(n) space, O(n) time
    unordered_map<int, int> seen;  // Space: O(n) in worst case
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;  // At most n entries
    }
    return {};
}
```

---

## Memory Constraints in Competitive Programming

### Typical Memory Limits
- **Online Judges**: 256MB - 512MB
- **Contest Platforms**: 128MB - 1GB
- **Interactive Problems**: Often stricter limits

### Memory Usage Estimation
```cpp
// Quick memory calculation
int n = 1e6;  // 1 million

// Different data types
int* intArray = new int[n];           // 4MB (4 bytes * 1M)
long long* llArray = new long long[n]; // 8MB (8 bytes * 1M)
string* strArray = new string[n];     // Variable, depends on string lengths

// 2D arrays
vector<vector<int>> matrix(n, vector<int>(n)); // 4GB for n=1M (too much!)

// Hash tables (with overhead)
unordered_map<int, int> map;  // ~12-16 bytes per entry (key+value+overhead)
```

### Memory Limit Strategies
```cpp
// Strategy 1: Use smaller data types when possible
vector<short> smallInts;     // 2 bytes instead of 4
vector<char> flags;          // 1 byte instead of 4 for boolean-like data

// Strategy 2: Bit manipulation for boolean arrays
bitset<1000000> visited;     // 1M bits = 125KB instead of 1MB

// Strategy 3: Compress coordinate systems
void coordinateCompression(vector<int>& coords) {
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    // Now use indices instead of actual coordinates
}

// Strategy 4: Stream processing for large inputs
void processLargeInput() {
    // Instead of storing all data
    // vector<int> allData(1e8);  // 400MB - might exceed limit
    
    // Process data as you read it
    int value;
    long long sum = 0;
    for (int i = 0; i < 1e8; i++) {
        cin >> value;
        sum += value;  // O(1) space
        // Process immediately, don't store
    }
}
```

### Memory-Efficient Competitive Programming Patterns

#### Pattern 1: Sliding Window with Deque
```cpp
// Instead of storing all window elements: O(k) space
deque<int> window;

// Use deque for efficient front/back operations: O(k) space but efficient
vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements (they'll never be maximum)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
```

#### Pattern 2: Space-Efficient Graph Traversal
```cpp
// Instead of storing visited array for large graphs
void dfsWithoutVisitedArray(vector<vector<int>>& graph, int start) {
    // Use the graph itself to mark visited nodes
    // Requires modifying input, but saves O(V) space
    stack<int> stk;
    stk.push(start);
    
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        
        if (graph[node].empty()) continue;  // Already processed
        
        // Process node
        vector<int> neighbors = graph[node];
        graph[node].clear();  // Mark as visited
        
        for (int neighbor : neighbors) {
            if (!graph[neighbor].empty()) {
                stk.push(neighbor);
            }
        }
    }
}
```

---

## Advanced Memory Management Tricks

### 1. **Custom Memory Allocators**
```cpp
// Pool allocator for fixed-size objects
template<typename T, size_t PoolSize>
class MemoryPool {
    char pool[PoolSize * sizeof(T)];
    vector<T*> freeList;
    size_t allocated;
    
public:
    MemoryPool() : allocated(0) {
        for (size_t i = 0; i < PoolSize; i++) {
            freeList.push_back(reinterpret_cast<T*>(pool + i * sizeof(T)));
        }
    }
    
    T* allocate() {
        if (freeList.empty()) return nullptr;
        T* ptr = freeList.back();
        freeList.pop_back();
        allocated++;
        return ptr;
    }
    
    void deallocate(T* ptr) {
        freeList.push_back(ptr);
        allocated--;
    }
};
```

### 2. **Memory-Mapped Files for Large Data**
```cpp
// For processing huge datasets that don't fit in memory
#include <sys/mman.h>
#include <fcntl.h>

class MemoryMappedFile {
    char* data;
    size_t size;
    int fd;
    
public:
    MemoryMappedFile(const string& filename) {
        fd = open(filename.c_str(), O_RDONLY);
        struct stat sb;
        fstat(fd, &sb);
        size = sb.st_size;
        
        data = static_cast<char*>(mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0));
    }
    
    ~MemoryMappedFile() {
        munmap(data, size);
        close(fd);
    }
    
    char* getData() { return data; }
    size_t getSize() { return size; }
};
```

### 3. **Lazy Evaluation for Space Saving**
```cpp
// Instead of computing all values upfront
class LazyFibonacci {
    mutable unordered_map<int, long long> cache;
    
public:
    long long get(int n) const {
        if (n <= 1) return n;
        if (cache.find(n) != cache.end()) return cache[n];
        
        cache[n] = get(n-1) + get(n-2);  // Compute only when needed
        return cache[n];
    }
    
    void clearCache() { cache.clear(); }  // Free memory when done
};
```

### 4. **Compression Techniques**
```cpp
// Run-Length Encoding for sparse data
class RunLengthEncoder {
public:
    struct Run {
        int value;
        int count;
    };
    
    vector<Run> encode(const vector<int>& data) {
        vector<Run> encoded;
        if (data.empty()) return encoded;
        
        int currentValue = data[0];
        int count = 1;
        
        for (int i = 1; i < data.size(); i++) {
            if (data[i] == currentValue) {
                count++;
            } else {
                encoded.push_back({currentValue, count});
                currentValue = data[i];
                count = 1;
            }
        }
        encoded.push_back({currentValue, count});
        return encoded;
    }
    
    vector<int> decode(const vector<Run>& encoded) {
        vector<int> decoded;
        for (const auto& run : encoded) {
            for (int i = 0; i < run.count; i++) {
                decoded.push_back(run.value);
            }
        }
        return decoded;
    }
};

// Delta encoding for sequential data
vector<int> deltaEncode(const vector<int>& data) {
    if (data.empty()) return {};
    
    vector<int> deltas;
    deltas.push_back(data[0]);  // First element as-is
    
    for (int i = 1; i < data.size(); i++) {
        deltas.push_back(data[i] - data[i-1]);  // Store differences
    }
    return deltas;  // Often requires much less space for sorted data
}
```

---

## Practical Space Optimization Examples

### Example 1: Matrix Chain Multiplication
```cpp
// Naive DP: O(n³) space
int matrixChainNaive(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    // ... implementation
    return 0;  // Placeholder
}

// Optimized DP: O(n²) space
int matrixChainOptimized(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}
```

### Example 2: Knapsack Problem Optimization
```cpp
// Standard DP: O(n * W) space
int knapsackNaive(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// Space-optimized: O(W) space
int knapsackOptimized(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < weights.size(); i++) {
        // Traverse backwards to avoid using updated values
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}
```

### Example 3: Palindrome Partitioning
```cpp
// Memory-heavy approach: Store all palindromes
bool isPalindrome(string& s, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j] != -1) return memo[i][j];
    
    if (i >= j) return memo[i][j] = 1;
    if (s[i] == s[j]) return memo[i][j] = isPalindrome(s, i+1, j-1, memo);
    return memo[i][j] = 0;
}

// Space-efficient approach: Expand around centers
vector<vector<bool>> computePalindromes(string& s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    
    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        isPalin[i][i] = true;
    }
    
    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        isPalin[i][i+1] = (s[i] == s[i+1]);
    }
    
    // Check for palindromes of length 3 and more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            isPalin[i][j] = (s[i] == s[j]) && isPalin[i+1][j-1];
        }
    }
    
    return isPalin;
}
```

---

## Memory Profiling and Debugging

### 1. **Manual Memory Tracking**
```cpp
class MemoryTracker {
    static size_t totalAllocated;
    static size_t currentAllocated;
    static size_t peakAllocated;
    
public:
    static void* allocate(size_t size) {
        void* ptr = malloc(size);
        if (ptr) {
            totalAllocated += size;
            currentAllocated += size;
            peakAllocated = max(peakAllocated, currentAllocated);
        }
        return ptr;
    }
    
    static void deallocate(void* ptr, size_t size) {
        free(ptr);
        currentAllocated -= size;
    }
    
    static void printStats() {
        cout << "Total allocated: " << totalAllocated << " bytes\n";
        cout << "Current allocated: " << currentAllocated << " bytes\n";
        cout << "Peak allocated: " << peakAllocated << " bytes\n";
    }
};
```

### 2. **Container Size Analysis**
```cpp
template<typename Container>
void analyzeContainerMemory(const Container& container, const string& name) {
    cout << name << " Analysis:\n";
    cout << "  Size: " << container.size() << " elements\n";
    cout << "  Capacity: " << container.capacity() << " elements\n";
    cout << "  Memory used: " << container.size() * sizeof(typename Container::value_type) << " bytes\n";
    cout << "  Memory allocated: " << container.capacity() * sizeof(typename Container::value_type) << " bytes\n";
    cout << "  Efficiency: " << (100.0 * container.size() / container.capacity()) << "%\n\n";
}

// Usage example
void memoryAnalysisExample() {
    vector<int> vec;
    for (int i = 0; i < 1000; i++) {
        vec.push_back(i);
        if (i % 100 == 0) {
            analyzeContainerMemory(vec, "Vector at size " + to_string(i));
        }
    }
}
```

---

## Common Space Complexity Mistakes

### 1. **Hidden Space Usage**
```cpp
// Mistake: Not counting recursion stack
int badFactorial(int n) {
    if (n <= 1) return 1;
    return n * badFactorial(n - 1);  // Hidden O(n) space in call stack
}

// Better: Iterative approach
int goodFactorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;  // O(1) space
    }
    return result;
}
```

### 2. **Unnecessary Data Structure Usage**
```cpp
// Mistake: Using heavy data structures when simple ones suffice
unordered_map<int, bool> visited;  // Each entry has overhead

// Better: Use simpler structures when possible
vector<bool> visited(n, false);    // More space-efficient for dense indices
// Or even better for very sparse cases:
bitset<MAX_N> visited;            // 1 bit per element
```

### 3. **Not Considering String Memory**
```cpp
// Mistake: Concatenating strings in loop
string result = "";
for (int i = 0; i < n; i++) {
    result += to_string(i);  // Each concatenation may reallocate entire string
}
// Space: O(n²) due to intermediate strings

// Better: Use string builder pattern
vector<string> parts;
for (int i = 0; i < n; i++) {
    parts.push_back(to_string(i));
}
string result = "";
for (const string& part : parts) {
    result += part;  // Only one final concatenation
}
// Space: O(n)
```

### 4. **Forgetting About Input Modification**
```cpp
// Can we modify input to save space?
void processArray(vector<int>& arr) {
    vector<int> processed(arr.size());  // O(n) extra space
    for (int i = 0; i < arr.size(); i++) {
        processed[i] = arr[i] * 2;
    }
    // Use processed array...
}

// Better: Modify in-place if allowed
void processArrayInPlace(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] *= 2;  // O(1) extra space
    }
    // Use modified arr directly...
}
```

---

## Final Pro Tips for Space Optimization

### 1. **Space Complexity Hierarchy (Preference Order)**
1. **O(1)** - Always prefer if possible
2. **O(log n)** - Acceptable for most problems
3. **O(n)** - Standard for many algorithms
4. **O(n log n)** - Sometimes necessary
5. **O(n²)** - Avoid if possible, acceptable for small n
6. **O(2ⁿ)** - Only for very small inputs

### 2. **Quick Space Optimization Checklist**
- ✅ Can I solve in-place?
- ✅ Can I use rolling arrays instead of 2D DP?
- ✅ Can I reuse temporary variables?
- ✅ Do I need to store all intermediate results?
- ✅ Can I use bit manipulation for boolean arrays?
- ✅ Can I compress the coordinate space?
- ✅ Can I process data streaming instead of storing all?

### 3. **Interview Space Analysis Framework**
```cpp
// Always follow this pattern when explaining space complexity:

void explainSpaceComplexity() {
    // 1. Identify all data structures
    vector<int> aux(n);              // "I'm using O(n) auxiliary space for..."
    unordered_map<int, int> freq;    // "Hash map uses O(k) space where k is..."
    
    // 2. Analyze recursion if present
    // recursiveCall();              // "Recursion depth is O(h) where h is..."
    
    // 3. Consider alternatives
    // "I could optimize this to O(1) space by modifying input in-place..."
    // "Or I could use rolling array technique to reduce from O(n²) to O(n)..."
    
    // 4. State final complexity
    // "Overall space complexity is O(n) dominated by the auxiliary array"
}
```

### 4. **Memory Constraint Problem-Solving Strategy**
```
Step 1: Calculate maximum theoretical memory usage
Step 2: Compare with problem memory limit
Step 3: If exceeds limit, apply optimization techniques:
        - In-place algorithms
        - Rolling arrays
        - Bit manipulation
        - Coordinate compression
        - Streaming processing
Step 4: Verify optimized solution fits within constraints
```

### 5. **Space vs Time Decision Matrix**
| Problem Constraint | Optimize For | Common Techniques |
|-------------------|--------------|-------------------|
| Tight memory limit | Space | In-place, bit manipulation, rolling arrays |
| Tight time limit | Time | Hash tables, precomputation, memoization |
| Balanced constraints | Both | Cache-friendly algorithms, moderate space usage |
| Online/streaming data | Space | Process on-the-fly, forget old data |

---

## Conclusion

Space complexity optimization is crucial for both competitive programming and technical interviews. The key principles are:

1. **Always analyze auxiliary space separately from input space**
2. **Consider recursion stack as part of space usage**
3. **Look for opportunities to reuse memory and process in-place**
4. **Understand the space-time tradeoff implications**
5. **Practice estimating memory usage for different data structures**

Master these concepts and you'll be able to write memory-efficient code that scales well and impresses interviewers. Remember: **the best algorithm is often not the fastest one, but the one that best balances time and space constraints for your specific problem!**