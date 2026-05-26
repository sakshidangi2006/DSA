#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1; 
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1; 
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) {
    int first = firstOcc(arr, target);
    
    if(first == -1) return 0;
    
    int last = lastOcc(arr, target);
    
    return last - first + 1;
}

int main() {
    vector<int> arr = {1,1,2,2,2,2,3};
    int ans = countFreq(arr,2);
    cout << ans;
    return 0;
}