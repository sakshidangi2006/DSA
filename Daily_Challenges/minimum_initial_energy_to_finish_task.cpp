#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b) {
    return (a[1] - a[0]) > (b[1] - b[0]);
}

int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), cmp);

    int ans = 0;
    int spent = 0;

    for (auto &t : tasks) {
        int actual = t[0];
        int minimum = t[1];

        ans = max(ans, spent + minimum);
        spent += actual;
    }

    return ans;
}

int main() {
    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
    int ans = minimumEffort(tasks);
    cout << ans;
    return 0;
}