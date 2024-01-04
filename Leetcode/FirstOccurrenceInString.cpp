#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needlesize = needle.size();
        if(needlesize > haystack.size())return -1;
        for(int i = 0; i <= haystack.size() - needlesize; i++)
        {
            if(haystack.substr(i,needlesize) == needle) return i;
        }
        return -1;
    }
};