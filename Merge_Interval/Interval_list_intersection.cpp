#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

    int m = firstList.size();
    int n = secondList.size();
    int i = 0, j = 0;
    vector<vector<int>>ans;

    while(i < m && j < n) {
        int start1 = firstList[i][0];
        int end1 = firstList[i][1];
        int start2 = secondList[j][0];
        int end2 = secondList[j][1];

        if(start1 <= start2) {
            if(end1 >= start2) {
                int s = max(start1, start2);
                int e = min (end1, end2);
                ans.push_back({s,e});
            }
        }

        else {
            if(end2 >= start1) {
                int s = max(start1, start2);
                int e = min(end1, end2);
                ans.push_back({s,e});
            }
        }
        if(end1 <= end2) i++;
        else j++;
    }
    return ans;
}

int main() {
    vector<vector<int>>firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>>secondList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> ans = intervalIntersection(firstList, secondList);
    for(int i = 0; i < ans.size(); i++) {
        cout <<"{";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j]<<" ";
        }
        cout <<"} ";
    }
    return 0;
}