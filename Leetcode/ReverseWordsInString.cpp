#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        size_t index;
        s += ' ';
        vector<string> strings;
        string returned = "";
        while (s.find_first_not_of(' ') != string::npos)
        {
            index = s.find_first_not_of(' ');
            if (index != string::npos) s.erase(s.begin(), s.begin() + index);
            index = s.find_first_of(' ');
            if (index != string::npos) { strings.push_back(s.substr(0, index)); s.erase(s.begin(), s.begin() + index); }
        }
        reverse(strings.begin(), strings.end());
        for (auto& i : strings) returned += i + " ";
        returned.pop_back();
        return returned;
    }
};