#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
        int minLength = INT_MAX;
        int low = 0;
        int start = 0;
        int formed = 0; 
        int required = 0;
        int m = s.size();
   
        vector<int> need(256,0), have(256,0);

        for(char c: t) {
            need[c]++;
        }

         for (int i = 0; i < 256; i++) {
            if (need[i] > 0) required++;
        }

        for(int high = 0; high < m; high++) {
            have[s[high]] ++;


            if (need[s[high]] > 0 && have[s[high]] == need[s[high]]) {
                formed++;
            }


            while(formed == required) {

                if((high-low+1) < minLength) {
                    minLength = high-low+1;
                    start = low;
                    
                }
                have[s[low]]--;

                 if (need[s[low]] > 0 && have[s[low]] < need[s[low]]) {
                    formed--;
                }
                low++;
            }
        }
        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }

int main () {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = minWindow(s,t);
    cout << ans;
    return 0;
}