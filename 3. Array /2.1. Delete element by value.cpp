#include <iostream>
using namespace std;

// Function to delete element by value
void deleteByValue(int arr[], int& n, int value) {
    int pos = -1;

    // Step 1: Find the position of the value
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    // Step 2: If value not found
    if (pos == -1) {
        cout << "Value not found in the array!" << endl;
        return;
    }

    // Step 3: Shift elements to the left
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Step 4: Decrease size
    n--;

    cout << "Value deleted successfully.\n";
}

// Function to display array
void displayArray(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[100], n, value;

    // Input array size
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input value to delete
    cout << "Enter value to delete: ";
    cin >> value;

    // Call deletion function
    deleteByValue(arr, n, value);

    // Display updated array
    displayArray(arr, n);

    return 0;
}
