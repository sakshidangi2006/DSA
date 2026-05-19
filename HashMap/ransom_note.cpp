#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


bool canConstruct(string ransomNote, string magazine) {
        
    unordered_map<char,int>mpp1, mpp2;

    for(char ch: ransomNote) {
        mpp1[ch]++;
    }

    for(char ch: magazine) {
        mpp2[ch]++;
    }

    for(auto i : mpp1) {
        char ch = i.first;
        int needFreq = i.second;
        int haveFreq = mpp2[ch];

        if(haveFreq < needFreq) {
            return false;
        }
    }

    return true;
}

int main() {
    string ramsomNote = "aa";
    string magazine = "aab";
    bool ans = canConstruct(ramsomNote, magazine);
    cout << ans;
    return 0;
}