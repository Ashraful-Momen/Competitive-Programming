#include <iostream>
using namespace std;

// call by value: function receives a copy of the value
int call_value(int value) {
    printf("Value of variable: %d\n", value); 
    return value; // return value 
}

// call by reference: function receives a pointer (address)
int call_reference(int* value) {
    printf("Value of ref/address: %p\n", (void*)value); // print address
    return *value; // return the value at the address
}

int main() {
    // array by default is a pointer . 
    // **** array points to the 1st element, 
    
    int a[] = {1, 2, 3}; // store each element 4 bytes address of int the address : 1001, 1004, 1008
    
    
    // print addresses of array elements
    printf("Address of a[0]: %p\n", a);     // returns the address of a[0]
    printf("Address of a[0]: %p\n", (void*)a);     // returns the address of a[0]
    
    // **** print print 1st element:  a == a[0] == *(a) 
    printf("Address of a[1]: %p\n", (void*)(a + 1)); // returns the address of a[1]
    
    int* p = &a[2]; // point to a[2]'s address

    // access values through pointer
    printf("Value at p (a[2]): %d\n", *p);         // returns the value of a[2]
    printf("Value at p+1 (a[3] - invalid access): %d\n", *(p + 1)); // may be garbage; out of bounds!

    int x = 10;

    // call by value: call the function with a copy of the value
    printf("Returned by call_value: %d\n", call_value(x));

    // call by reference: call the function with the address of x
    printf("Returned by call_reference: %d\n", call_reference(&x));


    // class use this->variable . "$this" access inside class and method also a pointer . 


    // explain with constent of pointer , constant pointer can't change the variable value , cause the the variable is pointer. 
    // a constant variable pointer point  to the constant variable. 
    // a constant pointer only point 1 variable . 

    // ----------- Pointer & Const Explanation -----------

    // A pointer to a constant value (cannot modify the value via the pointer)
    const int y = 20;
    const int* ptr1 = &y; // pointer to const
    // *ptr1 = 30; // ❌ Error: cannot modify the value y through ptr1

    // A constant pointer to a variable (cannot change what it points to, but can modify value)
    int z = 40;
    int* const ptr2 = &z; // const pointer
    *ptr2 = 50; // ✅ allowed: modifying the value of z
    // ptr2 = &x; // ❌ Error: ptr2 cannot point to another variable

    // A constant pointer to a constant value (cannot modify value or change pointer)
    const int* const ptr3 = &y;
    // *ptr3 = 100; // ❌ Error: cannot modify value
    // ptr3 = &z;   // ❌ Error: cannot change address

    return 0;
}
