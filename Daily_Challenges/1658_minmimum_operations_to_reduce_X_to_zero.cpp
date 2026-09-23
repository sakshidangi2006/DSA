#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int total = accumulate(nums.begin(),nums.end(),0);
    int target = total-x;

    if(target < 0) return -1;
    if(target == 0) return n;

    int sum = 0;
    int low = 0;
    int maxLen = -1;

    for(int high = 0; high < n; high++) {
        sum += nums[high];

        while(sum > target) {
            sum -= nums[low];
            low++;
        }

        if(sum == target) maxLen = max(maxLen, high-low+1);
    }
    return (maxLen == -1) ? -1 : n - maxLen;
}

int main() {
    vector<int> nums = {1,1,4,2,3};
    int x = 5;
    int ans = minOperations(nums,x);
    cout << ans;
    return 0;
}