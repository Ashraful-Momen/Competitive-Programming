#include <iostream>
using namespace std;

// insert a new array element : ______________________________________________________
// we have to move the elements from right to left side to make space.
// run a loop => from the last index to the position_index (reverse order).
// start the loop from the end: for (i = n - 1; i >= pos; i--)
// assign the current element to the next one => a[i + 1] = a[i]
// finally insert the new value at position => a[pos] = new_value
// increase the size of the array => n = n + 1

int main()
{
    int a[100], n, pos, value;

    // Step 1: Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Ask index and value to insert
    cout << "Enter the index to insert (0 to " << n << "): ";
    cin >> pos;

    // Step 4: Check for valid position
    if (pos < 0 || pos > n)
    {
        cout << "Invalid index!" << endl;
        return 1;
    }

    cout << "Enter the value to insert: ";
    cin >> value;

    // Step 5: Shift elements right to make space
    for (int i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }

    // Step 6: Insert the value
    a[pos] = value;

    // Step 7: Increase array size
    n++;

    // Step 8: Print updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
