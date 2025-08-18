// Solution-1: Bottom Up

class Solution {
public:
    int fib(int n) {

        //base case: 
        if(n <= 1) return n;

        //start from here : 
        int f[n+1];

        f[0] = 0;
        f[1] = 1;

        for ( int i = 2; i <= n; i++ ) {
            f[i] = f[i-1] + f[i-2];
        }

        return f[n];
    }
};


// Solution-2: Bottom up with Memory Optimization

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int oneStepPrevF = 0;
        int prevF = 1;
        int curF;

        for ( int i = 2; i <= n; i++ ) {
            curF = prevF + oneStepPrevF;
            oneStepPrevF = prevF;
            prevF = curF;
        }

        return curF;
    }
};


// Solution-3: Recursion with Top Down 

class Solution {
public:

    int calcFib(int n) {
        if ( n <= 1 ) return n;

        int res = calcFib(n-1) + calcFib(n-2);
        return res;
    }

    int fib(int n) {
        int res = calcFib(n);
        return res;
    }
};

  




// Solution-4: Dynamic Programming, Top-down Approach
// use array to store previous value return to next fibonacci => suppose -> fibo(4) => 5 and fibo(3) => 4 ; if next recursion call fibo(n) and need fibo(3) and fibo(4) value if available in dp[n] array they provide. 

class Solution {
public:

    int calcFib(int n, vector<int> &dp) {
        if ( n <= 1 ) return n;
        if (dp[n] != -1) return dp[n];

        dp[n] = calcFib(n-1, dp) + calcFib(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1, -1); // in the fibo -1 is the infinity cause -1 is not exist in the fibo series. 
        int res = calcFib(n, dp);
        return res;
    }
};
