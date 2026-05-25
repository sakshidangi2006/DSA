#include <iostream>
#include <vector>
using namespace std;

int findCeil(vector<int>& arr, int x) {
    int low = 0; 
    int high = arr.size()-1;
    int ans = -1;
    
    while(low <= high) {
        int mid = (low + (high-low)/2);
        
        if(arr[mid] < x) low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,8,10,11,12,19};
    int ans = findCeil(arr,5);
    cout << ans;
    return 0;
}
