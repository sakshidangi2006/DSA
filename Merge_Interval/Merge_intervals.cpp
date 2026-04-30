#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    int start1 = intervals[0][0];
    int end1 = intervals[0][1];

    vector<vector<int>> ans;

    for (int i = 1; i < intervals.size(); i++) {
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if (end1 >= start2) {
            end1 = max(end1, end2);
        } else {
            ans.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
    }

    ans.push_back({start1, end1});
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);

    for (int i = 0; i < ans.size(); i++) {
        cout <<"{";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j]<<" ";
        }
        cout << "} ";
    }

    return 0;
}
