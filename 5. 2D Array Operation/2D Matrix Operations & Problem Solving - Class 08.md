# **2D Matrix in C++**

A **2D matrix** is a collection of data arranged in rows and columns. In C++, it is typically represented using a **2D array**.

### **1\. Declaring a 2D Matrix**

int rows \= 3, cols \= 3;

int matrix\[rows\]\[cols\];

---

### **2\. Initializing a 2D Matrix**

int rows \= 3, cols \= 3;

int matrix\[rows\]\[cols\] \= {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

---

### **3\. Taking Input**

for (int i \= 0; i \< rows; \++i)

{

    for (int j \= 0; j \< cols; \++j)

    {

        cin \>\> matrix\[i\]\[j\];

    }

}

---

### **4\. Printing the Matrix**

for (int i \= 0; i \< rows; \++i)

{

    for (int j \= 0; j \< cols; \++j)

    {

        cout \<\< matrix\[i\]\[j\] \<\< " ";

    }

    cout \<\< endl;

}

---

### **5\. Accessing Rows**

int rowIndex \= 1; // 2nd row

for (int j \= 0; j \< cols; \++j)

    cout \<\< matrix\[rowIndex\]\[j\] \<\< " ";

---

### **6\. Accessing Columns**

int colIndex \= 2; // 3rd column

for (int i \= 0; i \< rows; \++i)

    cout \<\< matrix\[i\]\[colIndex\] \<\< " ";

---

### **7\. Accessing Diagonal Values**

Types of Diagonals:

* **Primary Diagonal**: Top-left to bottom-right → `i == j`

* **Secondary Diagonal**: Top-right to bottom-left → `i + j == n - 1`

#### **7.1. Primary Diagonal:**

for (int i \= 0; i \< rows; i\++)

{

    for (int j \= 0; j \< cols; j\++)

    {

        if (i \== j)

            cout \<\< matrix\[i\]\[j\] \<\< " ";

    }

}

#### **7.2. Secondary Diagonal:**

for (int i \= 0; i \< rows; i\++)

{

    for (int j \= 0; j \< cols; j\++)

    {

        if (i \+ j \== rows \- 1)

            cout \<\< matrix\[i\]\[j\] \<\< " ";

    }

}

---

### **8\. Matrix Summation (A \+ B)** 

for (int i \= 0; i \< n; \++i)

{

    for (int j \= 0; j \< n; \++j)

    {

        C\[i\]\[j\] \= A\[i\]\[j\] \+ B\[i\]\[j\];

    }

}

---

### **9\. Matrix Multiplication (A \* B)**

To multiply matrices `A[m][n]` and `B[n][p]`:

![][image1]

\#include \<bits/stdc++.h\>

using namespace std;

int main()

{

    int m, n, p;

    cin \>\> m \>\> n;

    int A\[m\]\[n\];

    for (int i \= 0; i \< m; \++i)

    {

        for (int j \= 0; j \< n; \++j)

        {

            cin \>\> A\[i\]\[j\];

        }

    }

    cin \>\> n \>\> p;

    int B\[n\]\[p\];

    int C\[m\]\[p\];

    memset(C, 0, sizeof(C));

    for (int i \= 0; i \< n; \++i)

    {

        for (int j \= 0; j \< p; \++j)

        {

            cin \>\> B\[i\]\[j\];

        }

    }

    for (int i \= 0; i \< m; \++i)

    {

        for (int j \= 0; j \< p; \++j)

        {

            for (int k \= 0; k \< n; \++k)

            {

                C\[i\]\[j\] \+= A\[i\]\[k\] \* B\[k\]\[j\];

            }

        }

    }

    for (int i \= 0; i \< m; \++i)

    {

        for (int j \= 0; j \< p; \++j)

        {

            cout \<\< C\[i\]\[j\] \<\< " ";

        }

        cout \<\< endl;

    }

    return 0;

}

---

### **10\. Solution of Search In Matrix** 

Problem: [https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/S](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/S) 

\#include \<bits/stdc++.h\>  
using namespace std;  
int main()  
{  
    int n, m;  
    cin \>\> n \>\> m;  
    int a\[n\]\[m\];  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< m; j\++)  
        {  
            cin \>\> a\[i\]\[j\];  
        }  
    }  
    int x;  
    cin \>\> x;  
    int found \= false;  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< m; j\++)  
        {  
            if (a\[i\]\[j\] \== x)  
            {  
                found \= true;  
                break;  
            }  
        }  
    }  
    if (found)  
        cout \<\< "will not take number" \<\< endl;  
    else  
        cout \<\< "will take number" \<\< endl;  
    return 0;  
}

