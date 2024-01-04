#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> abits(a), bbits(b), cbits(c);
        int total = 0;
        for (int i = 0; i < 32; i++) {
            if (cbits[i]) {
                if (!(abits[i] || bbits[i])) total += 1;
            }
            else {
                if (abits[i] || bbits[i]) total += (abits[i] + bbits[i]);
            }
        }
        return total;
    }
};