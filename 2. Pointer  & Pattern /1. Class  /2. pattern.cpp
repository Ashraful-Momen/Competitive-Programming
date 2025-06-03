Here is the **enhanced C++ pattern printing code**, now with:

* ✅ ASCII art of each pattern
* 🧠 The algorithm (loop explanation) for each pattern
* 💬 Clear code comments for learning/competitive prep

---

### 🧩 Full Code with ASCII + Algorithm Notes:

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5; // height of patterns

    // ============================
    // Pattern 1: Left-aligned Triangle
    // ============================
    /*
    ASCII SHAPE:
    *
    **
    ***
    ****
    *****

    ALGORITHM:
    - Outer loop for rows: 1 to n
    - Inner loop prints stars equal to current row
    */

    cout << "Pattern 1: Left-aligned Triangle\n";
    for (int i = 1; i <= n; ++i) {
        for (int star = 1; star <= i; ++star) {
            cout << "*";
        }
        cout << endl;
    }

    // ============================
    // Pattern 2: Right-aligned Triangle
    // ============================
    /*
    ASCII SHAPE:
        *
       **
      ***
     ****
    *****

    ALGORITHM:
    - Outer loop for rows: 1 to n
    - Inner loop 1: print spaces (n - row)
    - Inner loop 2: print stars (row)
    */

    cout << "\nPattern 2: Right-aligned Triangle\n";
    for (int i = 1; i <= n; ++i) {
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        for (int star = 1; star <= i; ++star) {
            cout << "*";
        }
        cout << endl;
    }

    // ============================
    // Pattern 3: Pyramid
    // ============================
    /*
    ASCII SHAPE:
        *
       ***
      *****
     *******
    *********

    ALGORITHM:
    - Outer loop for rows: 1 to n
    - Inner loop 1: spaces (n - row)
    - Inner loop 2: stars (2 * row - 1)
    */

    cout << "\nPattern 3: Pyramid\n";
    for (int i = 1; i <= n; ++i) {
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; ++star) {
            cout << "*";
        }
        cout << endl;
    }

    // ============================
    // Pattern 4: Inverted Pyramid
    // ============================
    /*
    ASCII SHAPE:
    *********
     *******
      *****
       ***
        *

    ALGORITHM:
    - Outer loop for rows: n to 1
    - Inner loop 1: spaces (n - row)
    - Inner loop 2: stars (2 * row - 1)
    */

    cout << "\nPattern 4: Inverted Pyramid\n";
    for (int i = n; i >= 1; --i) {
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; ++star) {
            cout << "*";
        }
        cout << endl;
    }

    // ============================
    // Pattern 5: Diamond
    // ============================
    /*
    ASCII SHAPE:
        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *

    ALGORITHM:
    - Upper half: rows 1 to n
        - spaces: n - row
        - stars: 2 * row - 1
    - Lower half: rows n-1 to 1
        - spaces: n - row
        - stars: 2 * row - 1
    */

    cout << "\nPattern 5: Diamond\n";
    // upper half
    for (int i = 1; i <= n; ++i) {
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; ++star) {
            cout << "*";
        }
        cout << endl;
    }
    // lower half
    for (int i = n - 1; i >= 1; --i) {
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; ++star) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
```

---

### 📘 Tips for Competitive Programming:

* Always **draw the pattern** before coding.
* Use `space` and `star` variables to simulate layout.
* Test edge cases (e.g. `n = 1`, `n = 0`, large `n`).
* If input is dynamic, use `cin >> n;`.


