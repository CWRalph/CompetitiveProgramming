#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, short> allnums;
        int index = 0;
        vector<int> positions(numbers.size());
        vector<int> finalnums(numbers.size());

        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (allnums.find(numbers[i]) == allnums.end())
            {
            allnums.insert({ numbers[i],0});
            positions[index] = i;
            finalnums[index] = numbers[i];
            ++index;
            }
            else if (allnums[numbers[i]] == 0)
            {
            allnums[numbers[i]] = 1;
            positions[index] = i;
            finalnums[index] = numbers[i];
            ++index;
            }
        }
        /////////////////Actual math
        for (size_t i = 0; i < finalnums.size()-1; i++)
        {
            for (size_t j = i+1; j < finalnums.size(); j++)
            {
            if (finalnums[i] + finalnums[j] == target) return { positions[i]+1,positions[j]+1 };
            else if (finalnums[i] + finalnums[j] > target) break;
            }
        }
        return {0,1};
    }
};