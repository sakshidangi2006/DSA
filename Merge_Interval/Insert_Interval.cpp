#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    int start1 = newInterval[0];
    int end1 = newInterval[1];
    vector<vector<int>> ans;

    for(int i = 0; i < intervals.size(); i++) {
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if(end2 < start1) {
            ans.push_back({start2, end2});
        }

        else if (start2 > end1) {
            ans.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }

        else {
            start1 = min(start1, start2);
            end1 = max(end1, end2);
        }
    }
    ans.push_back({start1, end1});
    return ans;
        
}

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int>newInterval = {2,5};
    vector<vector<int>> ans = insert(intervals, newInterval);
    for(int i = 0; i < intervals.size(); i++) {
        cout <<"{";
        for(int j = 0; j < intervals.size(); j++){
            cout << ans[i][j]<<" ";
        }
        cout <<"} ";
    }
    return 0;
}