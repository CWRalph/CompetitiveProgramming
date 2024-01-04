#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n + 1,1);
        if (n == 1) return 1;

        steps[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            steps[i] = steps[i - 1];
            steps[i] += steps[i - 2];
        }
        return steps[n];
    }
};