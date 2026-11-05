#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int n = arr1.size();
    int m = arr2.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        bool valid = true;
        for(int j = 0; j < m; j++) {
            if(abs(arr1[i]-arr2[j]) <= d) {
                valid = false;
                break;
            }
                
        }
        if(valid) count++;
    }
    return count;
}


int main() {
    vector<int>arr1 = {4,5,8};
    vector<int>arr2 = {10,9,1,8};
    int d = 2;
    int ans = findTheDistanceValue(arr1, arr2, d); 
    cout << ans;
    return 0;
}