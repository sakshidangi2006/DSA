#include <iostream>
using namespace std;

int scoreOfParentheses(string s) {
    int depth = 0;
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') depth++;
        else {
            depth--;
            if(s[i-1] == '(') ans += (1<<depth);
        }
    }
    return ans;
}

int main() {
    string s = "(()(()))";
    int ans = scoreOfParentheses(s);
    cout << ans;
    return 0;
}
