# Graph can represent by two way : 
-----------------------------------
1. Adjecency Matrix (normal matrix => row , col)
2. Adjececny List (Every node represent it's neighbour nodes, 1 -> 1,2,3 ; 2 -> 1, 4 ; .....)
3. we can use normal 2D array or adjecency list with vector or without vector.

-----------------------------------------------------------------------------------------------



# 1. Adjecency Matrix => Normal matrix input and output of the graph : 
-----------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;   // first read row and col

    int arr[1000][1000]; // static array with safe max size

    // Matrix Input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is:\n";

    // Matrix Output
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


#------------------ same code with the vector for memory efficient ---------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main(){

    int row,col;
    cin >> row >>col;

    vector<vector <int>> arr(row, vector <int>(col));

     // Matrix Input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is:\n";

    // Matrix Output
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }





    return 0;
}



### Input

```
5 6
1 2
1 3
2 4
3 4
4 5
2 5
```

### ✅ Output

```
Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 1 0 
0 1 1 0 1 
0 1 0 1 0 
```

---

⚡ Notes:

* `int adj[1001][1001];` → can store up to `n = 1000`.
* For **bigger graphs (n > 2000)**, adjacency matrix is **too memory heavy** (`O(n²)`), so use **adjacency list** instead.
* For **weighted graphs**, instead of `0/1`, store weight values (e.g., `adj[u][v] = w`).
