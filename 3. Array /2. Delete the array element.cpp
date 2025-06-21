#include <iostream>
using namespace std; 

int main () {

// delete the array element : ______________________________________________________
// we have to move the element right side to the left side . 
// run a loop => from the position_index to end_index. 
// start the loop from the index position we want to delete. for (i = pos; i < n - 1; i++)
// assign the next element to the current one => a[i] = a[i + 1]
// finally decrease the size of the array => n = n - 1


    //coding part : ____________________

    int a[100], n, pos;

    // Step 1: Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    cout << "Enter " << n << " ASCII values (e.g., 65 for A): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 3: Input position to delete
    cout << "Enter the index to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    // Step 4: Check if index is valid
    if (pos < 0 || pos >= n) {
        cout << "Invalid index!" << endl;
        return 1;
    }

    // Step 5: Delete element by shifting others left
    // delete the array element : ______________________________________________________
    // we have to move the element right side to the left side . 
    // run a loop => from the position_index to end_index. 
    // start the loop from the index position we want to delete. for (i = pos; i < n - 1; i++)
    // assign the next element to the current one => a[i] = a[i + 1]
    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Step 6: Reduce size
    n--;

    // Step 7: Print updated array (in character form)
    cout << "Updated array (ASCII values): ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nAs characters: ";
    for (int i = 0; i < n; i++) {
        cout << char(a[i]) << " ";
    }
    cout << endl;
    
    

    return 0; 
}
