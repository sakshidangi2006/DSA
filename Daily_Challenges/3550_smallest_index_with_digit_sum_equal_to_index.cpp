#include <iostream>
#include <vector>
using namespace std;

int smallestIndex(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        int sum = 0;
        while(n > 0) {
            int digit =  n%10;
            sum += digit;
            n /= 10;
        }

        if(sum == i) return i;
    }
    return -1;
}

int main() {
    vector<int>nums = {1,3,2};
    int ans = smallestIndex(nums);
    cout << ans;
    return 0;
}
