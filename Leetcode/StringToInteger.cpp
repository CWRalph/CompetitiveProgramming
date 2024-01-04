#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long double currentExp = 1, total = 0;
        char sign = '+';

        size_t spaces = s.find_first_not_of(" ");
        if (spaces != string::npos) s.erase(s.begin(), s.begin() + spaces);
        if (s.length() == 0) return 0;
        if (s[0] == '-' || s[0] == '+')
        {
            if (s[0] == '-') sign = '-';
            s.erase(s.begin(), s.begin() + 1);
        }

        size_t trailing = s.find_first_not_of("1234567890");
        if (trailing != string::npos)s.erase(s.begin() + trailing, s.end());

        //Ignore leading whitespace
        for (int index = s.length() - 1; index >= 0; index--)
        {
            total += (s[index] - '0') * currentExp;
            currentExp *= 10;
        }
        if (sign == '-' && total > 2147483647) return -2147483648;
        else if (sign != '-' && total >= 2147483647) return 2147483647;
        else if (sign == '-') return (int) total * -1;
        else return (int) total;
    }
};