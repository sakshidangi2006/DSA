#include <iostream>
#include <vector>
using namespace std;



void backtrack(vector<int> &candidates, int n, int idx, vector<int> & diary, int sum, vector<vector<int>>& ans ,int target) {

    if(idx == n) {
        if(sum == target) {
            ans.push_back(diary);
        }
        return;
    }

    backtrack(candidates, n, idx+1, diary, sum, ans, target);

    if(sum <= target) {
        diary.push_back(candidates[idx]);
        sum += candidates[idx];
        backtrack(candidates, n, idx, diary, sum, ans, target);
        diary.pop_back();
        sum -= candidates[idx];
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    int idx = 0;
    vector<int> diary;
    vector<vector<int>>ans;
    int sum = 0;
    backtrack(candidates, n, idx, diary, sum , ans, target);

    return ans;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);

    for(auto & a : ans) {
        for(int b : a) {
            cout << b <<" ";
        }
        cout << endl;
    }
    return 0;
}