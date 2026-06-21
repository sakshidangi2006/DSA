#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct cmp {
    bool operator()(const pair<int,int>&a, const pair<int,int>&b) const {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    
    for(int a : arr) {
        int dist = abs(x-a);
        pair<int,int> curr = {dist,a};
        if(pq.size() < k) {
            pq.push(curr);
        }
        else if(pq.top().first > curr.first || (pq.top().first == curr.first  && pq.top().second > curr.second)) {
            pq.pop();
            pq.push(curr);
        }
    }

    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int>arr = {1,2,3,4,5};
    vector<int>ans = findClosestElements(arr,4,3);
    for(int i = 0; i < ans.size(); i++) {
        cout<< arr[i]<<" ";
    }
    return 0;
}