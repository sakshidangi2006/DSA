#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int>row(m,0);
    vector<int>col(n,0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            } 
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>>matrix = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>>ans = setZeroes(matrix);

    for(auto& a : ans) {
        for(int b : a) {
            cout << b<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
