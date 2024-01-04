#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> board;
    vector<vector<string>> returnvalue;

    bool checkConflict(int r, int c) {
        int offset = 1;
        for (int row = r - 1; row >= 0; row--) {
            //Check column
            if (board[row][c] == 'Q') return true;
            //Check 135
            if (c - offset >= 0 && board[row][c - offset] == 'Q') return true;
            //Check 45
            if (c + offset < (int)board[0].size() && board[row][c + offset] == 'Q') return true;
            offset += 1;
        }
        return false;
    }

    void getStringsAtPos(int row) {
        if (row == board.size()) {
            returnvalue.push_back(board);
            return;
        }

        for (int index = 0; index < board.size(); index++) {
            if (!checkConflict(row, index)) {
                board[row] = string(board.size(), '.');
                board[row][index] = 'Q';
                getStringsAtPos(row + 1);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }
        getStringsAtPos(0);
        return returnvalue;
    }
};