#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mmap;
        int Max = 0, currentmax = 0, currentnum;

        //Add all numbers to a hashmap
        for (auto i : nums) mmap[i] = 1;
        auto it = mmap.cbegin();
        if (it != mmap.cend())
        {
            currentnum = (*it).first;
            currentmax = (*it).second;
            Max = (*it).second;
            ++it;
        }
        for (; it != mmap.cend(); it++)
        {
            if ((*it).first == currentnum + 1)
            {
                ++currentnum;
                currentmax += (*it).second;
                Max = max(Max, currentmax);
            }
            else
            {
                currentnum = (*it).first;
                currentmax = 1;
            }
        }
        return Max;
    }
};