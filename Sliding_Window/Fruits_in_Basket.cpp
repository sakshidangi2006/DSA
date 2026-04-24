#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>freq;
        int maxLength = -1;
        int low = 0;
        
        for(int high = 0; high < fruits.size(); high++) {
            freq[fruits[high]]++;

            while(freq.size() > 2) {
                freq[fruits[low]]--;
                
                if(freq[fruits[low]] == 0) {
                    freq.erase(fruits[low]);
                }
                low++;
            }

             maxLength = max(maxLength, (high-low+1));
        }
        return maxLength;
    }

int main() {
    vector<int> a = {1,2,1};
    int b = totalFruit(a);
    cout << b;
    return 0;
}