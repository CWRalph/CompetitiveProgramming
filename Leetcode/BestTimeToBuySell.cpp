#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentprofit, l = 0, r = 1; // Left is buying right is selling
        int maxprofit = 0;
        if (prices.size() <= 1) return 0;
        for (;r < prices.size(); r++)
        {
            currentprofit = prices[r] - prices[l];
            if (prices[l] < prices[r]) maxprofit = max(currentprofit, maxprofit);
            else l = r;
        }
        return maxprofit;
    }
};