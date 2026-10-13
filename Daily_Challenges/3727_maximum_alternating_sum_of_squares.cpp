#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<int>big, small;

    for(int i = 0; i < n; i++) {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    long long sum1 = 0;
    for(int i = 0; i < n/2; i++) {
        sum1 += nums[i];
    }

    long long sum2 = 0;
    for(int i = n/2; i < n; i++) {
        sum2 += nums[i];
    }

    long long result = sum2 - sum1;
    return result;
}

int main() {
    vector<int>nums =  {1,-1,2,-2,3,-3};
    long long ans = maxAlternatingSum(nums);
    cout << ans;
    return 0;
}
