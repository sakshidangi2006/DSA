#include <iostream>
using namespace std;

string removeOuterParentheses(string s) {
    int depth = 0;
    string ans;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            if(depth > 0) ans.push_back(s[i]);
            depth++;
        }
        else {
            depth--;
            if(depth > 0) ans.push_back(s[i]);
        }
    }
    return ans;
}

int main() {
    string s = "(()())(())(()(()))";
    string ans = removeOuterParentheses(s);
    cout << ans;
    return 0;
}
