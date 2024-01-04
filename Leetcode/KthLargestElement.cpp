#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int random(int start, int end)
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(start, end); // distribution in range [1, 6]

        return dist6(rng);
    }
    int findKthLargest(vector<int>& nums, int k) {
        //Find kth largest element
        int partition = random(0, nums.size() - 1);

        vector<int> smaller;
        vector<int> same;
        vector<int> larger;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums[partition]) smaller.push_back(nums[i]);
            else if (nums[i] > nums[partition]) larger.push_back(nums[i]);
            else same.push_back(nums[i]);
        }
        if (larger.size() >= k) return findKthLargest(larger, k);
        else if (larger.size() + same.size() < k) return findKthLargest(smaller, k - larger.size() - same.size());
        else return nums[partition];
    }
};