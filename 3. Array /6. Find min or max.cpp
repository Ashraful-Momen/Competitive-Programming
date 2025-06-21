#include <iostream>
using namespace std;

// find the minimum and maximum element in the array : ___________________________________________
// step 1: assume the first element is the min and max → min = a[0], max = a[0]
// step 2: run a loop from i = 1 to n - 1
// inside the loop:
// → if a[i] < min → update min = a[i]
// → if a[i] > max → update max = a[i]
// after loop ends, min and max will hold the smallest and largest values

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

    // Step 3: Initialize min and max with first element
    int min = a[0];
    int max = a[0];

    // Step 4: Find min and max using loop
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    // Step 5: Print result
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
