#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int area(int j, int i, vector<int>& height) 
    { 
        int x = abs(i - j) * min(height[j], height[i]);
        return x;
    }
    int maxArea(vector<int>& height) {
        int maxAreas = 0;
        int lindex = 0;
        int rindex = height.size() - 1;
        int maxLeft = lindex;
        int maxRight = rindex;

        if (height.size() == 2) return min(height[0], height[1]);
        maxAreas = area(lindex, rindex, height);
        while (lindex != rindex)
        {
            if (height[lindex] > height[rindex]) --rindex;
            else ++lindex;
            if (area(lindex, rindex, height) > maxAreas)
            {
                maxAreas = area(lindex, rindex, height);
                maxLeft = lindex;
                maxRight = rindex;
            }
        }
        return maxAreas;
    }
};