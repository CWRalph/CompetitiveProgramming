#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> m;
        vector<vector<string>> anagramsSame; anagramsSame;
        vector<string> sortedStrings = strs;
        int index = 0,differentStrings = 0;

        for (auto& i : sortedStrings) sort(i.begin(),i.end());

        for (auto& i : sortedStrings)
        {
            if (m.find(i) == m.end())
            {
                vector<string> newanagram; newanagram.push_back(strs[index]);
                anagramsSame.push_back(newanagram);
                m.insert({ i,differentStrings });
                ++differentStrings;
            }
            else
            {
                anagramsSame[m[sortedStrings[index]]].push_back(strs[index]);
            }
            ++index;
        }

        return anagramsSame;
    }
};