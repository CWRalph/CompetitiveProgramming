#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() -1;
        while(index >= 0)
        {
            if(++digits[index] == 10) digits[index] = 0;
            else return digits;
            --index;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};