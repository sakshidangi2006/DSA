#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int preSum = 0;
    int count = 0;

    unordered_map<int,int>mpp;
    mpp[0] = 1;

    for(int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum]++;
    }
    return count;
        
}

int main() {
    vector <int> nums = {1,1,1};
    int k = 2;
    int ans = subarraySum(nums,k);
    cout << ans;
    return 0;
}