#include <iostream>
#include <vector>
using namespace std;


int singleNumber(vector<int>& nums) {

    int xorCalculated = 0;
    for(int i = 0; i < nums.size(); i++) {
        xorCalculated ^= nums[i];
    }

    return xorCalculated;
}

int main() {
    vector<int> nums = {4,1,2,1,2};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}