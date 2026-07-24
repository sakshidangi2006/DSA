#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int bit = 0; bit < 32; bit++){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & (1 << bit)) != 0){
                count++;
            }
        }

        if(count % 3 != 0){
            result |= (1 << bit);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2,2,3,2};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}