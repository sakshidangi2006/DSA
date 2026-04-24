#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

 int longestKSubstr(string &s, int k) {
        int low = 0;
        int maxLength = -1;
        unordered_map<char,int>freq;
        
        for(int high = 0; high < s.size(); high++) {
            freq[s[high]]++;
            
            while(freq.size() > k) {
                freq[s[low]]--;
                
                if(freq[s[low]] == 0) {
                    freq.erase(s[low]);
                }
                low++;
            }
            if(freq.size() == k ) {
                maxLength = max(maxLength, (high-low+1));
            }
        }
        return maxLength;
    }

int main() {
    string a = "aabacbebebe";
    int k = 3;
    int b = longestKSubstr(a,k);
    cout<<b;
    return 0;
}