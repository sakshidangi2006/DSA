#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int total = nums[0];

    int maxSum = nums[0], curMax = nums[0];
    int minSum = nums[0], curMin = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        int x = nums[i];

        curMax = max(x, curMax + x);
        maxSum = max(maxSum, curMax);

        curMin = min(x, curMin + x);
        minSum = min(minSum, curMin);

        total += x;
    }

    if (maxSum < 0) return maxSum;

    return max(maxSum, total - minSum);
}

int main() {
    vector<int> arr = {5,-3,5};
    int ans = maxSubarraySumCircular(arr);
    cout<<ans;
    return 0;
}
