

#include <iostream>
#include <string>
using namespace std;



class pointerPlay{

    string name ; 


};

void array_print_with_pointer(int arr[]) {



    //buildin function for the arra lenght
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //show the addition of : 

    
}

int addition (int a , int b ){
    return a+b; 
}













int main() {

    // a pointer is a variable that store 

    int a = 10;
    int *p = &a;
    int **p2 = &p;

    cout << " value print with the pointer : " << *p << endl;
    cout << "Double Pointer value: " << **p2 << endl;
    cout << "p2 Pointer address: " << p2 << endl;

    cout << "p1 Pointer value: " << *p << endl;
    cout << "p1 Pointer address: " << p << endl;
    cout << "a Pointer address: " << &a << endl;

    cout << "p2 pointer value: " << **p2 << endl;
    cout << "p2 pointer address: " << *p2 << endl;

    //============================
    int arr[] = {1, 2, 3};

    // store a functoin to a variable , if pass array into the function , the variable must be a pointer for store the function 
    // 
    void (*load_arr)(int[]) = array_print_with_pointer; // here also use the , auto to pass function into array 


    load_arr(arr);

     // Use auto to store function pointer
    auto load_arr = array_print_with_pointer;
    load_arr(arr);

    // Lambda function for addition
    auto add = [](int x, int y) {
        return x + y;
    };
    cout << "Lambda Add: " << add(5, 7) << endl;


    //=============== this keyword is also a pointer ============

    pointerPlay *obj = new pointerPlay;

    //or
    pointerPlay obj; 

    //delete the class object pointer : 
    delete obj;  // free memory



    return 0;



}
