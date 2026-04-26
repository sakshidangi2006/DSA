#include <iostream>
#include <vector>
using namespace std;

int minSubArray(vector<int>& nums) {
        int sum = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int val1 = nums[i];
            int val2 = sum + nums[i];

            sum = min(val1, val2);
            minSum = min(minSum, sum);
        }
        return minSum;
    }


int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = minSubArray(a);
    cout << ans;
    return 0;
}