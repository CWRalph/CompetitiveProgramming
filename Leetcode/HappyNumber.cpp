#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
       
        if(n<5 and n != 1)  // its a Fact
            return false;
        
        if(n==1)
            return true; // Those numbers for which this process ends in 1 are happy.
        
        int a=0;
        
        while(n>0)
            {
            a = a + pow(n%10,2);
            n = n/10;
        }
        
        return isHappy(a);  //Recursion
    }
};