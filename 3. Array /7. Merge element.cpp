#include <iostream>
using namespace std;

// merge two arrays into a third array : ______________________________________________________
// we have two arrays: a1[] and a2[] with sizes n1 and n2
// we want to combine them into a3[]
// step 1: copy all elements of a1 into a3
// step 2: copy all elements of a2 into a3 (after a1’s elements)
// final array a3 will have size = n1 + n2
// print the merged array

int main()
{
    int a1[100], a2[100], a3[200];
    int n1, n2;

    // Step 1: Input first array
    cout << "Enter number of elements in first array: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements for first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }

    // Step 2: Input second array
    cout << "Enter number of elements in second array: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements for second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }

    // Step 3: Copy elements from first array to third array
    for (int i = 0; i < n1; i++)
    {
        a3[i] = a1[i];
    }

    // Step 4: Copy elements from second array to third array
    for (int i = 0; i < n2; i++)
    {
        a3[n1 + i] = a2[i];
    }

    // Step 5: Print merged array
    cout << "Merged array: ";
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << a3[i] << " ";
    }
    cout << endl;

    return 0;
}
