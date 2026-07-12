#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) { 

    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> rank;
    int r = 1;

    for (int x : temp) {
        if (rank.find(x) == rank.end()) {
            rank[x] = r++;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rank[arr[i]];
    }

    return arr;
}

int main() {
    vector<int>arr = {40,10,20,30};
    vector<int>ans = arrayRankTransform(arr);

    for(int a : ans) {
        cout << a<< " ";
    }
    return 0;
}