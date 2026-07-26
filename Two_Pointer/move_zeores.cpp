#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0;

    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

void print(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i]<<" ";
    }
}


int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    print(nums);
    return 0;
}