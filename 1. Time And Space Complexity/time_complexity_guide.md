# Complete Time Complexity Guide for Competitive Programming & Interviews

## Table of Contents
1. [Fundamentals](#fundamentals)
2. [Big O Notation Basics](#big-o-notation-basics)
3. [Common Time Complexities](#common-time-complexities)
4. [Mathematical Analysis](#mathematical-analysis)
5. [Code Analysis Techniques](#code-analysis-techniques)
6. [Advanced Optimization Tricks](#advanced-optimization-tricks)
7. [Data Structure Complexities](#data-structure-complexities)
8. [Algorithm Pattern Complexities](#algorithm-pattern-complexities)
9. [Interview Tricks & Tips](#interview-tricks--tips)
10. [Competitive Programming Constraints](#competitive-programming-constraints)

---

## Fundamentals

### What is Time Complexity?
Time complexity measures how the execution time of an algorithm grows as the input size increases. It's expressed using Big O notation.

### Why It Matters
- **Interviews**: 80% of coding interviews focus on optimization
- **Competitive Programming**: Wrong complexity = Time Limit Exceeded (TLE)
- **Real Systems**: Scalability depends on algorithmic efficiency

---

## Big O Notation Basics

### Definition
Big O describes the **worst-case** upper bound of an algorithm's time complexity.

### Common Notations
```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

### Mathematical Rules
1. **Drop Constants**: O(5n) → O(n)
2. **Drop Lower Terms**: O(n² + n) → O(n²)
3. **Multiplication Rule**: Nested operations multiply
4. **Addition Rule**: Sequential operations add

---

## Common Time Complexities

### O(1) - Constant Time
```cpp
// Array access, hash table operations
int getFirst(vector<int>& arr) {
    return arr[0];  // Always takes same time
}

// Mathematical operations
int sum = a + b;
int product = x * y;
```

### O(log n) - Logarithmic Time
```cpp
// Binary search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
// Analysis: Each iteration eliminates half the search space
// T(n) = T(n/2) + O(1) = O(log n)
```

### O(n) - Linear Time
```cpp
// Single loop through array
int findMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {  // n-1 iterations
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}
// Analysis: T(n) = (n-1) * O(1) = O(n)
```

### O(n log n) - Linearithmic Time
```cpp
// Merge sort, heap sort, efficient sorting
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);      // T(n/2)
        mergeSort(arr, mid + 1, right); // T(n/2)
        merge(arr, left, mid, right);   // O(n)
    }
}
// Analysis: T(n) = 2T(n/2) + O(n) = O(n log n)
```

### O(n²) - Quadratic Time
```cpp
// Nested loops, bubble sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {           // n iterations
        for (int j = 0; j < n - i - 1; j++) { // (n-i-1) iterations
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// Analysis: T(n) = n + (n-1) + (n-2) + ... + 1 = n(n-1)/2 = O(n²)
```

### O(2ⁿ) - Exponential Time
```cpp
// Naive Fibonacci, subset generation
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// Analysis: T(n) = T(n-1) + T(n-2) + O(1) ≈ O(2ⁿ)
```

---

## Mathematical Analysis

### Recurrence Relations

#### Master Theorem
For recurrences of the form: **T(n) = aT(n/b) + f(n)**

**Case 1**: If f(n) = O(n^(log_b(a) - ε)) for ε > 0, then T(n) = O(n^log_b(a))
**Case 2**: If f(n) = O(n^log_b(a)), then T(n) = O(n^log_b(a) * log n)
**Case 3**: If f(n) = Ω(n^(log_b(a) + ε)) for ε > 0, then T(n) = O(f(n))

#### Examples:
```cpp
// Binary Search: T(n) = T(n/2) + O(1)
// a=1, b=2, f(n)=O(1), log_b(a)=0
// Case 2: T(n) = O(log n)

// Merge Sort: T(n) = 2T(n/2) + O(n)
// a=2, b=2, f(n)=O(n), log_b(a)=1
// Case 2: T(n) = O(n log n)
```

### Summation Formulas
```
Σ(i=1 to n) 1 = n                    → O(n)
Σ(i=1 to n) i = n(n+1)/2            → O(n²)
Σ(i=1 to n) i² = n(n+1)(2n+1)/6     → O(n³)
Σ(i=0 to n) 2^i = 2^(n+1) - 1       → O(2ⁿ)
```

---

## Code Analysis Techniques

### Loop Analysis Patterns

#### Single Loop
```cpp
for (int i = 0; i < n; i++) {
    // O(1) operation
}
// Time: O(n)
```

#### Nested Loops
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operation
    }
}
// Time: O(n²)
```

#### Dependent Nested Loops
```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {  // j starts from i
        // O(1) operation
    }
}
// Analysis: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)
```

#### Logarithmic Loops
```cpp
for (int i = 1; i < n; i *= 2) {
    // O(1) operation
}
// Analysis: i takes values 1, 2, 4, 8, ..., 2^k where 2^k < n
// So k = log₂(n), Time: O(log n)
```

#### Harmonic Series Loop
```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        // O(1) operation
    }
}
// Analysis: n/1 + n/2 + n/3 + ... + n/n = n(1 + 1/2 + 1/3 + ... + 1/n)
// Harmonic series ≈ O(n log n)
```

---

## Advanced Optimization Tricks

### 1. **Amortized Analysis Trick**
```cpp
// Dynamic Array Resizing
class DynamicArray {
    vector<int> arr;
public:
    void push_back(int x) {
        arr.push_back(x);  // Amortized O(1)
    }
};
// Even though resizing takes O(n), it happens rarely
// Amortized time per operation: O(1)
```

### 2. **Two Pointers Technique**
```cpp
// Instead of O(n²) nested loops
bool twoSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());  // O(n log n)
    int left = 0, right = arr.size() - 1;
    while (left < right) {  // O(n)
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
// Total: O(n log n) instead of O(n²)
```

### 3. **Sliding Window Technique**
```cpp
// Maximum sum subarray of size k
int maxSumSubarray(vector<int>& arr, int k) {
    int windowSum = 0;
    // Calculate first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
// Time: O(n) instead of O(n*k)
```

### 4. **Memoization (Dynamic Programming)**
```cpp
// Optimized Fibonacci
unordered_map<int, long long> memo;
long long fibonacci(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
// Time: O(n) instead of O(2ⁿ)
```

### 5. **Binary Search on Answer**
```cpp
// Find minimum capacity to ship packages in D days
bool canShip(vector<int>& weights, int capacity, int days) {
    int currentWeight = 0, daysNeeded = 1;
    for (int weight : weights) {
        if (currentWeight + weight > capacity) {
            daysNeeded++;
            currentWeight = weight;
        } else {
            currentWeight += weight;
        }
    }
    return daysNeeded <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canShip(weights, mid, days)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
// Time: O(n * log(sum of weights))
```

---

## Data Structure Complexities

### Arrays
| Operation | Time |
|-----------|------|
| Access | O(1) |
| Search | O(n) |
| Insert | O(n) |
| Delete | O(n) |

### Hash Tables
| Operation | Average | Worst |
|-----------|---------|-------|
| Access | O(1) | O(n) |
| Search | O(1) | O(n) |
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |

### Binary Search Tree
| Operation | Average | Worst |
|-----------|---------|-------|
| Access | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

### Heap
| Operation | Time |
|-----------|------|
| Find Min/Max | O(1) |
| Insert | O(log n) |
| Delete Min/Max | O(log n) |
| Build Heap | O(n) |

---

## Algorithm Pattern Complexities

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |

### Graph Algorithms
| Algorithm | Time | Space |
|-----------|------|-------|
| DFS/BFS | O(V + E) | O(V) |
| Dijkstra | O((V + E) log V) | O(V) |
| Bellman-Ford | O(VE) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |
| Kruskal's MST | O(E log E) | O(V) |
| Prim's MST | O(E log V) | O(V) |

---

## Interview Tricks & Tips

### 1. **Quick Complexity Estimation**
```
n ≤ 10: O(n!) or O(2ⁿ) is acceptable
n ≤ 20: O(2ⁿ) might work
n ≤ 100: O(n³) or O(n²) is fine
n ≤ 1000: O(n²) is acceptable
n ≤ 10⁵: O(n log n) or O(n) required
n ≤ 10⁶: O(n) or O(log n) required
n ≤ 10⁸: O(log n) or O(1) required
```

### 2. **Common Interview Patterns**

#### Pattern: Brute Force → Optimization
```cpp
// Brute Force: O(n²)
vector<int> twoSum_bruteforce(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// Optimized: O(n)
vector<int> twoSum_optimized(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}
```

### 3. **Space-Time Tradeoff Recognition**
```cpp
// More space for better time
unordered_set<int> seen;  // O(n) space for O(1) lookup

// Less space, more time
vector<int> sorted_array;  // O(log n) binary search instead of O(1) hash
```

### 4. **Complexity Analysis Questions to Ask**
- "Can I solve this in linear time?"
- "Is there a way to avoid the nested loop?"
- "Can I preprocess the data to make queries faster?"
- "What if I sort the input first?"
- "Can I use extra space to optimize time?"

---

## Competitive Programming Constraints

### Typical Time Limits
- **Easy Problems**: 1-2 seconds
- **Medium Problems**: 1-3 seconds  
- **Hard Problems**: 2-5 seconds

### Operations per Second (Rough Estimates)
- **Simple operations**: ~10⁸ per second
- **Complex operations**: ~10⁶ per second

### Constraint-Complexity Mapping
```
n ≤ 10: O(n!), O(2ⁿ)
n ≤ 20: O(2ⁿ), O(n³)
n ≤ 500: O(n³)
n ≤ 5000: O(n²)
n ≤ 10⁵: O(n log n)
n ≤ 10⁶: O(n)
n ≤ 10⁸: O(log n)
```

### Quick TLE Prevention Checklist
1. ✅ Check if complexity matches constraints
2. ✅ Avoid unnecessary operations in inner loops
3. ✅ Use faster I/O for large inputs
4. ✅ Consider integer overflow
5. ✅ Use appropriate data structures

---

## Advanced Mathematical Tricks

### 1. **Bit Manipulation Optimizations**
```cpp
// Check if number is power of 2: O(1)
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Count set bits: O(number of set bits)
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Remove lowest set bit
        count++;
    }
    return count;
}
```

### 2. **Mathematical Shortcuts**
```cpp
// Sum of arithmetic progression
int sumAP(int first, int last, int n) {
    return n * (first + last) / 2;  // O(1) instead of O(n) loop
}

// GCD using Euclidean algorithm: O(log min(a,b))
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

### 3. **Precomputation Tricks**
```cpp
// Prefix sums for range queries
class PrefixSum {
    vector<int> prefix;
public:
    PrefixSum(vector<int>& arr) {
        prefix.resize(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
    }
    
    int rangeSum(int left, int right) {  // O(1) query
        return prefix[right + 1] - prefix[left];
    }
};
```

---

## Final Pro Tips

### 1. **Always Consider These Optimizations**
- Can I sort the input to make the problem easier?
- Can I use a hash table for O(1) lookups?
- Can I use two pointers instead of nested loops?
- Can I binary search on the answer?
- Can I precompute some values?

### 2. **Red Flags for Wrong Complexity**
- Nested loops when n > 1000
- No early termination in search algorithms
- Recalculating the same values repeatedly
- Using inappropriate data structures

### 3. **Communication During Interviews**
- Always state your approach's time complexity
- Explain why your solution is optimal
- Discuss space-time tradeoffs
- Mention alternative approaches and their complexities

### 4. **Practice Problems by Complexity**
- **O(1)**: Array manipulation, math problems
- **O(log n)**: Binary search variations
- **O(n)**: Two pointers, sliding window
- **O(n log n)**: Sorting-based problems
- **O(n²)**: Dynamic programming, nested iterations

Remember: **Time complexity analysis is a skill that improves with practice. Start with simple problems and gradually work your way up to more complex algorithms!**