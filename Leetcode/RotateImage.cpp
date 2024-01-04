#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int repeat = 0; repeat < size / 2; repeat++)
        {
            swap(matrix[repeat][repeat], matrix[repeat][size - 1 - repeat]);
            swap(matrix[repeat][repeat], matrix[size - 1 - repeat][size - 1 - repeat]);
            swap(matrix[repeat][repeat], matrix[size - 1 - repeat][repeat]);
            for (int i = 1; i <= size - (2*(repeat+1)); i++)
            {
                swap(matrix[repeat][(size - 1- repeat) - i], matrix[(size - 1- repeat) - i][size - 1 - repeat]);
                swap(matrix[repeat][(size - 1- repeat) - i], matrix[size - 1 - repeat][repeat + i]);
                swap(matrix[repeat][size - 1 - repeat - i], matrix[i + repeat][repeat]);
            }
        }
    }
};