# C++ Pointers and Memory Management Guide

## Basic Pointer Concepts

A **pointer** is a variable that stores the memory address of another variable. Pointers are fundamental to understanding memory management and efficient programming in C++.

### Basic Pointer Declaration and Usage
```cpp
int a = 10;
int *p = &a;        // p stores the address of variable a
int **p2 = &p;      // p2 stores the address of pointer p (double pointer)

cout << "Value via pointer: " << *p << endl;           // prints 10
cout << "Double pointer value: " << **p2 << endl;      // prints 10
cout << "Address stored in p: " << p << endl;          // prints address of a
cout << "Address of pointer p: " << &p << endl;        // prints address of p
```

## Function Parameter Passing

### Call by Value
- Function receives a **copy** of the value
- Original variable remains unchanged
- Uses more memory for large data

```cpp
int call_value(int value) {
    printf("Value of variable: %d\n", value);
    return value; // return copy of value
}
```

### Call by Reference
- Function receives the **address** (pointer) to the variable
- Can modify the original variable
- More memory efficient

```cpp
int call_reference(int* value) {
    printf("Address received: %p\n", (void*)value);
    return *value; // return value at the address
}

// Usage
int x = 10;
call_value(x);      // passes copy of x
call_reference(&x); // passes address of x
```

## Arrays and Pointers

Arrays are intrinsically connected to pointers in C++:

```cpp
int a[] = {1, 2, 3}; // Array elements stored at consecutive addresses

// Array name is a pointer to first element
printf("Address of a[0]: %p\n", a);           // same as &a[0]
printf("Address of a[1]: %p\n", (void*)(a + 1)); // pointer arithmetic

// Pointer to specific array element
int* p = &a[2];     // points to a[2]
printf("Value at p: %d\n", *p);               // prints 3
```

### Passing Arrays to Functions
```cpp
void array_print_with_pointer(int arr[]) {
    // arr is actually a pointer parameter
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
}
```

## Const with Pointers

Understanding const with pointers is crucial for safe programming:

### Pointer to Constant Value
```cpp
const int y = 20;
const int* ptr1 = &y;   // cannot modify y through ptr1
// *ptr1 = 30;          // ❌ Error: cannot modify value
```

### Constant Pointer
```cpp
int z = 40;
int* const ptr2 = &z;   // ptr2 always points to z
*ptr2 = 50;             // ✅ OK: can modify z's value
// ptr2 = &x;           // ❌ Error: cannot change what ptr2 points to
```

### Constant Pointer to Constant Value
```cpp
const int* const ptr3 = &y;  // cannot modify value OR change pointer
// *ptr3 = 100;              // ❌ Error: cannot modify value
// ptr3 = &z;                // ❌ Error: cannot change address
```

## Function Pointers

Store functions in variables using function pointers:

```cpp
// Traditional function pointer syntax
void (*load_arr)(int[]) = array_print_with_pointer;
load_arr(arr);  // call function through pointer

// Modern C++ auto keyword (cleaner syntax)
auto load_arr = array_print_with_pointer;
load_arr(arr);

// Lambda functions (anonymous functions)
auto add = [](int x, int y) {
    return x + y;
};
cout << "Lambda result: " << add(5, 7) << endl;
```

## Dynamic Memory Management

### Object Creation and Destruction
```cpp
class PointerPlay {
    string name;
};

// Dynamic allocation (heap memory)
PointerPlay* obj = new PointerPlay;  // allocate memory
delete obj;                          // free memory (important!)

// Stack allocation (automatic cleanup)
PointerPlay obj;  // automatically destroyed when out of scope
```

## Key Memory Concepts

### Memory Layout
- **Stack**: Local variables, function parameters (automatic cleanup)
- **Heap**: Dynamic allocation with `new`/`delete` (manual management)
- **Static**: Global variables, static variables

### Pointer Arithmetic
```cpp
int arr[] = {1, 2, 3};
int* p = arr;

p++;        // points to next element (arr[1])
p += 2;     // points to arr[3] (may be out of bounds!)
*(p + 1);   // access value at p+1 position
```

## Best Practices

1. **Always initialize pointers** - uninitialized pointers cause crashes
2. **Check for null pointers** before dereferencing
3. **Match new with delete** - prevent memory leaks
4. **Use smart pointers** in modern C++ (std::unique_ptr, std::shared_ptr)
5. **Prefer references over pointers** when possible for cleaner syntax
6. **Be careful with array bounds** - accessing out-of-bounds memory is undefined behavior

## Common Pointer Pitfalls

- **Dangling pointers**: Pointing to deleted/freed memory
- **Memory leaks**: Forgetting to delete dynamically allocated memory
- **Double deletion**: Calling delete twice on the same pointer
- **Array bounds violations**: Accessing memory outside array limits

Understanding pointers is essential for efficient C++ programming, memory management, and working with data structures like linked lists, trees, and dynamic arrays.
