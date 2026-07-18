#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;

    for(int i = 0; i < k ; i++) {
        sum += nums[i];
    }

    double maxSum = sum;

    for(int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i-k];
        maxSum = max(sum, maxSum);
    }

    return maxSum / k;
}

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double ans = findMaxAverage(nums, k);
    cout << ans;
    return 0;
}