---

### **11\. Solution of Matrix** 

Problem: [https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/T](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/T) 

\#include \<bits/stdc++.h\>  
using namespace std;  
int main()  
{  
    int n;  
    cin \>\> n;  
    int a\[n\]\[n\];  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< n; j\++)  
        {  
            cin \>\> a\[i\]\[j\];  
        }  
    }  
    int primary \= 0, secondary \= 0;

    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< n; j\++)  
        {  
            if (i \== j)  
                primary \+= a\[i\]\[j\];  
            if (i \+ j \== n \- 1)  
                secondary \+= a\[i\]\[j\];  
        }  
    }  
    cout \<\< abs(primary \- secondary) \<\< endl;  
    return 0;  
}

---

### **12\. Solution of Mirror Array** 

Problem: [https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/W](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/W)   
Practice: Try a different approach to swap columns

\#include \<bits/stdc++.h\>  
using namespace std;  
int main()  
{  
    int n, m;  
    cin \>\> n \>\> m;  
    int a\[n\]\[m\];  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< m; j\++)  
        {  
            cin \>\> a\[i\]\[j\];  
        }  
    }

    for (int i \= 0; i \< n; i\++)  
    {  
        int x \= 0, y \= m \- 1;  
        while (x \< y)  
        {  
            swap(a\[i\]\[x\], a\[i\]\[y\]);  
            x\++;  
            y\--;  
        }  
    }  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< m; j\++)  
        {  
            cout \<\< a\[i\]\[j\] \<\< " ";  
        }  
        cout \<\< endl;  
    }  
    return 0;  
}

---

### **13\. Solution of 8 Neighbors** 

Problem: [https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/X](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/X)   
Practice: Try with 8 if-else 

\#include \<bits/stdc++.h\>  
using namespace std;  
bool isValid(int i, int j, int n, int m)  
{  
    return i \>= 0 && i \< n && j \>= 0 && j \< m;  
}  
int dx\[\] \= {0, 0, \-1, 1, \-1, 1, \-1, 1};  
int dy\[\] \= {1, \-1, 0, 0, 1, 1, \-1, \-1};

int main()  
{  
    int n, m;  
    cin \>\> n \>\> m;  
    char a\[n\]\[m\];  
    for (int i \= 0; i \< n; i\++)  
    {  
        for (int j \= 0; j \< m; j\++)  
        {  
            cin \>\> a\[i\]\[j\];  
        }  
    }

    int x, y;  
    cin \>\> x \>\> y;  
    x\--;  
    y\--;  
    int ans \= 0;  
    for (int i \= 0; i \< 8; i\++)  
    {  
        int ni \= x \+ dx\[i\];  
        int nj \= y \+ dy\[i\];  
        if (\!isValid(ni, nj, n, m))  
        {  
            ans\++;  
            continue;  
        }  
        if (a\[ni\]\[nj\] \== 'x')  
            ans\++;  
    }  
    if (ans \== 8)  
        cout \<\< "yes" \<\< endl;  
    else  
        cout \<\< "no" \<\< endl;  
    return 0;  
}

[image1]: <data:image/png;base64,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>