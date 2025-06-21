#include <iostream>
using namespace std;

// delete the array element : ______________________________________________________
// we have to move the element right side to the left side .
// run a loop => from the position_index to end_index.
// start the loop from the index position we want to delete. for (i = pos; i < n - 1; i++)
// assign the next element to the current one => a[i] = a[i + 1]
// finally decrease the size of the array => n = n - 1

int main()
{
    int a[100], n, pos;

    // Step 1: Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Ask which index to delete
    cout << "Enter the index to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    // Step 4: Check for valid index
    if (pos < 0 || pos >= n)
    {
        cout << "Invalid index!" << endl;
        return 1;
    }

    // Step 5: Shift elements left from the deleted index
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    // Step 6: Decrease size of array : cause already delete 1 element from the array . 
    n--;

    // Step 7: Print updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
