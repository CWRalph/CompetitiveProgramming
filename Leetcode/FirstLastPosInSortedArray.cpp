#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstindex, lastindex,tempmid, low = 0, high = nums.size()-1, mid = nums.size() / 2;
        bool foundNum = false;
        //Find first appearance of target
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                foundNum = true;
                break;
            }
            if (nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        //Check if the number was found
        if (!foundNum) return { -1,-1 };

        //Mid is now the first index that the number appears
        //Find leftmost index
        low = 0;
        high = mid;
        tempmid = mid;
        while (low <= high)
        {
           tempmid = (low + high) / 2;
           if (nums[tempmid] == target) firstindex = tempmid;
            if (nums[tempmid] < target) low = tempmid + 1;
            else high = tempmid - 1;
        }

        low = mid;
        high = nums.size()-1;
        tempmid = mid;
        //Find rightmost index
        while (low <= high)
        {
            tempmid = (low + high) / 2;
            if (nums[tempmid] == target) lastindex = tempmid;
            if (nums[tempmid] <= target) low = tempmid + 1;
            else high = tempmid - 1;
        }   
        return { firstindex,lastindex };
    }
};