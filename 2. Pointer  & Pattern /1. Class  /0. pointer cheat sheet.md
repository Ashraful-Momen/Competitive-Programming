# Complete C/C++ Pointers Guide for Competitive Programming

## Table of Contents
1. [Pointer Basics](#pointer-basics)
2. [Pointer Arithmetic](#pointer-arithmetic)
3. [Arrays and Pointers](#arrays-and-pointers)
4. [Function Pointers](#function-pointers)
5. [Dynamic Memory Allocation](#dynamic-memory-allocation)
6. [Multi-dimensional Arrays](#multi-dimensional-arrays)
7. [String Manipulation](#string-manipulation)
8. [Advanced Pointer Techniques](#advanced-pointer-techniques)
9. [Common Pitfalls and Best Practices](#common-pitfalls-and-best-practices)
10. [Competitive Programming Applications](#competitive-programming-applications)

---

## Pointer Basics

### Declaration and Initialization
```cpp
// Basic pointer declaration
int *ptr;           // Uninitialized pointer
int *ptr = nullptr; // C++11 way (preferred)
int *ptr = NULL;    // C way

// Initialization with variable address
int x = 42;
int *ptr = &x;      // ptr points to x

// Multiple pointers
int *p1, *p2, *p3;  // All are pointers
int *p1, p2, *p3;   // p1 and p3 are pointers, p2 is int
```

### Dereferencing and Address Operations
```cpp
int x = 10;
int *ptr = &x;

cout << x;      // Output: 10
cout << &x;     // Output: address of x
cout << ptr;    // Output: address of x (same as &x)
cout << *ptr;   // Output: 10 (value at address)

*ptr = 20;      // Modify value through pointer
cout << x;      // Output: 20
```

### Pointer to Pointer
```cpp
int x = 100;
int *ptr = &x;
int **ptr2 = &ptr;    // Pointer to pointer

cout << x;        // 100
cout << *ptr;     // 100
cout << **ptr2;   // 100

**ptr2 = 200;     // Modify through double pointer
cout << x;        // 200
```

---

## Pointer Arithmetic

### Basic Operations
```cpp
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;

// Addition and Subtraction
ptr++;          // Move to next element
ptr += 2;       // Move 2 elements forward
ptr--;          // Move to previous element
ptr -= 1;       // Move 1 element backward

// Comparison
int *start = arr;
int *end = arr + 5;
if (ptr < end) {
    // ptr is before end
}

// Difference between pointers
ptrdiff_t diff = end - start;  // Result: 5
```

### Pointer Arithmetic Examples
```cpp
// Traversing array using pointer arithmetic
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;

// Method 1: Using increment
for (int i = 0; i < 5; i++) {
    cout << *ptr << " ";
    ptr++;
}

// Method 2: Using addition
ptr = arr;  // Reset pointer
for (int i = 0; i < 5; i++) {
    cout << *(ptr + i) << " ";
}
```

---

## Arrays and Pointers

### Array-Pointer Relationship
```cpp
int arr[5] = {1, 2, 3, 4, 5};

// These are equivalent:
cout << arr[0];     // 1
cout << *arr;       // 1
cout << *(arr + 0); // 1

cout << arr[2];     // 3
cout << *(arr + 2); // 3

// Array name is constant pointer
// arr++; // ERROR! Can't modify array name
```

### Dynamic Arrays
```cpp
// Dynamic array allocation
int n = 10;
int *arr = new int[n];

// Initialize
for (int i = 0; i < n; i++) {
    arr[i] = i * i;
    // or *(arr + i) = i * i;
}

// Access elements
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}

// Don't forget to free memory
delete[] arr;
```

### Passing Arrays to Functions
```cpp
// All three declarations are equivalent
void printArray(int arr[], int size);
void printArray(int *arr, int size);
void printArray(int arr[10], int size); // Size ignored

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        // or cout << *(arr + i) << " ";
    }
}

// Usage
int main() {
    int array[5] = {1, 2, 3, 4, 5};
    printArray(array, 5);
    return 0;
}
```

---

## Function Pointers

### Basic Function Pointers
```cpp
// Function declaration
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// Function pointer declaration and usage
int (*operation)(int, int);

operation = add;
cout << operation(5, 3);  // Output: 8

operation = multiply;
cout << operation(5, 3);  // Output: 15

// Alternative syntax
int (*ops[])(int, int) = {add, multiply};
cout << ops[0](5, 3);     // Output: 8
cout << ops[1](5, 3);     // Output: 15
```

### Function Pointers in Competitive Programming
```cpp
// Useful for different sorting comparisons
bool ascending(int a, int b) { return a < b; }
bool descending(int a, int b) { return a > b; }

void bubbleSort(int arr[], int n, bool (*compare)(int, int)) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (compare(arr[j+1], arr[j])) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Usage
int arr[] = {64, 34, 25, 12, 22, 11, 90};
bubbleSort(arr, 7, ascending);   // Sort in ascending order
bubbleSort(arr, 7, descending);  // Sort in descending order
```

---

## Dynamic Memory Allocation

### malloc, calloc, realloc, free (C style)
```cpp
#include <stdlib.h>

// malloc - allocates uninitialized memory
int *ptr = (int*)malloc(5 * sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    exit(1);
}

// calloc - allocates zero-initialized memory
int *ptr2 = (int*)calloc(5, sizeof(int));

// realloc - resize allocated memory
ptr = (int*)realloc(ptr, 10 * sizeof(int));

// free - deallocate memory
free(ptr);
free(ptr2);
```

### new and delete (C++ style)
```cpp
// Single variable
int *ptr = new int(42);        // Initialize with 42
int *ptr2 = new int;           // Uninitialized
delete ptr;
delete ptr2;

// Arrays
int *arr = new int[10];        // Array of 10 integers
int *arr2 = new int[10]();     // Zero-initialized array
int *arr3 = new int[5]{1,2,3,4,5}; // Initialized array
delete[] arr;
delete[] arr2;
delete[] arr3;
```

### Smart Pointers (C++11 and later)
```cpp
#include <memory>

// unique_ptr - exclusive ownership
std::unique_ptr<int> ptr = std::make_unique<int>(42);
cout << *ptr;  // 42

// unique_ptr for arrays
std::unique_ptr<int[]> arr = std::make_unique<int[]>(10);
arr[0] = 100;

// shared_ptr - shared ownership
std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
std::shared_ptr<int> ptr2 = ptr1;  // Both point to same object
cout << ptr1.use_count();  // 2

// weak_ptr - non-owning reference
std::weak_ptr<int> weak = ptr1;
```

---

## Multi-dimensional Arrays

### 2D Arrays and Pointers
```cpp
// Static 2D array
int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

// Array of pointers (rows can have different sizes)
int *rows[3];
rows[0] = new int[4]{1,2,3,4};
rows[1] = new int[4]{5,6,7,8};
rows[2] = new int[4]{9,10,11,12};

// Access elements
cout << rows[1][2];  // Output: 7

// Clean up
for (int i = 0; i < 3; i++) {
    delete[] rows[i];
}
```

### Dynamic 2D Arrays
```cpp
// Method 1: Array of pointers
int **create2D(int rows, int cols) {
    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

void delete2D(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// Method 2: Single allocation (more cache-friendly)
int *create2DFlat(int rows, int cols) {
    return new int[rows * cols];
}

int& access2D(int *arr, int row, int col, int cols) {
    return arr[row * cols + col];
}
```

---

## String Manipulation

### C-style Strings
```cpp
#include <cstring>

char str[] = "Hello World";
char *ptr = str;

// String traversal
while (*ptr != '\0') {
    cout << *ptr;
    ptr++;
}

// String functions with pointers
char* myStrcat(char* dest, const char* src) {
    char* result = dest;
    
    // Move to end of dest
    while (*dest) dest++;
    
    // Copy src to dest
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    
    return result;
}

int myStrlen(const char* str) {
    const char* ptr = str;
    while (*ptr) ptr++;
    return ptr - str;
}
```

### String Arrays
```cpp
// Array of string pointers
const char* words[] = {"apple", "banana", "cherry"};

// Print all words
for (int i = 0; i < 3; i++) {
    cout << words[i] << endl;
}

// Dynamic string array
char** createStringArray(int count, int maxLen) {
    char** arr = new char*[count];
    for (int i = 0; i < count; i++) {
        arr[i] = new char[maxLen];
    }
    return arr;
}
```

---

## Advanced Pointer Techniques

### Void Pointers
```cpp
// Generic pointer that can point to any data type
void* ptr;

int x = 10;
float y = 3.14f;
char c = 'A';

ptr = &x;
cout << *(int*)ptr;     // Cast to int* and dereference

ptr = &y;
cout << *(float*)ptr;   // Cast to float* and dereference

ptr = &c;
cout << *(char*)ptr;    // Cast to char* and dereference
```

### Const Pointers
```cpp
int x = 10, y = 20;

// Pointer to constant - can't modify value through pointer
const int* ptr1 = &x;
// *ptr1 = 30;  // ERROR!
ptr1 = &y;      // OK - can change what it points to

// Constant pointer - can't change what it points to
int* const ptr2 = &x;
*ptr2 = 30;     // OK - can modify value
// ptr2 = &y;   // ERROR!

// Constant pointer to constant
const int* const ptr3 = &x;
// *ptr3 = 30;  // ERROR!
// ptr3 = &y;   // ERROR!
```

### Pointer Arrays vs Array of Pointers
```cpp
// Array of pointers
int a = 1, b = 2, c = 3;
int* ptrArray[3] = {&a, &b, &c};

// Pointer to array
int arr[3] = {1, 2, 3};
int (*arrayPtr)[3] = &arr;

cout << (*arrayPtr)[0];  // Access first element
```

---

## Common Pitfalls and Best Practices

### Memory Leaks
```cpp
// BAD - Memory leak
void badFunction() {
    int* ptr = new int[1000];
    // Function ends without delete[] ptr
}

// GOOD - Proper cleanup
void goodFunction() {
    int* ptr = new int[1000];
    // ... use ptr ...
    delete[] ptr;
}

// BETTER - Use smart pointers
void betterFunction() {
    std::unique_ptr<int[]> ptr = std::make_unique<int[]>(1000);
    // Automatic cleanup when function ends
}
```

### Dangling Pointers
```cpp
// BAD - Dangling pointer
int* createDanglingPointer() {
    int x = 42;
    return &x;  // x goes out of scope!
}

// GOOD - Return heap-allocated memory
int* createValidPointer() {
    int* ptr = new int(42);
    return ptr;  // Caller must delete
}

// BETTER - Use references or smart pointers
std::unique_ptr<int> createSmartPointer() {
    return std::make_unique<int>(42);
}
```

### Null Pointer Checks
```cpp
// Always check for null pointers
void safeFunction(int* ptr) {
    if (ptr != nullptr) {
        cout << *ptr;
    } else {
        cout << "Null pointer!";
    }
}

// Or use modern C++ features
void modernSafeFunction(int* ptr) {
    if (ptr) {  // Implicit null check
        cout << *ptr;
    }
}
```

---

## Competitive Programming Applications

### Fast I/O with Pointers
```cpp
// Fast integer reading
inline int fastRead() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}
```

### Custom Data Structures
```cpp
// Linked List Node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};
```

### Memory Pool for Fast Allocation
```cpp
// Pre-allocated memory pool for competitive programming
template<typename T>
class MemoryPool {
private:
    T* pool;
    int current;
    int size;
    
public:
    MemoryPool(int n) : current(0), size(n) {
        pool = new T[n];
    }
    
    ~MemoryPool() {
        delete[] pool;
    }
    
    T* allocate() {
        if (current < size) {
            return &pool[current++];
        }
        return nullptr;
    }
    
    void reset() {
        current = 0;
    }
};

// Usage
MemoryPool<TreeNode> nodePool(100000);
TreeNode* newNode = nodePool.allocate();
```

### Array Manipulation Tricks
```cpp
// Reverse array using pointers
void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;
    
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

// Two pointers technique for sorted array
bool twoSum(int* arr, int n, int target) {
    int* left = arr;
    int* right = arr + n - 1;
    
    while (left < right) {
        int sum = *left + *right;
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
```

### Efficient String Processing
```cpp
// KMP algorithm using pointers
void computeLPS(char* pattern, int* lps, int m) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
```

### Quick Tips for Competitive Programming

1. **Use `int*` instead of `vector<int>` for better performance when size is known**
2. **Pre-allocate large arrays globally to avoid stack overflow**
3. **Use pointer arithmetic instead of array indexing for micro-optimizations**
4. **Prefer `new`/`delete` over `malloc`/`free` in C++ for better type safety**
5. **Use `nullptr` instead of `NULL` in modern C++**
6. **Always initialize pointers to avoid undefined behavior**
7. **Use const correctness to prevent accidental modifications**
8. **Profile your code - sometimes the "optimized" pointer version is slower due to compiler optimizations**

### Common Competitive Programming Patterns
```cpp
// Pattern 1: Two pointers for subarray problems
int maxSubarraySum(int* arr, int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for (int* ptr = arr + 1; ptr < arr + n; ptr++) {
        currentSum = max(*ptr, currentSum + *ptr);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// Pattern 2: Sliding window with pointers
int maxSumSubarray(int* arr, int n, int k) {
    int* left = arr;
    int* right = arr + k - 1;
    
    int sum = 0;
    for (int* p = left; p <= right; p++) {
        sum += *p;
    }
    
    int maxSum = sum;
    right++;
    
    while (right < arr + n) {
        sum = sum - *left + *right;
        maxSum = max(maxSum, sum);
        left++;
        right++;
    }
    
    return maxSum;
}
```

This comprehensive guide covers all essential pointer concepts needed for competitive programming in C and C++. Practice these concepts with actual problems to master pointer manipulation and memory management.
