#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

  
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto &p : freq) {
            if (p.second > 1)
                return true;
        }
    return false;
}

int main() {
    vector<int>nums = {1,2,3,1};
    bool ans = containsDuplicate(nums);
    cout << ans;
    return 0;
}