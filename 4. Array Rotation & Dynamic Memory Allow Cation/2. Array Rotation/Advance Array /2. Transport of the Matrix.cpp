#include <iostream>
using namespace std;

int main() 
{
    int row, col;
    cout << "Input Row and Column: ";
    cin >> row >> col;

    //  Set maximum limit to avoid dynamic size (VLA not allowed in standard C++)
    const int MAX = 100;
    if (row > MAX || col > MAX) {
        cout << "Matrix size too large. Max allowed is 100x100.\n";
        return 1;
    }

    int arr[MAX][MAX];         // Static 2D array
    int transpose[MAX][MAX];   // Transposed matrix

    // ✅ Input the matrix
    cout << "\nEnter values for the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Input value for arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // ✅ 1. Sum of the diagonal
    int sum = 0;
    if (row == col) {
        for (int i = 0; i < row; i++) {
            sum += arr[i][i];
        }
    }

    // ✅ 2. Transpose (Transport) of the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = arr[i][j];
        }
    }

    // ✅ Output the original matrix
    cout << "\nThe Matrix is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // New line after each row
    }

    // ✅ Output the transpose matrix
    cout << "\nThe Transpose (Transport) Matrix is:\n";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    // ✅ Output the diagonal sum
    if (row == col)
        cout << "\nThe sum of the diagonal is: " << sum << endl;
    else
        cout << "\nDiagonal sum is not applicable (non-square matrix)." << endl;

    return 0;
}
