#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k) {
        int low = 0;
        int maxLength = 0;
        int maxFreq = 0;
        unordered_map<char,int>freq;

        for(int high = 0; high < s.size(); high++) {
            freq[s[high]]++;
            maxFreq = max(maxFreq, freq[s[high]]);

            while((high-low+1) - maxFreq > k) {
                freq[s[low]]--;

                if(freq[s[low]] == 0) freq.erase(s[low]);
                low++;
            }
            maxLength =  max(maxLength, high-low+1);
        }
        return maxLength;
    }

int main() {
    string s = "AABABBA";
    int k = 1;
    int b = characterReplacement(s,k);
    cout << b;
    return 0;
}