// #reverse : swap(a[i], a[n-i-1]) ,  two pointer (i= 0, j=n-1, i<j, i++, j--)

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
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Reverse the array using swapping logic
    for (int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    // Step 4: Print the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
