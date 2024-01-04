#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> postfix = nums, prefix = nums, total(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) 
            prefix[i] *= prefix[i - 1];
        for (int i = nums.size() - 2; i >= 0; i--) 
            postfix[i] *= postfix[i + 1];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0) total[i] *= prefix[i - 1];
            if (i < nums.size() - 1) total[i] *= postfix[i + 1];
        }
        return total;
    }
};