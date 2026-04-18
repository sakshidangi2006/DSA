#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>sortedSquare(vector<int>& nums) {
    vector<int>neg, pos, ans;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) neg.push_back(nums[i] * nums[i]);
        else pos.push_back(nums[i] * nums[i]);
    }
    reverse(neg.begin(), neg.end());

    int i = 0, j = 0; 
    while(i < neg.size() && j < pos.size()) {
        if(neg[i] <= pos[j]) {
            ans.push_back(neg[i]);
            i++;
        }
        else {
            ans.push_back(pos[j]);
            j++;
        }
    }
    while(i < neg.size()){
        ans.push_back(neg[i]);
        i++;
    }
    while(j < pos.size()) {
        ans.push_back(pos[j]);
        j++;
    }
    return ans;
}

int main() {
    vector<int>a = {-4,-1,0,3,10};
    vector<int>b = sortedSquare(a);
    for(int i = 0; i < b.size(); i++) {
        cout<<b[i]<<" ";
    }
    return 0;
}