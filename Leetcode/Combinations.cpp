#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> temp;
        for (int i = 1; i < k+1; i++)
        {
            temp.push_back(i);
        }
         while (temp[0] <= (n - k + 1))
        {
         while (temp[k - 1] <= n)
            {
             combinations.push_back(temp);
             ++temp[k - 1];
            }
            for (int i = k - 1; i > 0; i--)
            {
                if (temp[i] > n)
                {
                    ++temp[i - 1];
                    for (int j = i; j < k; j++)
                    {
                        temp[j] = temp[j - 1] + 1;
                    }   
                }
            }
        }
        return combinations;
    }
};