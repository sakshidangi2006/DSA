#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


struct cmp{
    bool operator()(const pair<double,int>&a, const pair<double,int>&b) const{
        if(a.first != b.first) 
            return a.first < b.first;
        return a.second < b.second;
    }
};

double distance(vector<int>points) {
    double distance = sqrt((points[0] * points[0]) + (points[1] * points[1]));
    return distance;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double,int>,vector<pair<double,int>>,cmp>pq;
    
    for(int i = 0; i < points.size() ; i++) {
        double dist = distance(points[i]);
        int idx = i;
        pair<double,int> curr = {dist,idx};
        if(pq.size() < k) 
            pq.push(curr);
        
        else if(pq.top().first > curr.first) {
            pq.pop();
            pq.push(curr);
        }
    }

    vector<vector<int>>ans;
    while(!pq.empty()) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{1,3},{-2,2}};
    vector<vector<int>> ans = kClosest(points,1);
    for(int i = 0; i < ans.size(); i++ ) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}