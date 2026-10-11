#include <iostream>
#include <vector>
using namespace std;

int sumOfSquares(vector<int>& nums) {

    long long sum = 0;
    int n = nums.size();

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            sum += (nums[i-1] * nums[i-1]);
        }
    }

    return int(sum);
}

int main() {
    vector<int>nums = {1,2,3,4};
    int ans = sumOfSquares(nums);
    cout << ans;
    return 0;
}