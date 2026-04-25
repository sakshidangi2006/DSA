#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int val1 = nums[i];
            int val2 = sum + nums[i];

            sum = max(val1, val2);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }


int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(a);
    cout << ans;
    return 0;
} 
