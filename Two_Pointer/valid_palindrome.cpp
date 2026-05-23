#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size()-1;
    
    while(i < j) {

        while(i < j && !isalnum(s[i])) i++;
        while(i < j && !isalnum(s[j])) j--;

        if(tolower(s[i]) != tolower(s[j])) return false;

        i++, j--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    bool ans = isPalindrome(s);
    cout << ans;
    return 0;
}
