#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimes(int range){
    vector<bool> nums(range, 0);
    nums[0] = 1;
    nums[1] = 1;
    vector<int> primes;
    while(find(nums.begin(), nums.end(), 0) != nums.end()){
        auto pos = distance(nums.begin(), find(nums.begin(), nums.end(), 0));
        primes.push_back(pos);
        for(auto i = 0; i<nums.size();i+=pos){
            nums[i] = 1;
        }
    }
    return primes;
}