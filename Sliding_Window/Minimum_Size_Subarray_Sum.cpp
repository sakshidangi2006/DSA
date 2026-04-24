#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }

int main() {
    vector<int>a = {2,3,1,2,4,3};
    int target = 7;
    int b = minSubArrayLen(target,a);
    cout<<b;
    return 0;
}