#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m-1;
    int left = 0, right = n-1;

    while(top <= bottom && left <= right) {
        for(int j = left; j <= right; j++) {
            ans.push_back(matrix[top][j]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int j = right; j >= left ; j--) {
            ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(int a : ans) {
        cout << a <<" ";
    }
    return 0;
}
