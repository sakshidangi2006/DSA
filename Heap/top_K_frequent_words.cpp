#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

    struct cmp {
        bool operator()(const pair<string,int>& a,
                        const pair<string,int>& b) const {

            if (a.second == b.second)
                return a.first < b.first;

            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;

        for (auto &s : words)
            mpp[s]++;

        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            cmp
        > pq;

        for (auto &m : mpp) {
            pq.push({m.first, m.second});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

int main() {

    vector<string>words = {"i","love","leetcode","i","love","coding"};
    vector<string>ans = topKFrequent(words,2);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i]<<" ";
    }
    return 0;

}