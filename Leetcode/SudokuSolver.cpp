#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<vector<char>> mainSudoku;
        vector<vector<char>> solvedSudoku;
public:
    bool checkPosition(int& row, int& col)
    {
        if (solvedSudoku[row][col] == '0') return false;
        //Check row
        //cout << "Row Check: ";
        for (int i = 0; i < solvedSudoku.size(); i++)
        {
            //cout << solvedSudoku[row][i] << ", ";
            if (i == col) continue;
            if (solvedSudoku[row][i] != '.' && solvedSudoku[row][i] == solvedSudoku[row][col]) return false;
        }

        //Check column
        //cout << "\nCol check: ";
        for (int i = 0; i < solvedSudoku.size(); i++)
        {
            //cout << solvedSudoku[i][col] << ", ";
            if (i == row) continue;
            if (solvedSudoku[i][col] != '.' && solvedSudoku[i][col] == solvedSudoku[row][col]) return false;
        }

        //Check box
        int boxrow = row / 3;
        int boxcols = col / 3;
        //cout << "\nBox check: ";
        for (int i = boxrow * 3; i < boxrow * 3 + 3; i++)
        {
            for (int j = boxcols * 3; j < boxcols * 3 + 3; j++)
            {
                //cout << solvedSudoku[i][j] << ", ";
                if (i == row && j == col) continue;
                if (solvedSudoku[i][j] !=  '.' && solvedSudoku[i][j] == solvedSudoku[row][col]) return false;
            }
        }
        return true;
    }
    bool recursiveSudokuSolve(int row, int col)
    {
        //printSudoku();
        //Stop conditions
        if (row < 0) return false;
        if (row > 8) return true;
        bool goback, numworks = false;

        //Check if this is a permanent value
        if (mainSudoku[row][col] != '.') return recursiveSudokuSolve(row + (col + 1) / 9, (col + 1) % 9);

        //Check if the current value is a period, make it one
        else
        {
            if (solvedSudoku[row][col] == '.') solvedSudoku[row][col] = '0';
            while (numworks == false)
            {
                ++solvedSudoku[row][col];
                if (checkPosition(row, col) == true)
                {
                    if (solvedSudoku[row][col] > '9')
                    {   
                        solvedSudoku[row][col] = '.';
                        return false;
                    }
                    else numworks = recursiveSudokuSolve(row + (col + 1) / 9, (col + 1) % 9);
                }
            }
            return true;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        mainSudoku = board;
        solvedSudoku = board;
        
        recursiveSudokuSolve(0,0);
        board = solvedSudoku;
    }
};