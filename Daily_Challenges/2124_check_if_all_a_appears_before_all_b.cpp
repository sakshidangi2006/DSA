#include <iostream>
using namespace std;

bool checkString(string s) {
    int countb = 0;

    for(int i = 0; i < s.size(); i++) {
        if(countb >=1 && s[i] == 'a') return false;
        if(s[i] == 'b') countb++;
        else continue;
    }
    return true;
}

int main() {
    string s = "aaabbb";
    bool ans = checkString(s); 
    cout << ans;
    return 0;
}