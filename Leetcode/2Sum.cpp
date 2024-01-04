#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> sorted;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sorted.push_back({ nums[i],i });
        }
        sort(sorted.begin(), sorted.end(), [](pair<int,int> x, pair<int, int> j)->bool {return x.first < j.first; });
        int left = 0, right = nums.size() - 1;
        while (sorted[left].first + sorted[right].first != target)
        {
            if (sorted[left].first + sorted[right].first < target)
                ++left;
            else if (sorted[left].first + sorted[right].first > target)
                --right;
        }
        vector<int> result = { sorted[left].second,sorted[right].second };
        return result;
    }
};