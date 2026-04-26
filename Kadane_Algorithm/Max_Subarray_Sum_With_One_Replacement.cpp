#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumSum(vector<int>& arr) {

    int noDelete = arr[0];
    int oneDelete = INT_MIN;
    int res = arr[0];

    for(int i = 1; i<arr.size(); i++) {
        int prevnoDelete = noDelete;
        int prevOneDelete = oneDelete;
            
        noDelete = max(noDelete + arr[i], arr[i]);

        int v;
        if(prevOneDelete == INT_MIN) {
        v = arr[i];
        }
        else {
            v = prevOneDelete + arr[i];
        }
            
        oneDelete = max(v, prevnoDelete);
        res = max(res, max(oneDelete,noDelete));
    }
    return res;
}

int main() {
    vector<int> arr = {1,-2,0,3};
    int ans = maximumSum(arr);
    cout << ans;
    return 0;
}