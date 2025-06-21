#include <iostream>
using namespace std;

// search an element in the array : ______________________________________________________
// we have to check each element one by one from the beginning.
// run a loop => from i = 0 to n - 1
// inside the loop: check if a[i] == search_value
// → if yes, then print the index and stop
// → if loop ends and not found, show "not found" message

int main()
{
    int a[100], n, value, found = 0;

    // Step 1: Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Input the value to search
    cout << "Enter the number to search: ";
    cin >> value;

    // Step 4: Search using linear search
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
        {
            cout << "Element found at index: " << i << endl;
            found = 1;
            break;
        }
    }

    // Step 5: If not found
    if (!found)
    {
        cout << "Element not found in the array!" << endl;
    }

    return 0;
}
