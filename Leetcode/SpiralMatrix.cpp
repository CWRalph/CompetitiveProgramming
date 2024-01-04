#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int offsetx = 0;
        int offsety = 0;
        int indexx = 0, indexy = 0;
        while (answer.size() != matrix.size() * matrix[0].size()) {
            while(indexx < matrix[0].size() - offsetx) {
                answer.push_back(matrix[indexy][indexx]);
                indexx++;
            }
            --indexx;
            ++indexy;
            while(indexy < matrix.size() - offsety)
            {
                answer.push_back(matrix[indexy][indexx]);
                indexy++;
            }
            --indexy;
            --indexx;
            if ((answer.size() != matrix.size() * matrix[0].size()) && (offsetx + 1 < matrix[0].size() / 2 || matrix[0].size() % 2 == 1)) {
                while (indexx >= offsetx) {
                    answer.push_back(matrix[indexy][indexx]);
                    indexx--;
                }
                ++indexx;
                --indexy;
            }
            if ((answer.size() != matrix.size() * matrix[0].size()) && (offsety + 1 < matrix.size() / 2 || matrix.size() % 2 == 1)) {
                while (indexy > offsety)
                {
                    answer.push_back(matrix[indexy][indexx]);
                    indexy--;
                }
                ++indexx;
                ++indexy;
            }
            ++offsetx;
            ++offsety;
        }
        return answer;
    }
};