#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxArea(vector<int>& height) {
    int maxWater = 0;
    int i = 0;
    int j = height.size()-1;

    while(i < j) {
        int hgt = min(height[i],height[j]);
        int width = j - i;
        int currWater = hgt * width;
        maxWater = max(maxWater, currWater);
        if(height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(height);
    cout << ans;
    return 0;
}
