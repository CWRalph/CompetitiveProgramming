#include <bits/stdc++.h>
using namespace std;
class Solution {
    using mP = pair<int, int>;
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), col = strs[0].size();
        int ans = 0;
        vector<mP> to_com; //qusetionable interval ranges [i, j)
        to_com.push_back({0, n});
        for(int c = 0; c < col; c++){
            vector<mP> tmp;
            for(auto &[i,j]: to_com)
                for(int start = i; start < j;){
                    int right = start +1;
                    for(; right < j; right++)
                        if(strs[start][c] < strs[right][c] ){//different section group
                            tmp.push_back({start, right});
                            break;
                        }
                        else if(strs[start][c] > strs[right][c]){ //don't remove this col
                            ans++;
                            goto next_col;
                        }

                    if(right == j)
                        tmp.push_back({start, right});
                    start = right;
                }
            to_com = move(tmp);
            next_col: ;
        }
        return ans;
    }
};