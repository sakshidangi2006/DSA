#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {

    int xor1 = 0;
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {
        xor1 ^= nums[i];
    }

    int setBitPosition = -1;
    for(int i = 0; i < 32; i++) {
        if(xor1 & (1 << i)) {
            setBitPosition = i;
            break;
        }
    }

    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] & (1 << setBitPosition)){
            num1 ^= nums[i];
        }
        else {
            num2 ^= nums[i];
        }
    }

    ans.push_back(num1);
    ans.push_back(num2);
    return ans;
}

int main() {
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = singleNumber(nums);
    cout <<"[" << ans[0] <<"," << ans[1] <<"]";
    return 0;
}