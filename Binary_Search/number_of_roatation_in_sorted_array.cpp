#include <iostream>
#include <vector>
using namespace std;

int findKRotation(vector<int> &arr) {
  
    int low = 0, high = arr.size()-1;
    while(low < high) {
        int mid = low + (high - low)/2;
        
        if(arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {5,1,2,3,4};
    int ans = findKRotation(arr);
    cout << ans;
    return 0;
}