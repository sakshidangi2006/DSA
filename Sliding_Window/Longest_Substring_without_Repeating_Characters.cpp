#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int low = 0;
        int maxLength = 0;
        unordered_map<char,int>freq;

        for(int high = 0; high < s.size(); high++){
            freq[s[high]]++;

            while(freq[s[high]] >= 2) {
                freq[s[low]]--;
                
                if(freq[s[low]] == 0) freq.erase(s[low]);
                low++;
            }
            maxLength = max(maxLength,(high-low+1));
        }
        return maxLength;
    }

int main() {
    string s = "abcabcbb";
    int b = lengthOfLongestSubstring(s);
    cout << b;
    return 0;
}