#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end) {
        
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int i = 0;
    int j = 0;
    int rooms = 0;
    int maxRooms = 0;
    
    while (i < start.size() && j < start.size()) {
        
        if(start[i] < end[j]) {
            rooms ++;
            maxRooms = max(maxRooms, rooms);
            i++;
        }
        else {
            rooms --;
            j++;
        }
        
    }
    
    return maxRooms;
}

int main() {
    vector<int> start = {1,10,4};
    vector<int>end = {4,15,10};
    int ans = minMeetingRooms(start, end);
    cout << ans;
    return 0;
}

