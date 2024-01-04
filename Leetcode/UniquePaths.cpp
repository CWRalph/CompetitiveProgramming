#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long double Factorial(int n)
    {
        long double ans = 1;
        for (int i = n; i > 0; i--)
            ans *= i;
        return ans;
    }
    int uniquePaths(int m, int n) {
        //m+n fac / mfac * nfac
        int numerator = (m - 1) + (n - 1);
        long double a = Factorial(numerator);
        long double b = Factorial(m - 1) * Factorial(n - 1);
        return (int)(a/b + 0.5);
    }
};