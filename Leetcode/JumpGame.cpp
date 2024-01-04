#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int current = nums[0], index = 0;
        while (current >= 0) {
            current = max(current, nums[index]);
            --current;
            ++index;
            if (current >= 0 && index == nums.size() - 1) return true;
        }
        return false;
    }
};