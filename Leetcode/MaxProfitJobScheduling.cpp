#include <bits/stdc++.h>
using namespace std;
struct Item {
    int startTime, endTime, profit;

    Item(int st, int et, int pr) {
        startTime = st - 1;
        endTime = et - 1;
        profit = pr;
    }
};

class Solution {
public:
    map<int, int> ranges;

    pair<int, int> getRangeIndexFromNumber(int key) {
        if (ranges.size() == 0) return { 0,0 };
        auto it = ranges.upper_bound(key);
        if (it == ranges.begin()) return { 0,0 };
        else {
            --it;
            //if (it->first == key) return *it;
           // --it;
            return *it;
        }
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        if (startTime.size() == 0) return 0;
        vector<Item> items;


        for (int i = 0; i < startTime.size(); i++) {
            items.push_back(Item(startTime[i], endTime[i], profit[i]));
        }

        sort(items.begin(), items.end(), [](const Item& a, const Item& b)->bool {
            return a.endTime < b.endTime;
            });

        int maxVal = items.back().endTime + 1, maxIndex = 0, itemIndex = 0;

        while (maxIndex < maxVal) {
            if (itemIndex == items.size()) {
                ranges[maxIndex] = (maxIndex > 0) ? std::max(getRangeIndexFromNumber(maxIndex).second, getRangeIndexFromNumber(maxIndex - 1).second) : getRangeIndexFromNumber(maxIndex).second;
                maxIndex++;
            }
            else if (maxIndex < items[itemIndex].endTime) {
                int newValue = (maxIndex > 0) ? std::max(getRangeIndexFromNumber(maxIndex).second, getRangeIndexFromNumber(maxIndex - 1).second) : getRangeIndexFromNumber(maxIndex).second;

                //std::fill(currentMax.begin() + maxIndex, currentMax.begin() + items[itemIndex].endTime+1, newValue);
                ranges[maxIndex] = newValue;
                maxIndex = items[itemIndex].endTime;
            }
            else {
                int optionalMax = items[itemIndex].profit + getRangeIndexFromNumber(items[itemIndex].startTime).second;
                ranges[maxIndex] = std::max(getRangeIndexFromNumber(maxIndex).second, optionalMax);
                ++itemIndex;
            }
        }
        return (*ranges.rbegin()).second;
    }
};