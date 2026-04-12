#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> twoSumWithDuplicates(vector<int> &arr, int target) {
    int n = arr.size();
    int i = 0, j = n-1;
    vector<pair<int,int>> ans;
    while(i < j) {
        int sum = arr[i] + arr[j];
        if(sum == target) {
          ans.push_back({arr[i],arr[j]});
          int left = arr[i], right = arr[j];
          while(i < j && arr[i] == left) i++;
          while(i < j && arr[j] == right) j--;
        }
        else if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
}
int main() {
    vector<int> a = {1,1,1,2,2,3,3,4,5,6,6,6};
    vector<pair<int,int>> b = twoSumWithDuplicates(a,7);
    for(auto p : b) {
        cout<<"(" <<p.first <<"," <<p.second <<") " ;
    }
    return 0;
}
