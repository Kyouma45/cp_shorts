//recursive
int gcdExtended(int a, int b, int* x, int* y);
int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
    {
        cout << "Inverse doesn't exist";
        return 0;
    }
    else {
 
        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
    }
}
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
Time:O(logM)
Space:O(logM)



 
//iterative
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
Time:O(logM)
Space:O(1)


 
//for 1 to n
void modularInverse(int n, int prime)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[prime % i] *
               (prime - prime / i) % prime;   
 
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';   
}
//time:O(N)
