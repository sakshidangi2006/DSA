#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int preSum = 0, count = 0;
    unordered_map<int,int>mpp;
    mpp[0] = 1;

    for(int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        int required = (preSum % k + k)% k;
        count += mpp[required];
        mpp[required] ++;
    }
    return count;
}

int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int ans = subarraysDivByK(nums,k);
    cout << ans;
    return 0;
}