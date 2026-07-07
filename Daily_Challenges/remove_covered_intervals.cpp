#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int removeCoveredIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(), cmp);
    int count = 0;
    int maxEnd = 0;

    for (auto &interval : intervals) {
        if (interval[1] > maxEnd) {
            count++;
            maxEnd = interval[1];
        }
    }
    return count;
}

int main() {
    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};
    int ans = removeCoveredIntervals(intervals);
    cout << ans;
    return 0;
}