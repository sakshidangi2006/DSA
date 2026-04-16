/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Two sum problem return two numbers == target from an unsorted array
if array is unsorted than hashmap is the only optimal solution for indices problem but for number problem we can use two pointer approach as optimal solution 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Brute Force Solution with TC:O(n²) and SC"O(1)

vector<int> twosum(vector<int> &arr , int target) {
    int n = arr.size();
    for(int i = 0; i<n-1; i++) {
       for(int j = 1; j<n; j++ ) {
        int sum = arr[i]+arr[j];
        if(sum == target) {
            cout<<"Indices of that two numbers are: "<<arr[i]<<","<<arr[j]<<endl;    
            cout<<"The two numbers whose sum is equal to target are : "<<" ";
            return {i, j};
        }
       }
    }
    return { };
}

// Optimal Solution with TC:O(n) and SC:O(n) using HashMap when array is not sorted
// Returns indices of the two numbers that add up to target

vector<int> twoSum(vector<int> &arr, int target) {
    unordered_map<int, int> hashMap;  
    
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];  
        
        // If complement exists in hashMap, we found our pair
        if(hashMap.find(complement) != hashMap.end()) {
            return {hashMap[complement], i};
        }
        
        // Store current number with its index
        hashMap[arr[i]] = i;
    }
    
    return {};  // No pair found
}

// Optimal solution with TC:O(N) and SC:O(N) when array is sorted

vector<int> TwoSum(vector<int>&arr, int target) {
    int i = 0, j = arr.size()-1;
    while(i<j) {
        int sum = arr[i]+arr[j];
        if(sum == target) {
            cout<<"The two numbers whose sum is equal to target are : "<<arr[i]<<" "<<arr[j]<<endl;
            return {i, j};
        }
        else if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
}
int main() {
    vector<int> a = {1,6,3,8,12,9};
    vector<int> b = twoSum(a, 9);
    for(int i = 0; i< b.size(); i++) {
        cout<<b[i]<<" ";
    }
    return 0;
}

