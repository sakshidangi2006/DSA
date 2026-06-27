#include <iostream>
#include <vector> 
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {

    vector<int> left, mid, right;

    for (int x : nums) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            mid.push_back(x);
        else
            right.push_back(x);
    }

    vector<int> ans;

    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), mid.begin(), mid.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

int main() {
    vector<int> nums = {9,12,5,10,14,3,10};
    vector<int> ans = pivotArray(nums,10);
    cout<<"{";
    for(int x: ans) {
        cout<< x <<" ";
    }
    cout<<"}";
    return 0;
}