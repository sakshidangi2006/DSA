#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeArrays(vector<vector<int>>& mat) {

    vector<int> ans;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

    for (int i = 0; i < mat.size(); i++) {
        if (!mat[i].empty()) {
            pq.push({mat[i][0], i, 0});
        }
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int val = cur[0];
        int row = cur[1];
        int col = cur[2];
        ans.push_back(val);
        if (col + 1 < mat[row].size()) {
            pq.push({mat[row][col + 1], row, col + 1});
        }
    }

    return ans;
}

int main() {
    vector<vector<int>>  mat = {{1, 3, 5, 7},{2, 4, 6, 8}, {0, 9, 10, 11}};
    vector<int>ans = mergeArrays(mat);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}