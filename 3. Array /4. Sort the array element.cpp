#include <iostream>
using namespace std;

// sort the array in ascending order : ______________________________________________________
// we have to compare each element with the next element.
// if current element is greater than the next one, then we will swap them.
// run two loops:
// → outer loop: from i = 0 to n - 1 (for number of passes)
// → inner loop: from j = 0 to n - i - 1 (for pairwise comparisons)
// inside inner loop:
// → if a[j] > a[j + 1], then swap the values
// after all passes, the array will be sorted in ascending order

int main()
{
    int a[100], n;

    // Step 1: Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 3: Apply bubble sort
    for (int i = 0; i < n - 1; i++) // total passes
    {
        for (int j = 0; j < n - i - 1; j++) // compare elements
        {
            if (a[j] > a[j + 1])
            {
                // swap a[j] and a[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Step 4: Print the sorted array
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
