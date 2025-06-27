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

    int arr[MAX][MAX]; // Static 2D array

    //  Input the matrix
    cout << "\nEnter values for the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Input value for arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // 1. The sum of the diagonal : 
    int sum = 0; 
    cout << "\nEnter values for the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if(i==j){

                cout << "Input value for arr[" << i << "][" << j << "]: " << endl;
                sum = sum + arr[i][j];
            }
        }
    }

    //  Output the matrix
    cout << "\nThe Matrix is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // New line after each row
    }

    cout<<" The sum of the diagonal is : " << sum <<endl;

    return 0;
}
