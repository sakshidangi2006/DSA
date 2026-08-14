#include <iostream>
#include <unordered_map>
using namespace std;


int maximumLengthSubstring(string s) {
    
    unordered_map<char,int> freq;
    int maxLength = 0;
    int low = 0;

    for(int high = 0; high < s.size(); high++) {
        freq[s[high]]++;

        while(freq[s[high]] > 2) {
            freq[s[low]]--;
            low++;
        }

        maxLength = max(maxLength, high-low+1);
    
    }
    return maxLength;
}

int main() {
    string s = "bcbbbcba";
    int ans = maximumLengthSubstring(s);
    cout << ans;
    return 0;
}
