#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string reverseParentheses(string s) {
    stack<string> st;
    string curr = "";

    for (char c : s) {
        if (c == '(') {
            st.push(curr);
            curr = "";
        }
        else if (c == ')') {
            reverse(curr.begin(), curr.end());

            curr = st.top() + curr;
            st.pop();
        }
        else {
            curr += c;
        }
    }

    return curr;
}

int main() {
    string s = "(abcd)";
    string ans = reverseParentheses(s);
    cout << ans;
    return 0;
}
