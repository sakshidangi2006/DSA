#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


struct cmp {

    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {

        if(a.first != b.first)
            return a.first > b.first; 

        return a.second > b.second;
    }

};


vector<int> topKFrequent(vector<int>& nums, int k) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    unordered_map<int,int> mpp;

    for(int num : nums) {
        mpp[num]++;
    }

    for(auto &m : mpp) {
        int element = m.first;
        int freq = m.second;
        pair<int,int> curr = {freq, element};

        if(pq.size() < k) {
            pq.push(curr);
        }

        else if(freq > pq.top().first) {
        pq.pop();
         pq.push(curr);
        }

    }

    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    vector<int>ans = topKFrequent(nums,2);
    cout <<"{";
    for(int i = 0; i < ans.size(); i++) {
        cout<< ans[i]<<" ";
    }
    cout <<"}";
    return 0;
}