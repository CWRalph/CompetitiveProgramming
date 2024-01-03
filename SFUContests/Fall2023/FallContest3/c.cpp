#include <iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    while(n--){cin >> nums[n];}
    for(int num : nums){cout << num << endl;}
}