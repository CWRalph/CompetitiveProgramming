#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, current = nums[i++], count = 1;
        
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for (; i < nums.size(); i++)
        {
            if (current == nums[i])++count;
            else
            {
                pq.push({ count,current });
                count = 1;
                current = nums[i];
            }
        }
        pq.push({ count,current });

        for (i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};