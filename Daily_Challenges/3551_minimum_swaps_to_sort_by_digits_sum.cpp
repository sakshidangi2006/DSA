#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int digitSum(int num) {
    int sum = 0;

    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

struct cmp{
    bool operator()(int nums1, int nums2) const {
        int num1DigitSum = digitSum(nums1);
        int nums2DigitSum = digitSum(nums2);

        if(num1DigitSum != nums2DigitSum) {
            return num1DigitSum < nums2DigitSum;
        }

        return nums1 < nums2;
    }
};

int minSwaps(vector<int>& nums) {
    vector<int>afterSorted(nums);

    sort(afterSorted.begin(), afterSorted.end(), cmp());

    unordered_map<int,int>valToIdx;

    for(int i = 0; i < nums.size(); i++) {
        valToIdx[nums[i]] = i;
    }

    int swap = 0;

    for(int i = 0; i < nums.size(); i++) {
        int expectedVal = afterSorted[i];
        int currentVal  = nums[i];

        if(expectedVal == currentVal) continue;

        int idx = valToIdx[expectedVal];
        
        nums[i] = expectedVal;
        nums[idx] = currentVal;

        valToIdx[expectedVal] = i;
        valToIdx[currentVal]  = idx;

        swap ++; 
    }
    return swap;
}

int main() {
    vector<int>nums = {37,100};
    int ans = minSwaps(nums);
    cout << ans;
    return 0;
}