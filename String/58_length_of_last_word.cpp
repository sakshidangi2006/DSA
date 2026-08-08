#include <iostream>
using namespace std;


int lengthOfLastWord(string s) {
    int i = s.size()-1;

    while(i >= 0 && s[i] ==' '){
        i--;
    } 

    int length = 0;
    while(i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    return length;
}

int main() {
    string s = "Hello World";
    int ans = lengthOfLastWord(s);
    cout << ans;
    return 0;
}