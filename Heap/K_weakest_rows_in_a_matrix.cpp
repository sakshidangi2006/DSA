#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

int countOnes(const vector<int>& row) {
    int low = 0, high = row.size() - 1;
    int firstZero = row.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (row[mid] == 0) {
            firstZero = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return firstZero;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

    for (int i = 0; i < mat.size(); i++) {
        int soldiers = countOnes(mat[i]);
        pair<int,int> curr = {soldiers, i};

        if (pq.size() < k) {
            pq.push(curr);
        }
        else if (
            pq.top().first > curr.first ||
            (pq.top().first == curr.first &&
             pq.top().second > curr.second)
        ) {
            pq.pop();
            pq.push(curr);
        }
    }

    vector<int> ans;

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>>mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    vector<int>ans = kWeakestRows(mat,3);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i]<<" ";
    }
    return 0;
}