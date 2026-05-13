#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;

        while (!st.empty() && st.top() <= nums[idx]) {
            st.pop();
        }

        if (i < n) {
            if (!st.empty()) {
                ans[idx] = st.top();
            }
        }

        st.push(nums[idx]);
    }
    return ans;
}

int main() {
    vector<int>nums = {1,2,3,4,3};
    vector<int>ans = nextGreaterElements(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<" ";
    }
    return 0;
}