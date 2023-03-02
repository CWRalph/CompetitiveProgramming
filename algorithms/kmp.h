#pragma once
#include <bits/stdc++.h>
using namespace std;

class KMP{
    private:
    string needle;
    vector<int> lps;
    vector<int> createLPS(){
        vector<int> lps(needle.length(), -1);
        lps[0] = 0;
        for(int i = 1; i < needle.length();i++){
            //Current match length represented by lps[i-1]
            //If the needle[i] value matches needles[lps[i-1]] then the new length is lps[i-1] + 1
            //Since we'd have to move at least that far to find another possible match
            int currentCheck = i-1;
            while(lps[currentCheck] > 0 && needle[lps[currentCheck]] != needle[i]) currentCheck--;
            if(needle[lps[currentCheck]] == needle[i]) lps[i] = lps[currentCheck] + 1;
            else lps[i] = 0;
        }
        return lps;
    }

    public:
    KMP(string needle) : needle(needle){
        this->lps = createLPS();
    }

    vector<int> findSubstringPositions(string haystack){
        vector<int> positions;
        for(int i = 0, j = 0; i - this->needle.length() < haystack.length();){
            while(needle[j] == haystack[i + j]){
                j++;
            }
            if(j == needle.length()){
                cout << "Match at position: " << i << endl;
                positions.push_back(i);
                i++;
            }else{
                i+=lps[j];
                cout << "Failed match at position: " << j << " new i is: " << i;
            }

        }
    }
};