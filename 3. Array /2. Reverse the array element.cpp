#include <iostream>
using namespace std;

// reverse the array : ______________________________________________________
// we have to swap the first element with the last element, second with second-last, and so on.
// we can do this using a loop: run from i = 0 to i < n / 2 , [cause run the loop half size of the array] 
// swap a[i] with a[n - 1 - i] using a temporary variable
// after loop ends, the array will be reversed

int main()
{
    int a[100], n;

    // Step 1: Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input elements
    cout << "Enter " << n << " elements (ASCII values if you want to see characters): ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Reverse the array
    for (int i = 0; i < n / 2; i++)
    {
        // Swap a[i] and a[n - 1 - i]
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    // Step 4: Print reversed array
    cout << "Reversed array (as numbers): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nAs characters: ";
    for (int i = 0; i < n; i++)
    {
        cout << char(a[i]) << " ";
    }
    cout << endl;

    return 0;
}
