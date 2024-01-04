#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distance(int x, int y) { return abs(x - y); }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //Find the intercept rectangle
        //Check if the lines intercept

        //Horizontal lines of a and vertical lines of b
        int overlapX = 0, overlapY = 0;
        //Check rec 1 inside rec 2
        if (ax1 >= bx1 && ax1 <= bx2)
        {
            if (ax2 >= bx2) overlapX = distance(ax1, bx2);
            else overlapX = distance(ax1, bx2) - distance(ax2, bx2);
        }
        else if (bx1 >= ax1 && bx1 <= ax2)
        {
            if (bx2 >= ax2) overlapX = distance(bx1, ax2);
            else overlapX = distance(bx1, ax2) - distance(bx2, ax2);
        }
        if (ay2 >= by1 && ay2 <= by2)
        {
            if (ay1 <= by1) overlapY = distance(ay2, by1);
            else overlapY = distance(ay2, by1) - distance(ay1, by1);
        }
        else if (by2 >= ay1 && by2 <= ay2)
        {
            if (by1 <= ay1) overlapY = distance(by2, ay1);
            else overlapY = distance(by2, ay1) - distance(by1, ay1);
        }
        return (distance(ax1,ax2) * distance(ay1,ay2)) + (distance(bx1,bx2) * distance(by1,by2)) - (overlapX * overlapY);
    }
};