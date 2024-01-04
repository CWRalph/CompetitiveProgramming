#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> hashSet;

        for (int index : nums) {
            if (hashSet.find(index) != hashSet.end()) return index;
            hashSet.insert(index);
        }
        return -1;
    }
};