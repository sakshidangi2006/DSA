#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


vector<int> findMissingElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    vector<int> ans;

    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int num : nums) {
        freq[num]++;
        mn = min(mn, num);
        mx = max(mx, num);
    }

    for (int i = mn; i <= mx; i++) {
        if (freq[i] == 0) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7,8,6,9};
    vector<int> ans = findMissingElements(nums);

    if(ans.size()== 0){
        cout<<"[]";
    }
    for(int a : ans) {
        cout<<a <<" ";
    }
    return 0;
}