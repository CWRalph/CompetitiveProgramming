#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shifttonext(vector<pair<int, int>>& sorted, int current, bool upordown)
    {
        int num = sorted[current].first;
        if (upordown) while (current < sorted.size() && sorted[current].first == num) ++current;
        else while (current < sorted.size() && sorted[current].first == num) --current;
        return current;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<pair<int, int>> sorted;
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) sorted.push_back({ nums[i],i });
        sort(sorted.begin(), sorted.end(), [](pair<int, int> x, pair<int, int> j)->bool {return x.first < j.first; });
        
        int left,right,i = 0, current = sorted[0].first;
        
        vector<int> currenttotal;
        while(i < sorted.size() - 1)
        {
            if (i > 0 && current == sorted[i].first) continue;
            left = i + 1;
            right = sorted.size() - 1;
            int total = 0 - sorted[i].first;
            while (left < right && left > i && right < sorted.size())
            {
                if (sorted[left].first + sorted[right].first > total)  right = shifttonext(sorted, right, false);
                else if (sorted[left].first + sorted[right].first < total) left = shifttonext(sorted, left, true);
                else
                {
                    vector<int> x = { sorted[i].first,sorted[left].first,sorted[right].first };
                    result.push_back(x);
                    left = shifttonext(sorted, left, true);
                    right = shifttonext(sorted, right, false);
                }
            }
            i = shifttonext(sorted,i,true);
        }
        return result;
    }
};