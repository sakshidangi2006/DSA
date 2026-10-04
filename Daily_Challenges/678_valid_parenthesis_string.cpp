#include <iostream>
#include <algorithm>
using namespace std;


bool checkValidString(string s) {
    int low = 0;
    int high = 0;

    for(char ch : s) {
        if(ch == '(') {
            low++;
            high++;
        }
        else if(ch == ')') {
            low--;
            high--;
        }

        else {
            low--;
            high++;
        }

        if(high < 0) return false;
        low = max(0,low);
    }

    return (low == 0);
}

int main() {
    string s = "(*)";
    bool ans = checkValidString(s);
    cout << ans ;
    return 0;
}