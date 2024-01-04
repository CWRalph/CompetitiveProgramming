#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = nums[0];
        for (int i = 1; i < nums.size();i++)
        {
            if (nums[i] == current)
            {
                int index = i;
                while (i < nums.size() && nums[i] == current)
                {
                    i++;
                }
                nums.erase(nums.begin() + index, nums.begin() + i - 1);
                i -= i - index;
            }
            if(i < nums.size()) current = nums[i];
        }
        return nums.size();
    }
};